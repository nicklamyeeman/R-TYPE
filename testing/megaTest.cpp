/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** test
*/

#include <unistd.h>
#include <iostream>
#include <future>
#include "Client.hpp"

std::string func1(void);

void func2() {
	std::string elem;
	std::getline(std::cin, elem);
	std::cout << "func2 : " << elem << std::endl;
	func1();
}
std::string func1() {
	std::future<void> fut = std::async (func2);
	std::cout << "func1" << std::endl;
	return ("judi est un con");
}

int main(int ac, char **av) {
	double i = 0;
	// (std::async (func1));
    using namespace boost::asio;
    using ip::udp;
    io_service io_service;
	Client a(av[1], av[2], io_service);

  return 0;

}