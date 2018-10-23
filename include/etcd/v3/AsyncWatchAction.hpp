#ifndef __ASYNC_WATCHACTION_HPP__
#define __ASYNC_WATCHACTION_HPP__

#include <grpc++/grpc++.h>
#include <etcd/v3/proto/rpc.grpc.pb.h>
#include <etcd/v3/Action.hpp>
#include <etcd/v3/AsyncWatchResponse.hpp>
#include <etcd/Response.hpp>


using grpc::ClientAsyncReaderWriter;
using etcdserverpb::WatchRequest;
using etcdserverpb::WatchResponse;


namespace etcdv3
{

  using watch_callback = std::function<void(etcd::Response &&)>;

  class AsyncWatchAction : public etcdv3::Action
  {
    public:
      AsyncWatchAction(etcdv3::ActionParameters param);
      AsyncWatchResponse ParseResponse();
      void waitForResponse();
      void waitForResponse(watch_callback const & callback);
      void cancelWatch();
    private:
      WatchResponse response;
      bool isCancelled;
      std::unique_ptr<ClientAsyncReaderWriter<WatchRequest, WatchResponse>> stream;
  };

}

#endif
