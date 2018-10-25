#ifndef STATUS_H
#define STATUS_H

#include<grpc++/grpc++.h>

namespace etcdv3
{
  enum class StatusCode
      : int
  {
    UNKNOWN_ERROR = -2,
    UNDERLYING_GRPC_ERROR = -1,
    OK = 0,
    KEY_NOT_FOUND = 100,
    TEST_FAILED = 101,
    KEY_ALREADY_EXISTS = 105,
    KEY_READ_ONLY = 107,
    OTHER_ERROR = 999,
    USER_DEFINED_ERROR = 1099
  };

  /// Class representing both etcd and gRPC status codes and error messages
  struct V3Status
  {
    etcdv3::StatusCode etcd_error_code;
    grpc::StatusCode grpc_error_code;
    std::string etcd_error_message;
    std::string grpc_error_message;

    V3Status();
    V3Status(etcdv3::StatusCode const etcd_error_code, std::string etcd_error_message);
    V3Status(grpc::StatusCode const grpc_error_code, grpc::string grpc_error_message);
    V3Status(V3Status const &) = default;
    V3Status & operator =(V3Status const &) = default;
    V3Status(V3Status &&) = default;
    V3Status & operator =(V3Status &&) = default;

    bool is_ok() const;
    bool etcd_is_ok() const;
    bool grpc_is_ok() const;

    static etcdv3::StatusCode etcd_error_code_from_int(int const code);
  };
} // namespace etcd

#endif // STATUS_H
