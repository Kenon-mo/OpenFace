#pragma once

#include <string>

#include <boost/asio.hpp>

class CommClient
{
private:
    boost::asio::io_service io_service_;
    boost::asio::ip::tcp::socket socket_;

    /**
     * @brief Internal read buffer
     */
    boost::asio::streambuf buf_;

    /**
     * @brief portNumber to connect to
     */
    const unsigned int portNumber_;
    /**
     * @brief ip address to connect to
     */
    const boost::asio::ip::address ipAddr_;
public:
    /**
     * @brief Class handling client connection to server, used for debugging purposes
     * @param portNumber Port number of the server
     * @param ipAddr_ Ip address of the server
     * @param helloMessage Message to send to the server on connect
     */
    CommClient(const unsigned int& portNumber, const std::string& ipAddr_);
    ~CommClient();

    void sendMessage(const std::string& msg);
    /**
     * @brief Wait for the response from the server
     */
    void readSocketUntil(const std::string& delim = "\n");
    std::string getBufferStr();
};
