/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** DirFiles
*/

#ifndef DIRFILES_HPP_
#define DIRFILES_HPP_

#include <iostream>
#include <string>
#include <list>
#include <dirent.h>

class DirFiles {
	public:
		DirFiles(const std::string &directory);
		~DirFiles();

	public:
		const std::list<std::string> getNames(void) { return _files; };

	private:
		std::list<std::string> _files;
};

#endif /* !DIRFILES_HPP_ */
