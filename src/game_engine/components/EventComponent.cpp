/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** EventComponent
*/

#include "EventComponent.hpp"

EventComponent::EventComponent(const boost::property_tree::ptree &comp) try {
	_onClick = false;
	_action = -1;

	std::cout << "Event component" << std::endl;

	for (const boost::property_tree::ptree::value_type &_comp : comp) {
		std::cout << _comp.first << std::endl;
		if (_comp.first.compare("moves") == 0) {
			_up = getCode(_comp.second.get<std::string>("Up"));
			_left = getCode(_comp.second.get<std::string>("Left"));
			_down = getCode(_comp.second.get<std::string>("Down"));
			_right = getCode(_comp.second.get<std::string>("Right"));
		}
		if (_comp.first.compare("action") == 0)
			_action = getCode(_comp.second.data());
		if (_comp.first.compare("onClick") == 0) {
			_onClickAction = _comp.second.data();
			_onClick = true;
		}
	}

	std::cout << _up << " " << _left << " " << _down << " " << _right << std::endl;
} catch (std::exception &e) {
	std::cerr << "prob with Event Component configuration" << std::endl;
}

EventComponent::EventComponent(const EventComponent *copy) {
	_up = copy->_up;
	_left = copy->_left;
	_down = copy->_down;
	_right = copy->_right;
	_action = copy->_action;
	_onClick = copy->_onClick;
	_onClickAction = copy->_onClickAction;
	
}

EventComponent::~EventComponent() {}

int EventComponent::getCode(std::string code) const {
	if (code.compare("left") == 0)
		return (71);
	if (code.compare("right") == 0)
		return (72);
	if (code.compare("up") == 0)
		return (73);
	if (code.compare("down") == 0)
		return (74);
	if (code.compare("space") == 0)
		return (57);
	return (code.at(0) - 'A');
}
