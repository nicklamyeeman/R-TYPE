/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** BehaviorComponent
*/

#ifndef BEHAVIORCOMPONENT_HPP_
#define BEHAVIORCOMPONENT_HPP_

#include "IComponent.hpp"

class BehaviorComponent : public IComponent {
	public:
		BehaviorComponent(const boost::property_tree::ptree &);
		~BehaviorComponent();

        float getX(void) const { return (_x); };
        float getY(void) const { return (_y); };

        void setX(const float x) { _x = x; };
        void setY(const float y) { _y = y; };

	protected:
	private:
        float _x;
        float _y;
};

#endif /* !BEHAVIORCOMPONENT_HPP_ */
