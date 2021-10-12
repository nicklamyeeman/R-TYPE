/*
** EPITECH PROJECT, 2019
** server
** File description:
** TcpClient
*/

#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

void handler(const boost::system::error_code&, size_t) {}

int main(int ac, char **av) {
    try {
        boost::asio::io_service io_service;
        tcp::socket socket(io_service);

        socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 3031 ));
        boost::system::error_code error;
        boost::asio::streambuf receive_buffer;
        string data;

        while (1) {
            sleep(1);
            boost::asio::async_read(socket, receive_buffer, handler);
            if ( error && error != boost::asio::error::eof ) {
                cout << "receive failed: " << error.message() << endl;
            } else {
                const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
                cout << data << endl;
            }
        }
    } catch (std::exception & excep) {
        std::cout << excep.what() << std::endl;
    }
    return 0;
}