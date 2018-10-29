#include "etcd/v3/AsyncKeepAliveAction.hpp"
#include <etcd/v3/Transaction.hpp>

using etcdserverpb::LeaseGrantRequest;

static constexpr const char *kKeepAliveTag = "keep_alive";
static constexpr const char *kKeepAliveWriteTag = "keep_alive_write";

etcdv3::AsyncKeepAliveAction::AsyncKeepAliveAction(ActionParameters param)
: etcdv3::Action(std::move(param))
, _stream(parameters.lease_stub->AsyncLeaseKeepAlive(&context, &cq_, (void*)kKeepAliveTag))
{
    LeaseKeepAliveRequest keep_alive_req;
    keep_alive_req.set_id(parameters.lease_id);

    void *got_tag;
    bool ok = false;

    if (cq_.Next(&got_tag, &ok) && ok && (got_tag == static_cast<const void*>(kKeepAliveTag))) {
        _stream->Write(keep_alive_req, (void*)kKeepAliveWriteTag);
        ok = false;
        if (cq_.Next(&got_tag, &ok) && ok && got_tag == static_cast<const void*>(kKeepAliveWriteTag)) {
            _stream->Read(&_response, (void*)this);
        } else {
            cq_.Shutdown();
        }
    } else {
        cq_.Shutdown();
    }
}

void etcdv3::AsyncKeepAliveAction::waitForResponse()
{
    void* got_tag;
    bool ok = false;

    if (cq_.Next(&got_tag, &ok)) {
        // if not ok or unknown tag received (or write done), break watch
        if (!ok || got_tag != (void*)this) {
            cq_.Shutdown();
            return;
        }

        // ok and got tag is for read
        _stream->Read(&_response, (void*)this);
    }
}

etcdv3::AsyncKeepAliveResponse
etcdv3::AsyncKeepAliveAction::ParseResponse()
{
    if (!status.ok()) {
        return AsyncKeepAliveResponse(status.error_code(), status.error_message());
    }

    return AsyncKeepAliveResponse(_response);
}
