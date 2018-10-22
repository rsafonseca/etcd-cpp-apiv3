#include <memory>
#include <etcd/Utils.h>
#include <etcd/Client.hpp>
#include <etcd/v3/AsyncTxnResponse.hpp>
#include <etcd/v3/AsyncRangeResponse.hpp>
#include <etcd/v3/AsyncWatchResponse.hpp>
#include <etcd/v3/AsyncDeleteRangeResponse.hpp>
#include <etcd/v3/Transaction.hpp>
#include <iostream>

#include <etcd/v3/AsyncSetAction.hpp>
#include <etcd/v3/AsyncCompareAndSwapAction.hpp>
#include <etcd/v3/AsyncCompareAndDeleteAction.hpp>
#include <etcd/v3/AsyncUpdateAction.hpp>
#include <etcd/v3/AsyncGetAction.hpp>
#include <etcd/v3/AsyncDeleteAction.hpp>
#include <etcd/v3/AsyncWatchAction.hpp>
#include <etcd/v3/AsyncLeaseGrantAction.hpp>


using grpc::Channel;


etcd::Client::Client(std::string const & address, const pplx::task_options & task_options)
	: channel_(etcd::utils::createChannel(address))
	, stub_(KV::NewStub(channel_))
	, watchServiceStub(Watch::NewStub(channel_))
	, leaseServiceStub(Lease::NewStub(channel_))
	, task_options(task_options)
{}

std::shared_ptr<Channel> etcd::Client::channel() const
{
	return channel_;
}

pplx::task<etcd::Response> etcd::Client::get(std::string const & key)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.withPrefix = false;
  params.kv_stub = stub_.get();
  return Response::create(std::make_shared<etcdv3::AsyncGetAction>(std::move(params)), task_options);
}

pplx::task<etcd::Response> etcd::Client::set(std::string const & key, std::string const & value, int ttl)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.kv_stub = stub_.get();

  if(ttl > 0)
  {
    auto res = leasegrant(ttl).get();
    if(!res.is_ok()) 
    {
      return pplx::task<etcd::Response>([res]()
      {
        return etcd::Response(res.error_code(), res.error_message().c_str());    
      }, task_options);
    }
    else
    {
      params.lease_id = res.value().lease();
    }
  }
  return Response::create(std::make_shared<etcdv3::AsyncSetAction>(std::move(params)), task_options);
}

pplx::task<etcd::Response> etcd::Client::set(std::string const & key, std::string const & value, int64_t leaseid)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.lease_id = leaseid;
  params.kv_stub = stub_.get();
  return Response::create(std::make_shared<etcdv3::AsyncSetAction>(std::move(params)), task_options);
}


pplx::task<etcd::Response> etcd::Client::add(std::string const & key, std::string const & value, int ttl)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.kv_stub = stub_.get();

  if(ttl > 0)
  {
    auto res = leasegrant(ttl).get();
    if(!res.is_ok()) 
    {
      return pplx::task<etcd::Response>([res]()
      {
        return etcd::Response(res.error_code(), res.error_message().c_str());    
      }, task_options);
    }
    else
    {
      params.lease_id = res.value().lease();
    }
  }
  return Response::create(std::make_shared<etcdv3::AsyncSetAction>(std::move(params), true), task_options);
}

pplx::task<etcd::Response> etcd::Client::add(std::string const & key, std::string const & value, int64_t leaseid)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.lease_id = leaseid;
  params.kv_stub = stub_.get();
  return Response::create(std::make_shared<etcdv3::AsyncSetAction>(std::move(params), true), task_options);
}


pplx::task<etcd::Response> etcd::Client::modify(std::string const & key, std::string const & value, int ttl)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.kv_stub = stub_.get();

  if(ttl > 0)
  {
    auto res = leasegrant(ttl).get();
    if(!res.is_ok()) 
    {
      return pplx::task<etcd::Response>([res]()
      {
        return etcd::Response(res.error_code(), res.error_message().c_str());    
      }, task_options);
    }
    else
    {
      params.lease_id = res.value().lease();
    }
  }
  return Response::create(std::make_shared<etcdv3::AsyncUpdateAction>(std::move(params)), task_options);
}

pplx::task<etcd::Response> etcd::Client::modify(std::string const & key, std::string const & value, int64_t leaseid)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.lease_id = leaseid;
  params.kv_stub = stub_.get();
  return Response::create(std::make_shared<etcdv3::AsyncUpdateAction>(std::move(params)), task_options);
}


