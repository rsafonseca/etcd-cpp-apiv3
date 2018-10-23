#include <etcd/v3/V3Response.hpp>


etcdv3::V3Response::V3Response(grpc::StatusCode const error_code, const grpc::string & error_message)
  : error_code(error_code)
  , error_message(error_message)
{}

etcdv3::V3Response::V3Response(int const error_code, std::string error_message)
  : error_code(error_code)
  , error_message(std::move(error_message))
{}

bool etcdv3::V3Response::has_values() const
{
  return values.size() > 0;
}
