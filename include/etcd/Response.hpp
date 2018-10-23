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
  struct Response
  {
      int         error_code = 0;
      std::string error_message;
      int64_t     revision = 0;
      std::string action;
      Value       value;
      Value       prev_value;
      Values      values;
      Keys        keys;

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
      Response(int const error_code, std::string error_message);
      Response(etcdv3::V3Response && response);

      /**
     * Returns true if this is a successful response
     */
      bool is_ok() const;
  };
}

#endif
