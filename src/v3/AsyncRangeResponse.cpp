#include <etcd/v3/AsyncRangeResponse.hpp>
#include <etcd/v3/action_constants.hpp>


etcdv3::AsyncRangeResponse::AsyncRangeResponse(
    etcdserverpb::RangeResponse const & resp,
    bool const prefix)
{
  revision = resp.header().revision();
  action = etcdv3::GET_ACTION;

  if (resp.kvs_size() == 0)
  {
    error_code = 100;
    error_message = "Key not found";
  }
  else
  {
    for (int index = 0; index < resp.kvs_size(); index++)
    {
      etcdv3::KeyValue kv;
      kv.kvs.CopyFrom(resp.kvs(index));
      values.push_back(kv);
    }
    if (!prefix)
    {
      value = values[0];
      values.clear();
    }
  }
}
