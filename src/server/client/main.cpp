/*
** EPITECH PROJECT, 2019
** client
** File description:
** main
*/

#include "Client.hpp"

int main(int ac, char **av)
{
    using namespace boost::asio;
    using ip::udp;
    io_service io_service;

    if (ac != 3)
        return 84;
    try {
        std::stoi(av[2]);
        Client cli(av[1], av[2], io_service);
        io_service.run();
    } catch (std::exception & excep) {
        return 84;
    }
    return 0;
}
