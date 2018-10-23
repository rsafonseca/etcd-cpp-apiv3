#include <etcd/v3/AsyncLeaseGrantResponse.hpp>


etcdv3::AsyncLeaseGrantResponse::AsyncLeaseGrantResponse(etcdserverpb::LeaseGrantResponse const & resp)
{
  revision = resp.header().revision();
  error_message = resp.error();
  value.kvs.set_lease(resp.id());
  value.set_ttl(resp.ttl());
}
