/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** main
*/

#include <stdio.h>
#include <iostream>
#include <exception>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/thread.hpp>

#include "SFMLDisplay.hpp"
#include "Engine.hpp"

int main(int ac, char **av)
{
    using namespace boost::asio;
    using ip::udp;
    io_service io_service;

    if (ac != 3)
        return 84;
    try {
        std::stoi(av[2]);
        Engine e(av[1], av[2], io_service);
        e.run();
        io_service.run();
        std::cout << "Io service" << std::endl;
    } catch (std::exception & excep) {
        return 84;
    }
    return 0;
}