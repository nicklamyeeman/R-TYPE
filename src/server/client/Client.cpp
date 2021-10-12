/*
** EPITECH PROJECT, 2019
** client
** File description:
** Client
*/

#include <future>
#include "Client.hpp"

void Client::func2() {
	std::string elem;
	std::getline(std::cin, elem);
	std::cout << "func2 : " << elem << std::endl;
	func1(32);
}

void Client::func1(int fd) {
    std::future<void> fut = std::async (&Client::func2, this);
	std::cout << "func1" << std::endl;
}

Client::Client(char *addr, char *port, boost::asio::io_service &io_service) : _inGame(false), socket_(io_service), gameSocket_(io_service), remote_endpoint_(ip::address::from_string(addr), std::stoi(port))
{
    _lol = "nonononono";
    socket_.open(udp::v4());
    socket_.set_option(socket_base::broadcast(true));
    gameSocket_.open(udp::v4());
    gameSocket_.set_option(socket_base::broadcast(true));
    udp::socket sock(io_service);
    udp::endpoint end = remote_endpoint_;
	std::future<void> lol = std::async(&Client::start_send, this);
		std::cout <<  _lol << std::endl;

	while(42) {
        sleep(3);
		std::cout <<  _lol << std::endl;
	}
}

Client::~Client() {}

Client *Client::getInstance() {
    return (this);
}

void Client::start_send(void) {
    std::string line;
    std::cout << "before getline" << std::endl;
    std::cout << "getline = " << _lol << std::endl;
    _lol = "Buck Frice";
    socket_.async_send_to(boost::asio::buffer(line), remote_endpoint_,
        boost::bind(&Client::handle_send, this, line,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred)
    );
    std::cout << "lol " << line << std::endl;
}

void Client::handle_send(std::string & line, const boost::system::error_code& error, std::size_t bytes_transferred)
{
    std::cout << "MDR C LA CALLBACK : " << line << std::endl;
    if (!error || error == boost::asio::error::message_size) {
        std::cout << "Sent: [" << line << "]" << std::endl;
        start_receive();
    }
}

void Client::start_receive(void)
{
    std::cout << "SYNC RECEIVE" << std::endl;
    boost::system::error_code error;
    socket_.receive_from(
        boost::asio::buffer(recv_buffer_),
        remote_endpoint_,
        0,
        error
    );
    std::cout << recv_buffer_.c_array() << std::endl;
}

void Client::handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    std::string _answer;
    std::string addr = remote_endpoint_.address().to_string();
    int ret = 0;

    if (!error || error == boost::asio::error::message_size) {
        if (recv_buffer_.c_array() != nullptr) {
            _answer = recv_buffer_.c_array();
            std::cout << "Received from [" + addr + "]: " << _answer << std::endl;
        }
        if (_answer.compare("creation:3001\n") == 0) {
            _inGame = true;
            std::cout << "create a game.." << std::endl;
        }
        start_send();
    }
}