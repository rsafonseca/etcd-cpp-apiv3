#include "etcd/v3/AsyncKeepAliveAction.hpp"
#include <etcd/v3/Transaction.hpp>

using etcdserverpb::LeaseGrantRequest;

enum class Type {
    Connect = 1,
    Write = 2,
    Read = 3,
    Finish = 4,
};

etcdv3::AsyncKeepAliveAction::AsyncKeepAliveAction(ActionParameters param)
: etcdv3::Action(std::move(param))
, _stream(parameters.lease_stub->AsyncLeaseKeepAlive(&context, &cq_, reinterpret_cast<void*>(Type::Connect)))
{
    LeaseKeepAliveRequest keep_alive_req;
    keep_alive_req.set_id(parameters.lease_id);

    void *got_tag;
    bool ok = false;

    if (!cq_.Next(&got_tag, &ok)) {
        throw std::runtime_error("Failed to create lease keep alive stream");
    }

    if (!ok) {
        cq_.Shutdown();
        throw std::runtime_error("Completion queue not OK!");
    }

    Type tag = static_cast<Type>(reinterpret_cast<size_t>(got_tag));
    GPR_ASSERT(tag == Type::Connect);
}

etcdv3::AsyncKeepAliveAction::~AsyncKeepAliveAction()
{
    grpc::Status status;
    _stream->Finish(&status, reinterpret_cast<void*>(Type::Finish));

    void *got_tag = nullptr;
    bool ok = false;
    if (cq_.Next(&got_tag, &ok)) {
        Type tag = static_cast<Type>(reinterpret_cast<size_t>(got_tag));
        GPR_ASSERT(tag == Type::Finish);

        if (status.ok()) {
            std::cout << "Finished stream successfuly" << std::endl;
        } else {
            std::cerr << "Failed to finish stream" << std::endl;
        }
    }
}

void etcdv3::AsyncKeepAliveAction::waitForResponse()
{
    LeaseKeepAliveRequest keep_alive_req;
    keep_alive_req.set_id(parameters.lease_id);

    _stream->Write(keep_alive_req, reinterpret_cast<void*>(Type::Write));

    void* got_tag = nullptr;
    bool ok = false;

    while (cq_.Next(&got_tag, &ok)) {
        if (!ok) {
            cq_.Shutdown();
            return;
        }

        switch (static_cast<Type>(reinterpret_cast<size_t>(got_tag))) {
            case Type::Read:
                return;
            case Type::Write:
                _stream->Read(&_response, reinterpret_cast<void*>(Type::Read));
                break;
            default:
                GPR_ASSERT(false);
                break;
        }
    }
}

void etcdv3::AsyncKeepAliveAction::setLeaseId(int64_t lease_id)
{
    parameters.lease_id = lease_id;
}

etcdv3::AsyncKeepAliveResponse
etcdv3::AsyncKeepAliveAction::ParseResponse()
{
    if (!status.ok()) {
        return AsyncKeepAliveResponse(status.error_code(), status.error_message());
    }

    return AsyncKeepAliveResponse(_response);
}
