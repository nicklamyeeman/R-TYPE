/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <string>
#include "IUdpServer.hpp"
#include "User.hpp"

class IGame {
	public:
		virtual ~IGame() = default;

		virtual void disconnectPlayer(const std::string & player) = 0;

		virtual const bool isPlayer(const std::string & player) const = 0;

		virtual void addPlayer(const std::string &) = 0;
		virtual int getPort(void) const = 0;

		virtual const std::vector<std::string> &getPlayersIP(void) const = 0;

		virtual int	getNbPlayers(void) const = 0;
		virtual std::string	getHost(void) const = 0;
};

#endif /* !IGAME_HPP_ */
