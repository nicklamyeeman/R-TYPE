/*
** EPITECH PROJECT, 2019
** tcp
** File description:
** TcpServer
*/

#ifndef TCPSERVER_HPP_
#define TCPSERVER_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <pthread.h>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class tcp_connection : public boost::enable_shared_from_this<tcp_connection>
{
    public:
        tcp_connection(boost::asio::io_service& io_service);
        // tcp_connection(tcp::socket sock) { socket = sock; };

        void download(void);
        void handle_write(const boost::system::error_code&, size_t) { }
        tcp::socket& socket() { return socket_; }

        tcp::socket socket_;
    private:
        std::string toRead_;
        std::string message_;
};


class tcp_server {
    public:
        tcp_server(boost::asio::io_service& io_service);

        void start_accept();
        void handle_accept(tcp_connection *new_connection, const boost::system::error_code& error);

        tcp::acceptor acceptor_;
};

#endif /* !TCPSERVER_HPP_ */
