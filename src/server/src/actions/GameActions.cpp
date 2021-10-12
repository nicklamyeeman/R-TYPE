/*
** EPITECH PROJECT, 2019
** server
** File description:
** GameActions
*/

#include "UdpServer.hpp"

IGame   *UdpServer::getPlayerGame(const std::string & addr)
{
    for (auto g : _games) {
        if (g.second->isPlayer(addr) == true) {
            std::cout << "Host: " << g.second->getHost() << std::endl;
            return g.second;
        }
    }
    return nullptr;
}