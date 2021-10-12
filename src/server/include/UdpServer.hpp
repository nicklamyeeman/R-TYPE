/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** UdpServer
*/

#ifndef UDPSERVER_HPP_
#define UDPSERVER_HPP_

#include <map>

#include "IUdpServer.hpp"
#include "Game.hpp"
#include "rfc.hpp"

class UdpServer : public IUdpServer {
	public:
		UdpServer(boost::asio::io_service &io_service);
		~UdpServer();

	public:
		void send_to(udp::endpoint);
		IGame   *getPlayerGame(const std::string & addr);
		void eraseGame(const std::string & addr) { _games.erase(addr); }
		void changeGameHost(const std::string & oldHost, const std::string & newHost);
		const int getRuleQueue(void) const { return _ruleQueue; }
		const STATE getUserState(const std::string & addr) { return _users[addr].second->getState(); }
        void setOpenPort(int port, bool state) { _openPorts[port] = state; };
		const int getOpenPort(void);
		std::map<std::string, IGame *> getGames(void) { return _games; }
		const std::string & getAnswer(void) const { return _answer; }
		const std::string & getCurrentAddr(void) const { return _currentAddr; }
		const udp::endpoint getUserEndpoint(const std::string & addr) { return (_users[addr].first) ;}
		const std::map<std::string, std::pair<udp::endpoint, User *>> & getUsers(void) { return _users; }

		void setMessage(boost::shared_ptr<std::string> newMessage) { _message = newMessage; }
		void setUserState(const std::string & addr, STATE newState) { _users[addr].second->setState(newState); }

	public:
        void start_receive(void);
		void handle_connection(const std::string & addr);
        void handle_receive(const boost::system::error_code& error, std::size_t /*bytes_transferred*/);
        void handle_send(boost::shared_ptr<std::string> /*message*/, const boost::system::error_code& /*error*/, std::size_t /*bytes_transferred*/);

	private:
        void bindOpenPorts(void);
		void quit_server(const std::string &, const std::string &);
		void create_game(const std::string &, const std::string &);
		void list_server(const std::string &, const std::string &);
		void join_server(const std::string &, const std::string &);

		void transfer_map(int, const std::string &, const std::string & message);

	public:
		void createNewGame(const std::string & addr, boost::asio::io_service &io_service, int openPort);
		void back_to_main_menu(const std::string &, const std::string &);

	private:
		int _nbClient;
		int _ruleQueue;

		std::string						_answer;
		std::string 					_currentAddr;
		boost::shared_ptr<std::string> 	_message;
		std::map<std::string, IGame *>	_games;
		std::map<std::string, std::pair<udp::endpoint, User *>>	_users;
		std::map <STATE, std::map<std::string, void (UdpServer::*)(const std::string &, const std::string &)> >	_state;

		std::map<int, bool> 	_openPorts;
		udp::socket 			socket_;
		udp::endpoint 			remote_endpoint_;
		boost::array<char, 4> 	recv_buffer_;
};

#endif /* !UDPSERVER_HPP_ */
