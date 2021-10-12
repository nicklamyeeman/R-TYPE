/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Game
*/

#include <iostream>
#include "Game.hpp"
#include "rfc.hpp"

Game::Game(IUdpServer *serv, const std::string & playerAddr, int openPort, boost::asio::io_service &io_service) : _nbPlayers(1),  _host(playerAddr), socket_(io_service, udp::endpoint(udp::v4(), openPort))
{
    _shouldQuit = false;
    _port = openPort;
    _serv = serv;
    _state[IN_GAME][__622__] = &Game::back_to_main_menu;
    _state[IN_GAME][__625__] = &Game::fire;
    _state[IN_GAME][__626__] = &Game::move_up;
    _state[IN_GAME][__627__] = &Game::move_down;
    _state[IN_GAME][__628__] = &Game::move_left;
    _state[IN_GAME][__629__] = &Game::move_right;

    _state[CREATE_GAME][__600__] = &Game::start_game;
    _state[CREATE_GAME][__602__] = &Game::back_to_main_menu;

    _players.push_back(playerAddr);
    start_receive();
}

Game::~Game()
{
}

void Game::handle_connection(const std::string & addr)
{
    for (auto s : getPlayersIP()) {
        std::cout << "In Game lobby: " << s << std::endl;
        if (s.compare(addr) == 0)
            return;
    }
}

void Game::start_receive(void)
{
    socket_.async_receive_from(
        boost::asio::buffer(recv_buffer_), remote_endpoint_,
        boost::bind(&Game::handle_receive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred)
    );
}

void Game::handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    _currentAddr = remote_endpoint_.address().to_string();

    std::cout << "Addr: " << _currentAddr << " | Buffer: " << recv_buffer_.c_array() << std::endl;
    for (auto s : _players) {
        std::cout << "Ip: " << s << std::endl;
        if (_playersEndpoints.find(s) == _playersEndpoints.end() && s.compare(_currentAddr) == 0) {
            std::cout << "Assigning Endpoint => " << remote_endpoint_ << " to addr: " << s << std::endl;
            _playersEndpoints[s] = remote_endpoint_;
        }
    }
    if (recv_buffer_.c_array() != nullptr)
        _code = recv_buffer_.c_array();
    handle_connection(_currentAddr);
    if (!error || error == boost::asio::error::message_size) {
        if (_state[_serv->getUserState(_currentAddr)][_code] != nullptr)
                (this->*(_state[_serv->getUserState(_currentAddr)][_code]))();
        else {
            _gameMessage = boost::shared_ptr<std::string> (new std::string ("Wrong cmd.\n"));
            send_to(_playersEndpoints[_currentAddr]);
        }
        if (_shouldQuit == true) {
            delete this;
            return;
        }
        start_receive();
    }
}

void Game::send_to(udp::endpoint remote_endpoint)
{
    std::cout << "Remote endpoint: " << remote_endpoint << std::endl;
    socket_.async_send_to(boost::asio::buffer(*_gameMessage), remote_endpoint,
        boost::bind(&Game::handle_send, this, _gameMessage,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred)
    );
}

void Game::handle_send(boost::shared_ptr<std::string> message, const boost::system::error_code& error, std::size_t bytes_transferred)
{
}

void Game::disconnectPlayer(const std::string & player)
{
    int newNbPlayers = 0;
    bool hostIsGone = false;
    std::vector<std::string> newPlayers;

    for (const std::string s : _players) {
        if (s.compare(player) != 0) {
            newPlayers.push_back(s);
            newNbPlayers += 1;
        }
        if (s.compare(player) == 0 && _host.compare(player) == 0) {
            hostIsGone = true;
        }
    }
    if (hostIsGone == true) {
        if (newPlayers.empty() == true) {
            _host = "noHost";
            _serv->eraseGame(player);
        } else {
            _host = newPlayers.front();
            _serv->changeGameHost(player, _host);
            std::cout << "Host is: " << _host << std::endl;
        }
    }
    _players = newPlayers;
    _nbPlayers = newNbPlayers;
    std::cout << "Number of player(s): " << _nbPlayers << std::endl;
}

const bool Game::isPlayer(const std::string & player) const
{
    for (const std::string s : _players) {
        if (s.compare(player) == 0)
            return true;
    }
    return false;
}

void Game::addPlayer(const std::string & player)
{
    _players.push_back(player);
    _nbPlayers += 1;
    std::cout << "Number of player(s): " << _nbPlayers << std::endl;
}