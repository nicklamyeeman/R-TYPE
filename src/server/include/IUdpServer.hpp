/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IUdpServer
*/

#ifndef IUDPSERVER_HPP_
#define IUDPSERVER_HPP_

#include <ctime>
#include <string>
#include <vector>
#include <iostream>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "User.hpp"

using boost::asio::ip::udp;

class IUdpServer {
	public:
		virtual ~IUdpServer() = default;

        public:
        virtual void send_to(udp::endpoint) = 0;
        virtual void setOpenPort(int port, bool state) = 0;
        virtual const int getOpenPort(void) = 0;
        virtual void eraseGame(const std::string & addr) = 0;
        virtual void changeGameHost(const std::string & oldHost, const std::string & newHost) = 0;
        virtual const std::string & getAnswer(void) const = 0;
        virtual const std::string & getCurrentAddr(void) const = 0;
        virtual const STATE getUserState(const std::string & addr) = 0;
        virtual const udp::endpoint getUserEndpoint(const std::string & addr) = 0;
        virtual const std::map<std::string, std::pair<udp::endpoint, User *>> & getUsers(void) = 0;
        virtual const int getRuleQueue(void) const = 0;

        virtual void setUserState(const std::string & addr, STATE) = 0;
        virtual void setMessage(boost::shared_ptr<std::string>) = 0;

	public:
        virtual void bindOpenPorts(void) = 0;
        virtual void start_receive(void) = 0;
        virtual void handle_connection(const std::string &addr) = 0;
        virtual void handle_receive(const boost::system::error_code& error, std::size_t /*bytes_transferred*/) = 0;
        virtual void handle_send(boost::shared_ptr<std::string> /*message*/, const boost::system::error_code& /*error*/, std::size_t /*bytes_transferred*/) = 0;

        private:
        virtual void create_game(const std::string &, const std::string &) = 0;
        virtual void list_server(const std::string &, const std::string &) = 0;
        virtual void join_server(const std::string &, const std::string &) = 0;

        private:
        virtual void createNewGame(const std::string & addr, boost::asio::io_service &io_service, int openPort) = 0;
        // virtual void transfer_map(int, const std::string &) = 0;

        public:
        virtual void back_to_main_menu(const std::string &, const std::string &) = 0;
};

#endif /* !IUDPSERVER_HPP_ */
