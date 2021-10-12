/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** EventSystem
*/

#include "EventSystem.hpp"

EventSystem::EventSystem() {}

EventSystem::~EventSystem() {}

int EventSystem::getMoveAction(const Entity *entity, const std::string &move) {
}

const std::string &EventSystem::getOnClick(const Entity *entity) {
	EventComponent *event = entity->getComponent<EventComponent>("Event");
	if (event == nullptr && event->getOnClick() == nullptr)
		return (nullptr);
	
}