/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** EventSystem
*/

#ifndef EVENTSYSTEM_HPP_
#define EVENTSYSTEM_HPP_

#include "EventComponent.hpp"
#include "ISystem.hpp"

class EventSystem {
	public:
		EventSystem();
		~EventSystem();

	public:
		int getMoveAction(const std::string &move);
		const std::string &getOnClick();

	private:
};

#endif /* !EVENTSYSTEM_HPP_ */
