#include <etcd/Response.hpp>

#include <iostream>


etcd::Response::Response(int const error_code, char const * const error_message)
  : error_code(error_code)
  , error_message(error_message)
{}

etcd::Response::Response(int const error_code, std::string error_message)
  : error_code(error_code)
  , error_message(std::move(error_message))
{}

etcd::Response::Response(etcdv3::V3Response && reply)
  : error_code(reply.error_code)
  , error_message(std::move(reply.error_message))
  , revision(reply.revision)
  , action(std::move(reply.action))
  , prev_value(std::move(reply.prev_value))
{
  if(reply.has_values())
  {
    for(size_t index = 0; index < reply.values.size(); index++)
    {
      keys.push_back(reply.values[index].kvs.key());
      values.push_back(Value(std::move(reply.values[index])));
    }
  }
  else
  {
    value = Value(std::move(reply.value));
  }
}

bool etcd::Response::is_ok() const
{
  return error_code == 0;
}
