#ifndef __ETCD_WATCHER_HPP__
#define __ETCD_WATCHER_HPP__

#include <string>
#include <etcd/Response.hpp>
#include <etcd/v3/AsyncWatchAction.hpp>

#include <grpc++/grpc++.h>

using etcdserverpb::Watch;
using grpc::Channel;

namespace etcd
{

class Watcher
{
public:
	Watcher(
		const std::string & address,
		const std::string & key,
		std::function<void(Response)> callback,
		const pplx::task_options & task_options = pplx::task_options());
	Watcher(
		const std::shared_ptr<grpc::Channel> & channel,
		const std::string & key,
		std::function<void(Response)> callback,
		const pplx::task_options & task_options = pplx::task_options());
	Watcher(
		const std::string & address,
		const std::string & key,
		const bool recursive,
		const int fromIndex,
		std::function<void(Response)> callback,
		const pplx::task_options & task_options = pplx::task_options());
	Watcher(
		const std::shared_ptr<Channel> & channel,
		const std::string & key,
		const bool recursive,
		const int fromIndex,
		std::function<void(Response)> callback,
		const pplx::task_options & task_options = pplx::task_options());
	void Cancel();
	bool Cancelled() const;
	~Watcher();

protected:
	void doWatch();

	const std::shared_ptr<Channel> channel;
	const std::unique_ptr<Watch::Stub> watchServiceStub;
	const pplx::task_options task_options;
	etcdv3::ActionParameters watch_action_parameters;
	std::function<void(Response)> callback;
	bool isCancelled;
	pplx::task<void> currentTask;
	std::unique_ptr<etcdv3::AsyncWatchAction> call;
};
} // namespace etcd

#endif
