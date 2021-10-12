/*
** EPITECH PROJECT, 2019
** server
** File description:
** gameRules
*/

#include "Game.hpp"

using namespace boost::asio;
using ip::udp;

void Game::start_game(void)
{
    if (_host.compare(_currentAddr) != 0) {
        _gameMessage = boost::shared_ptr<std::string> (new std::string ("notHost\n"));
        send_to(_playersEndpoints[_currentAddr]);
        return;
    }
    std::string tmp = "start:" + _currentAddr;

    for (std::string s : getPlayersIP()) {
        if (_currentAddr.compare(s) != 0)
            tmp += ";" + s;
    }
    _gameMessage = boost::shared_ptr<std::string> (new std::string (tmp));
    for (std::string s: getPlayersIP()) {
        _playersEndpoints[s].address(ip::address::from_string(s));
        send_to(_playersEndpoints[s]);
        _serv->setUserState(s, IN_GAME);
    }
}

void Game::back_to_main_menu(void)
{
    std::cout << "Back to the menu" << std::endl;
    _serv->setUserState(_currentAddr, IN_MENU);
    disconnectPlayer(_currentAddr);
    if (_host.compare("noHost") == 0) {
        _gameMessage = boost::shared_ptr<std::string> (new std::string ("end:" + _currentAddr + "\n"));
        send_to(_playersEndpoints[_currentAddr]);
        _serv->setOpenPort(_port, true);
        _shouldQuit = true;
        _playersEndpoints.erase(_currentAddr);
        return;
    } else {
        _gameMessage = boost::shared_ptr<std::string> (new std::string ("quit:" + _currentAddr + "\n"));
        for (std::string s: getPlayersIP()) {
            send_to(_playersEndpoints[s]);
        }
        _playersEndpoints.erase(_currentAddr);
    }
}

void Game::fire(void)
{
    _gameMessage = boost::shared_ptr<std::string> (new std::string ("fire:" + _currentAddr + "\n"));

    for (std::string s: getPlayersIP()) {
        send_to(_playersEndpoints[s]);
    }
}

void Game::move_up(void)
{
    _gameMessage = boost::shared_ptr<std::string> (new std::string ("up:" + _currentAddr + "\n"));

    for (std::string s: getPlayersIP()) {
        std::cout << "Player: " << s << "move up" << std::endl;
        send_to(_playersEndpoints[s]);
    }
}

void Game::move_down(void)
{
    _gameMessage = boost::shared_ptr<std::string> (new std::string ("down:" + _currentAddr + "\n"));

    for (std::string s: getPlayersIP()) {
        send_to(_playersEndpoints[s]);
    }
}

void Game::move_left(void)
{
    _gameMessage = boost::shared_ptr<std::string> (new std::string ("left:" + _currentAddr + "\n"));

    for (std::string s: getPlayersIP()) {
        send_to(_playersEndpoints[s]);
    }
}

void Game::move_right(void)
{
    _gameMessage = boost::shared_ptr<std::string> (new std::string ("right:" + _currentAddr + "\n"));

    for (std::string s: getPlayersIP()) {
        send_to(_playersEndpoints[s]);
    }
}