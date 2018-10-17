#include <etcd/Utils.h>

namespace etcd {

namespace utils {

std::shared_ptr<grpc::Channel> createChannel(
	const std::string & address,
	const std::shared_ptr<grpc::ChannelCredentials> & channel_credentials)
{
	const std::string substr("://");
	const auto i = address.find(substr);
	const std::string stripped_address = (i != std::string::npos) ? address.substr(i + substr.length()) : "";
	return grpc::CreateChannel(stripped_address, channel_credentials);
}

} // namespace utils

} // namespace etcd
