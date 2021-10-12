/*
** EPITECH PROJECT, 2019
** client
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <ctime>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/thread.hpp>

using namespace boost::asio;
using ip::udp;

class Client {
	public:
		Client(char *addr, char *port, boost::asio::io_service &io_service);
		~Client();

	Client *getInstance(void);
	void func1(int fds);
	void func2(void);

	void start_send(void);
	void start_receive(void);

	void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred);
	void handle_send(std::string & line, const boost::system::error_code& error, std::size_t bytes_transferred);

	bool	_inGame;

	private:
		std::string _lol;
		udp::socket 				socket_;
		udp::socket 				gameSocket_;
		udp::endpoint 				remote_endpoint_;
		udp::endpoint 				game_endpoint_;
		boost::array<char, 100> 	recv_buffer_;
		std::map <std::string, void (Client::*)(const std::string &, const std::string &)> _rules;
};

#endif /* !CLIENT_HPP_ */
