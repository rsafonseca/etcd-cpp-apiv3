#include <etcd/v3/AsyncWatchAction.hpp>
#include <etcd/v3/action_constants.hpp>


using etcdserverpb::RangeRequest;
using etcdserverpb::RangeResponse;
using etcdserverpb::WatchCreateRequest;


etcdv3::AsyncWatchAction::AsyncWatchAction(etcdv3::ActionParameters param)
  : etcdv3::Action(std::move(param))
  , isCancelled(false)
  , stream(parameters.watch_stub->AsyncWatch(&context, &cq_, (void*)"create"))
{
  WatchRequest watch_req;
  WatchCreateRequest watch_create_req;
  watch_create_req.set_key(parameters.key);
  watch_create_req.set_prev_kv(true);
  watch_create_req.set_start_revision(parameters.revision);
  //watch_create_req.set_progress_notify(true);

  if(parameters.withPrefix)
  {
    std::string range_end(parameters.key);
    int ascii = (int)range_end[range_end.length()-1];
    range_end.back() = ascii+1;
    watch_create_req.set_range_end(range_end);
  }

  watch_req.mutable_create_request()->CopyFrom(watch_create_req);

  void* got_tag;
  bool ok = false;
  if (cq_.Next(&got_tag, &ok) && ok && got_tag == (void*)"create")
  {
    stream->Write(watch_req, (void*)"write");
    ok = false;
    if (cq_.Next(&got_tag, &ok) && ok && got_tag == (void*)"write")
    {
      stream->Read(&response, (void*)this);
    }
    else
    {
      cq_.Shutdown();
    }
  }
  else
  {
    cq_.Shutdown();
  }
}

void etcdv3::AsyncWatchAction::waitForResponse() 
{
  void* got_tag;
  bool ok = false;
  
  while(cq_.Next(&got_tag, &ok))
  {
    // if not ok or unknown tag received (or write done), break watch
    if (!ok || got_tag != (void*)this)
    {
      cq_.Shutdown();
      break;
    }

    // ok and got tag is for read
    if(response.events_size())
    {
      stream->WritesDone((void*)"writes done");
    }
    else
    {
      stream->Read(&response, (void*)this);
    }
  }
}

void etcdv3::AsyncWatchAction::cancelWatch()
{
  if (!isCancelled)
  {
    //check if cq_ is ok
    isCancelled = true;
    void* got_tag;
    bool ok = false;
    gpr_timespec deadline;
    deadline.clock_type = GPR_TIMESPAN;
    deadline.tv_sec = 0;
    deadline.tv_nsec = 10000000;
    if (cq_.AsyncNext(&got_tag, &ok, deadline) != CompletionQueue::SHUTDOWN)
    {
      stream->WritesDone((void*)"writes done");
    }
  }
}

void etcdv3::AsyncWatchAction::waitForResponse(std::function<void(etcd::Response)> const & callback)
{
  void * got_tag;
  bool ok = false;

  while (cq_.Next(&got_tag, &ok))
  {
    // if not ok or unknown tag received (or write done), break watch
    if (!ok || got_tag != (void*)this)
    {
      cq_.Shutdown();
      break;
    }

    // if ok and read done, call callback and just read again
    // call callback only if reply has events
    if (response.events_size())
    {
      // callback is responsible for errors handling
      callback(ParseResponse());
    }
    stream->Read(&response, (void *)this);
  }
}

etcdv3::AsyncWatchResponse etcdv3::AsyncWatchAction::ParseResponse()
{
  if (!status.ok())
  {
    return AsyncWatchResponse(status.error_code(), status.error_message());
  }

  return AsyncWatchResponse(response);
}
