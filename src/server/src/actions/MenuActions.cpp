/*
** EPITECH PROJECT, 2019
** server
** File description:
** MenuActions
*/

#include <iostream>
#include <fstream>
#include <string>
#include "UdpServer.hpp"

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

const int UdpServer::getOpenPort(void)
{
    for (auto p : _openPorts) {
        if (p.second == true) {
            return p.first;
        }
    }
    return -1;
}

void UdpServer::changeGameHost(const std::string & oldHost, const std::string & newHost)
{
    IGame *tmpGame = _games[oldHost];
    _games.erase(oldHost);
    _games[newHost] = tmpGame;
}

void UdpServer::quit_server(const std::string & addr, const std::string & code)
{
    _message = boost::shared_ptr<std::string> (new std::string(addr + ";offline\n"));
    _users.erase(addr);
}

void *game_thread(void *args)
{
    UdpServer *serv = static_cast<UdpServer *>(args);
    boost::asio::io_service io_service;
    int port = serv->getOpenPort();

    serv->createNewGame(serv->getCurrentAddr(), io_service, port);
    serv->setOpenPort(port, false);
    io_service.run();
    io_service.stop();
    pthread_exit(NULL);
    return (NULL);
}

void UdpServer::createNewGame(const std::string & addr, boost::asio::io_service &io_service, int openPort)
{
    _games[addr] = new Game(this, addr, openPort, io_service);
}

void UdpServer::create_game(const std::string & addr, const std::string & code)
{
    _users[addr].second->setState(CREATE_GAME);
    pthread_t t;
    int port = getOpenPort();
    if (port == -1) {
        _message = boost::shared_ptr<std::string> (new std::string ("noopenport\n"));
        return;
    }
    _message = boost::shared_ptr<std::string> (new std::string("creation:" + std::to_string(port) + "\n"));
    pthread_create(&t, NULL, &game_thread, (void *)this);
}

void UdpServer::join_server(const std::string & addr, const std::string & code)
{
    std::string subcode;
    IGame *game = nullptr;

    try {
        subcode = code.substr(3, 1);
    } catch (const std::exception & excep) {
        _message = boost::shared_ptr<std::string> (new std::string ("noexist\n"));
        throw excep;
    }
    int i = 0;
    for (auto g : _games) {
        if (i == std::stoi(subcode)) {
            game = g.second;
        }
        i += 1;
    }
    if (game == nullptr) {
        _message = boost::shared_ptr<std::string> (new std::string ("noexist\n"));
        return;
    }
    if (game->getNbPlayers() < 4) {
        game->addPlayer(addr);
        _users[addr].second->setState(CREATE_GAME);
        subcode = "player:" + addr + ";host:" + game->getHost() + "\n";
        _message = boost::shared_ptr<std::string> (new std::string(subcode));
        for (std::string s : game->getPlayersIP()) {
            send_to(_users[s].first);
        }
    } else {
        subcode = "noplace\n";
    }
    _message = boost::shared_ptr<std::string> (new std::string(subcode));
}

void UdpServer::list_server(const std::string & addr, const std::string & code)
{
    std::string pre_message;

    for (auto g : _games) {
        if (_users[g.first].second->getState() == CREATE_GAME)
            pre_message += g.second->getHost() + ";" + std::to_string(g.second->getNbPlayers()) + "/4;" + std::to_string(g.second->getPort()) + "\n";
    }
    if (pre_message.empty() == true) {
        pre_message = "none";
    }
    pre_message += "\n";
    _users[addr].second->setState(SELECT_GAME);
    _message = boost::shared_ptr<std::string> (new std::string(pre_message));
}

void UdpServer::back_to_main_menu(const std::string & addr, const std::string & code)
{
    _users[addr].second->setState(IN_MENU);
    _message = boost::shared_ptr<std::string> (new std::string(addr + ";menu\n"));
}