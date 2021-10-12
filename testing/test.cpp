/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** test
*/

#include <unistd.h>
#include <iostream>
#include <future>
<<<<<<< HEAD
#include "Client.hpp"
=======
>>>>>>> 9258a1c8a569364eb50bde1e1a79eb573befb747

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

<<<<<<< HEAD
int main(int ac, char **av) {
	double i = 0;
	// (std::async (func1));
    using namespace boost::asio;
    using ip::udp;
    io_service io_service;
	Client a(av[1], av[2], io_service);
=======
int main() {
	double i = 0;
	std::future<std::string> lol (std::async (func1));

	while(42) {
		// sleep(3);
		std::cout << "lol c la clebou" << std::endl;
		// std::cout << "debut " << std::endl;
		// std::cout << "fin" << std::endl;
		// if ((int)i % 1000000 == 0)
		// 	std::cout << "boucle " << std::endl;
	}
		// std::cout << "boucle" << std::endl;
>>>>>>> 9258a1c8a569364eb50bde1e1a79eb573befb747

  return 0;

}