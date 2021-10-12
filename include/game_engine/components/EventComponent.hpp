/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** EventComponent
*/

#ifndef EVENTCOMPONENT_HPP_
#define EVENTCOMPONENT_HPP_

#include "IComponent.hpp"

class EventComponent : public IComponent {
	public:
		EventComponent(const boost::property_tree::ptree &comp);
		EventComponent(const EventComponent *copy);
		~EventComponent();

		const int getUp(void) const {return _up;};
		const int getDown(void) const {return _down;};
		const int getLeft(void) const {return _left;};
		const int getRight(void) const {return _right;};
		const int getAction(void) const {return _action;};
		const std::string getOnClick(void) {return ((_onClick == true) ? _onClickAction : nullptr);};

	private:
		int getCode(std::string code) const;

	private:
		int _up;
		int _left;
		int _down;
		int _right;
		int _action;
		bool _onClick;
		std::string _onClickAction;

};

#endif /* !EVENTCOMPONENT_HPP_ */
