#include <iomanip>
#include <etcd/Value.hpp>
#include <etcd/v3/KeyValue.hpp>


etcd::Value::Value(etcdv3::KeyValue && kv)
  : _key(std::move(kv.kvs.key()))
  , _value(std::move(kv.kvs.value()))
  , _created(kv.kvs.create_revision())
  , _modified(kv.kvs.mod_revision())
  , _ttl(kv.get_ttl())
  , _lease_id(kv.kvs.lease())
{}

std::string const & etcd::Value::key() const
{
  return _key;
}

bool etcd::Value::is_dir() const
{
  return _dir;
}

std::string const & etcd::Value::as_string() const
{
  return _value;
}

int64_t etcd::Value::created_revision() const
{
  return _created;
}

int64_t etcd::Value::modified_revision() const
{
  return _modified;
}

int etcd::Value::ttl() const
{
  return _ttl;
}

int64_t etcd::Value::lease() const
{
  return _lease_id;
}
