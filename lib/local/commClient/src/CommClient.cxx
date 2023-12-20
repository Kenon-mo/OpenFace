#include "CommClient.hxx"

CommClient::CommClient(const unsigned int& portNumber, const std::string& ipAddr) : 
socket_(io_service_),
portNumber_(portNumber),
ipAddr_(boost::asio::ip::address::from_string(ipAddr))
{
    socket_.connect(boost::asio::ip::tcp::endpoint(ipAddr_, portNumber_));
}

CommClient::~CommClient()
{
}

void CommClient::sendMessage(const std::string& msg)
{
    boost::asio::write(socket_, boost::asio::buffer(msg + "\n"));
}

void CommClient::readSocketUntil(const std::string& delim)
{
    boost::asio::read_until(socket_, buf_, delim);
}

std::string CommClient::getBufferStr()
{
    return boost::asio::buffer_cast<const char*>(buf_.data());
}