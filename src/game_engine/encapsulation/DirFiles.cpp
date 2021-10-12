/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** DirFiles
*/

#include "DirFiles.hpp"

DirFiles::DirFiles(const std::string &directory) {
	DIR				*dir = opendir(directory.c_str());
	struct dirent	*select;
	std::exception e;

	if (dir != NULL) {
		while ((select = readdir(dir)) != NULL) {
			std::string name(select->d_name);
			if (name.compare(".") != 0 && name.compare("..") != 0)
				_files.push_back(std::string(select->d_name));
		}
		closedir(dir);
	}
	else
		throw e;
}

DirFiles::~DirFiles() {}
