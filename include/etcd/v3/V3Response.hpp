#ifndef __V3_RESPONSE_HPP__
#define __V3_RESPONSE_HPP__

#include <grpc++/grpc++.h>
#include <etcd/v3/KeyValue.hpp>

namespace etcdv3
{
  struct V3Response
  {
      int64_t revision = 0;
      int error_code = 0;
      std::string error_message;
      std::string action;
      etcdv3::KeyValue value;
      etcdv3::KeyValue prev_value;
      std::vector<etcdv3::KeyValue> values;
      std::vector<etcdv3::KeyValue> prev_values;

      V3Response() = default;
      V3Response(grpc::StatusCode const error_code, grpc::string const & error_message);
      V3Response(int const error_code, std::string error_message);

      bool has_values() const;
  };
}

#endif
