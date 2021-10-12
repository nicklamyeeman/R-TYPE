/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <vector>
#include "IGame.hpp"

class Game : public IGame {
	public:
		Game(IUdpServer *serv, const std::string & playerAddr, int openPort, boost::asio::io_service &io_service);
		~Game();

		void disconnectPlayer(const std::string & player);

		const bool isPlayer(const std::string & player) const;

		const std::vector<std::string>	&getPlayersIP(void) const { return _players; }

		void handle_connection(const std::string & addr);
		void start_receive(void);
		void send_to(udp::endpoint remote_endpoint);
		void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred);
		void handle_send(boost::shared_ptr<std::string> message, const boost::system::error_code& error, std::size_t bytes_transferred);

		void addPlayer(const std::string & player);
		int	getNbPlayers(void) const { return _nbPlayers; }
		std::string	getHost(void) const { return _host; }

	public:
		int getPort(void) const { return _port; }
		void start_game(void);
		void back_to_main_menu(void);
		void fire(void);
        void move_up(void);
        void move_down(void);
        void move_left(void);
        void move_right(void);

	private:
		int			_port;
		int			_nbPlayers;
		bool		_shouldQuit;

		std::string	_currentAddr;
		std::string	_code;
		std::string _host;
		IUdpServer 	*_serv;
		std::vector<std::string>	_players;
		std::map<std::string, udp::endpoint> _playersEndpoints;
		std::map <STATE, std::map<std::string, void (Game::*)(void)> >	_state;

		udp::socket 			socket_;
		boost::shared_ptr<std::string> 	_gameMessage;
		udp::endpoint 			remote_endpoint_;
		boost::array<char, 3> 	recv_buffer_;
};

#endif /* !GAME_HPP_ */
