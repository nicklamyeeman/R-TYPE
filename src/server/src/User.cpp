/*
** EPITECH PROJECT, 2019
** server
** File description:
** User
*/

#include "User.hpp"

User::User(STATE initialState, const std::string & addr) : _state(initialState), _addr(addr)
{
}

User::~User()
{
}

