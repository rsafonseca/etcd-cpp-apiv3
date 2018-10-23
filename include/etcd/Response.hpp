#ifndef __ETCD_RESPONSE_HPP__
#define __ETCD_RESPONSE_HPP__

#include <string>
#include <vector>

#include <etcd/Value.hpp>
#include <etcd/v3/V3Response.hpp>


namespace etcd
{
  typedef std::vector<std::string> Keys;

  /**
   * The Reponse object received for the requests of etcd::Client
   */
  class Response
  {
  public:

	  template<typename T> static pplx::task<etcd::Response> create(
		  std::shared_ptr<T> call,
		  const pplx::task_options & task_options)
	  {
		  return pplx::task<etcd::Response>([call]()
		  {
			  call->waitForResponse();
			  return etcd::Response(call->ParseResponse());
		  }, task_options);
	  }

    Response() = default;
	Response(int const error_code, const char * const error_message);
	Response(etcdv3::V3Response && response);

    /**
     * Returns true if this is a successful response
     */
    bool is_ok() const;

    /**
     * Returns the error code received from the etcd server. In case of success the error code is 0.
     */
    int error_code() const;

    /**
     * Returns the string representation of the error code
     */
    std::string const & error_message() const;

    /**
     * Returns the action type of the operation that this response belongs to.
     */
    std::string const & action() const;

    /**
     * Returns the current revision of etcd key-value store
     */
    int64_t revision() const;

    /**
     * Returns the value object of the response to a get/set/modify operation.
     */
    Value const & value() const;

    /**
     * Returns the previous value object of the response to a set/modify/rm operation.
     */
    Value const & prev_value() const;

    /**
     * Returns the index-th value of the response to an 'ls' operation. Equivalent to values()[index]
     */
    Value const & value(size_t const index) const;

    /**
     * Returns the vector of values in a directory in response to an 'ls' operation.
     */
    Values const & values() const;

    /**
     * Returns the vector of keys in a directory in response to an 'ls' operation.
     */
    Keys const & keys() const;

    /**
     * Returns the index-th key in a directory listing. Same as keys()[index]
     */
    std::string const & key(size_t const index) const;

  private:
    int         _error_code = 0;
    std::string _error_message;
    int64_t     _revision = 0;
    std::string _action;
    Value       _value;
    Value       _prev_value;
    Values      _values;
    Keys        _keys;
  };
}

#endif
