//
// EPITECH PROJECT, 2018
// Rtype
// File description:
// Main
//

#include <stdio.h>
#include <iostream>
#include <exception>
#include <boost/asio.hpp>
#include "UdpServer.hpp"

int main(int argc, char **argv)
{
    try {
        boost::asio::io_service io_service;
        UdpServer server(io_service);
        io_service.run();
    } catch (const std::exception &excep) {
        std::cerr << excep.what() << std::endl;
        return 84;
    }
    return (0);
}
