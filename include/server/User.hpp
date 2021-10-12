/*
** EPITECH PROJECT, 2019
** server
** File description:
** User
*/

#ifndef USER_HPP_
#define USER_HPP_

#include <string>
#include <iostream>

enum    STATE {
    IN_MENU = 0,
    CREATE_GAME = 1,
    SELECT_GAME = 2,
    IN_GAME = 3,
};

class User {
	public:
		User(STATE initialState, const std::string & addr);
		~User();

    public:
        void    setState(STATE newState) { _state = newState; }

    public:
        const STATE     getState(void) const { return _state; }

	private:
        STATE       _state;
        std::string _addr;

};

#endif /* !USER_HPP_ */
