#ifndef __ETCD_VECTOR_HPP__
#define __ETCD_VECTOR_HPP__

#include <string>
#include <vector>

#include <pplx/pplxtasks.h>

#include <etcd/v3/KeyValue.hpp>

namespace etcd
{
  /**
   * Represents a value object received from the etcd server
   */
  class Value
  {
  public:
    /**
     * Returns true if this value represents a directory on the server. If true the as_string()
     * method is meaningless.
     */
    bool is_dir() const;

    /**
     * Returns the key of this value as an "absolute path".
     */
    std::string const & key() const;

    /**
     * Returns the string representation of the value
     */
    std::string const & as_string() const;

    /**
     * Returns the creation index of this value.
     */
    int64_t created_revision() const;

    /**
     * Returns the last modification's index of this value.
     */
    int64_t modified_revision() const;

    /**
     * Returns the ttl of this value or 0 if ttl is not set
     */
    int ttl() const;
  
    int64_t lease() const;

  protected:
    friend class Response;
    friend class BaseResponse; // deliberately done since Value class will be removed during full V3
    friend class DeleteRpcResponse;
    friend class AsyncDeleteResponse;
    Value() = default;
    Value(etcdv3::KeyValue && kvs);
	// TODO: maybe add Value constructor from json to work with JSON responses
    std::string _key;
    bool        _dir = false;
    std::string _value;
    int64_t     _created = 0;
    int64_t     _modified = 0;
    int         _ttl = 0;
    int64_t     _lease_id = 0;
  };

  typedef std::vector<Value> Values;
}

#endif