pplx::task<etcd::Response> etcd::Client::modify_if(std::string const & key, std::string const & value, std::string const & old_value, int ttl)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.old_value.assign(old_value);
  params.kv_stub = stub_.get();

  if(ttl > 0)
  {
    auto res = leasegrant(ttl).get();
    if(!res.is_ok()) 
    {
      return pplx::task<etcd::Response>([res]()
      {
        return etcd::Response(res.error_code(), res.error_message().c_str());    
      }, task_options);
    }
    else
    {
      params.lease_id = res.value().lease();
    }
  }
  return Response::create(std::make_shared<etcdv3::AsyncCompareAndSwapAction>(std::move(params), etcdv3::Atomicity_Type::PREV_VALUE), task_options);
}

pplx::task<etcd::Response> etcd::Client::modify_if(std::string const & key, std::string const & value, std::string const & old_value, int64_t leaseid)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.old_value.assign(old_value);
  params.lease_id = leaseid;
  params.kv_stub = stub_.get();
  return Response::create(std::make_shared<etcdv3::AsyncCompareAndSwapAction>(std::move(params), etcdv3::Atomicity_Type::PREV_VALUE), task_options);
}



pplx::task<etcd::Response> etcd::Client::modify_if(std::string const & key, std::string const & value, int old_index, int ttl)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.old_revision = old_index;
  params.kv_stub = stub_.get();
  if(ttl > 0)
  {
    auto res = leasegrant(ttl).get();
    if(!res.is_ok()) 
    {
      return pplx::task<etcd::Response>([res]()
      {
        return etcd::Response(res.error_code(), res.error_message().c_str());    
      }, task_options);
    }
    else
    {
      params.lease_id = res.value().lease();
    }
  }
  return Response::create(std::make_shared<etcdv3::AsyncCompareAndSwapAction>(std::move(params), etcdv3::Atomicity_Type::PREV_INDEX), task_options);
}

pplx::task<etcd::Response> etcd::Client::modify_if(std::string const & key, std::string const & value, int old_index, int64_t leaseid)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.lease_id = leaseid;
  params.old_revision = old_index;
  params.kv_stub = stub_.get();
  return Response::create(std::make_shared<etcdv3::AsyncCompareAndSwapAction>(std::move(params), etcdv3::Atomicity_Type::PREV_INDEX), task_options);
}


pplx::task<etcd::Response> etcd::Client::rm(std::string const & key)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.withPrefix = false;
  params.kv_stub = stub_.get();
  return Response::create(std::make_shared<etcdv3::AsyncDeleteAction>(std::move(params)), task_options);
}


pplx::task<etcd::Response> etcd::Client::rm_if(std::string const & key, std::string const & old_value)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.old_value.assign(old_value);
  params.kv_stub = stub_.get();
  return Response::create(std::make_shared<etcdv3::AsyncCompareAndDeleteAction>(std::move(params), etcdv3::Atomicity_Type::PREV_VALUE), task_options);
}

pplx::task<etcd::Response> etcd::Client::rm_if(std::string const & key, int old_index)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.old_revision = old_index;
  params.kv_stub = stub_.get();
  return Response::create(std::make_shared<etcdv3::AsyncCompareAndDeleteAction>(std::move(params), etcdv3::Atomicity_Type::PREV_INDEX), task_options);

}

pplx::task<etcd::Response> etcd::Client::rmdir(std::string const & key, bool recursive)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.withPrefix = recursive;
  params.kv_stub = stub_.get();
  return Response::create(std::make_shared<etcdv3::AsyncDeleteAction>(std::move(params)), task_options);
}

pplx::task<etcd::Response> etcd::Client::ls(std::string const & key)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.withPrefix = true;
  params.kv_stub = stub_.get();
  return Response::create(std::make_shared<etcdv3::AsyncGetAction>(std::move(params)), task_options);
}

pplx::task<etcd::Response> etcd::Client::watch(std::string const & key, bool recursive)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.withPrefix = recursive;
  params.watch_stub = watchServiceStub.get();
  return Response::create(std::make_shared<etcdv3::AsyncWatchAction>(std::move(params)), task_options);
}

pplx::task<etcd::Response> etcd::Client::watch(std::string const & key, int fromRevision, bool recursive)
{
  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.withPrefix = recursive;
  params.revision = fromRevision;
  params.watch_stub = watchServiceStub.get();
  return Response::create(std::make_shared<etcdv3::AsyncWatchAction>(std::move(params)), task_options);
}

pplx::task<etcd::Response> etcd::Client::leasegrant(int ttl)
{
  etcdv3::ActionParameters params;
  params.ttl = ttl;
  params.lease_stub = leaseServiceStub.get();
  return Response::create(std::make_shared<etcdv3::AsyncLeaseGrantAction>(std::move(params)), task_options);
}



