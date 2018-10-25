#include <etcd/v3/V3Status.h>


etcdv3::V3Status::V3Status()
  : etcd_error_code(etcdv3::StatusCode::OK)
  , grpc_error_code(grpc::StatusCode::OK)
{}

etcdv3::V3Status::V3Status(etcdv3::StatusCode const etcd_error_code, std::string etcd_error_message)
  : etcd_error_code(etcd_error_code)
  , grpc_error_code(grpc::StatusCode::OK)
  , etcd_error_message(std::move(etcd_error_message))
{}

etcdv3::V3Status::V3Status(grpc::StatusCode const grpc_error_code, grpc::string grpc_error_message)
  : etcd_error_code(grpc_error_code == grpc::StatusCode::OK ? etcdv3::StatusCode::OK : etcdv3::StatusCode::UNDERLYING_GRPC_ERROR)
  , grpc_error_code(grpc_error_code)
  , etcd_error_message(grpc_error_message.empty() ? "" : "Underlying gRPC error")
  , grpc_error_message(std::move(grpc_error_message))
{}

bool etcdv3::V3Status::is_ok() const
{
  return grpc_is_ok() && etcd_is_ok();
}

bool etcdv3::V3Status::etcd_is_ok() const
{
  return etcd_error_code == etcdv3::StatusCode::OK;
}

bool etcdv3::V3Status::grpc_is_ok() const
{
  return grpc_error_code == grpc::StatusCode::OK;
}

etcdv3::StatusCode etcdv3::V3Status::etcd_error_code_from_int(int const code)
{
  try
  {
    return static_cast<etcdv3::StatusCode>(code);
  }
  catch (...)
  {
    return etcdv3::StatusCode::UNKNOWN_ERROR;
  }
}
