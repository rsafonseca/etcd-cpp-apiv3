#include <etcd/Utils.h>
#include <etcd/Watcher.hpp>
#include <etcd/Client.hpp>


etcd::Watcher::Watcher(
    const std::string & address,
    const std::string & key,
    std::function<void(Response)> callback,
    const pplx::task_options & task_options)
  : Watcher::Watcher(etcd::utils::createChannel(address), key, true, 0, callback, task_options)
{}

etcd::Watcher::Watcher(
    const std::shared_ptr<grpc::Channel> & channel,
    const std::string & key,
    std::function<void(Response)> callback,
    const pplx::task_options & task_options)
  : Watcher::Watcher(channel, key, true, 0, callback, task_options)
{}

etcd::Watcher::Watcher(
    const std::string & address,
    const std::string & key,
    const bool recursive,
    const int fromIndex,
    std::function<void(Response)> callback,
    const pplx::task_options & task_options)
  : Watcher::Watcher(etcd::utils::createChannel(address), key, recursive, fromIndex, callback, task_options)
{}

etcd::Watcher::Watcher(
    const std::shared_ptr<grpc::Channel> & channel,
    const std::string & key,
    const bool recursive,
    const int fromIndex,
    std::function<void(Response)> callback,
    const pplx::task_options & task_options)
  : channel(channel)
  , watchServiceStub(Watch::NewStub(channel))
  , task_options(task_options)
  , callback(callback)
  , isCancelled(false)
{
  watch_action_parameters.key = key;
  watch_action_parameters.withPrefix = recursive;
  watch_action_parameters.revision = fromIndex;
  watch_action_parameters.watch_stub = watchServiceStub.get();
  doWatch();
}

void etcd::Watcher::Cancel()
{
  if (isCancelled)
  {
    return;
  }
  if (call)
  {
    call->cancelWatch();
    currentTask.wait();
    call.reset();
  }
  isCancelled = true;
}

bool etcd::Watcher::Cancelled() const
{
  return isCancelled;
}

etcd::Watcher::~Watcher()
{
  try
  {
    Cancel();
  } catch (...)
  {}
}

void etcd::Watcher::doWatch()
{
  try
  {
    if (call) {
      call->cancelWatch();
    }
    currentTask.wait();
  } catch (...)
  {}
  call.reset(new etcdv3::AsyncWatchAction(watch_action_parameters));
  currentTask = pplx::task<void>([this]()
  {
    call->waitForResponse(callback);
  }, task_options);
}
