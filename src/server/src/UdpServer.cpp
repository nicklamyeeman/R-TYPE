/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** UdpServer
*/

// #include <future>
#include "UdpServer.hpp"

UdpServer::UdpServer(boost::asio::io_service &io_service) : _nbClient(0), _ruleQueue(0), socket_(io_service, udp::endpoint(udp::v4(), 3000))
{
    _state[IN_MENU][__520__] = &UdpServer::create_game;
    _state[IN_MENU][__521__] = &UdpServer::list_server;
    _state[IN_MENU][__522__] = &UdpServer::quit_server;
    _state[SELECT_GAME][__530__] = &UdpServer::join_server;
    _state[SELECT_GAME][__531__] = &UdpServer::list_server;
    _state[SELECT_GAME][__532__] = &UdpServer::back_to_main_menu;
    bindOpenPorts();
    start_receive();
}

UdpServer::~UdpServer()
{
}

void UdpServer::bindOpenPorts(void) {
    _openPorts[3001] = true;
    _openPorts[3002] = true;
    _openPorts[3003] = true;
    _openPorts[3004] = true;
    _openPorts[3005] = true;
    _openPorts[3006] = true;
    _openPorts[3007] = true;
    _openPorts[3008] = true;
    _openPorts[3009] = true;
    _openPorts[3010] = true;
    _openPorts[3011] = true;
}

void UdpServer::start_receive(void)
{
    socket_.async_receive_from(
        boost::asio::buffer(recv_buffer_), remote_endpoint_,
        boost::bind(&UdpServer::handle_receive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred)
    );
}

void UdpServer::handle_connection(const std::string & addr)
{
    for (auto s : _users) {
        std::cout << "Already connected users: " << s.first << std::endl;
        if (s.first.compare(addr) == 0)
            return;
    }
    std::cout << "Welcome player [" + addr + "]" << std::endl;
    _users[addr].first = remote_endpoint_;
    _users[addr].second = new User(IN_MENU, addr);
}

void UdpServer::send_to(udp::endpoint remote_endpoint)
{
    socket_.async_send_to(boost::asio::buffer(*_message), remote_endpoint,
        boost::bind(&UdpServer::handle_send, this, _message,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred)
    );
}

void UdpServer::handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    std::string addr = remote_endpoint_.address().to_string();
    int ret = 0;

    if (recv_buffer_.c_array() != nullptr)
        _answer = recv_buffer_.c_array();
    else
        start_receive();
    if (!error || error == boost::asio::error::message_size) {
        _currentAddr = addr;
        _ruleQueue += 1;
        handle_connection(addr);
        if (_users[addr].second->getState() != CREATE_GAME && _users[addr].second->getState() != IN_GAME) {
            try {
                if (_state[_users[addr].second->getState()][_answer.substr(0, 3)] != nullptr) {
                    if (_users[addr].second->getState() != IN_GAME)
                        (this->*(_state[_users[addr].second->getState()][_answer.substr(0, 3)]))(addr, _answer);
                } else
                    _message = boost::shared_ptr<std::string> (new std::string("Command not found;" + addr + "\n"));
            } catch (const std::exception & excep) {
                std::cerr << "Catched an error" << std::endl;
            }
            send_to(remote_endpoint_);
        } else {
            std::cout << "Decision about the rule to follow sent to the right thread" << std::endl;
            _message = boost::shared_ptr<std::string> (new std::string("Change port.\n"));
            send_to(remote_endpoint_);
        }
        start_receive();
    }
}

void UdpServer::handle_send(boost::shared_ptr<std::string> message, const boost::system::error_code& error, std::size_t bytes_transferred)
{
}