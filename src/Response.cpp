#include <etcd/Response.hpp>

#include <iostream>


etcd::Response::Response(int const error_code, char const * const error_message)
  : _error_code(error_code),
    _error_message(error_message)
{}

etcd::Response::Response(etcdv3::V3Response && reply)
  : _error_code(reply.error_code)
  , _error_message(std::move(reply.error_message))
  , _revision(reply.revision)
  , _action(std::move(reply.action))
  , _prev_value(std::move(reply.prev_value))
{
  if(reply.has_values())
  {
    auto val = std::move(reply.values);
    for(size_t index = 0; index < val.size(); index++)
    {
      _keys.push_back(val[index].kvs.key());
      _values.push_back(Value(std::move(val[index])));
    }
  }
  else
  {
    _value = Value(std::move(reply.value));
  }
}

int etcd::Response::error_code() const
{
  return _error_code;
}

std::string const & etcd::Response::error_message() const
{
  return _error_message;
}

int64_t etcd::Response::revision() const
{
  return _revision;
}

std::string const & etcd::Response::action() const
{
  return _action;
}

bool etcd::Response::is_ok() const
{
  return error_code() == 0;
}

etcd::Value const & etcd::Response::value() const
{
  return _value;
}

etcd::Value const & etcd::Response::prev_value() const
{
  return _prev_value;
}

etcd::Values const & etcd::Response::values() const
{
  return _values;
}

etcd::Value const & etcd::Response::value(size_t const index) const
{
  return _values[index];
}

etcd::Keys const & etcd::Response::keys() const
{
  return _keys;
}

std::string const & etcd::Response::key(size_t const index) const
{
  return _keys[index];
}
