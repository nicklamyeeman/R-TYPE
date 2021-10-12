/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AnimatorSystem
*/

#ifndef ANIMATORSYSTEM_HPP_
#define ANIMATORSYSTEM_HPP_

#include <iostream>
#include "Entity.hpp"
#include "ISystem.hpp"

class AnimatorSystem : public ISystem {
	public:
		AnimatorSystem();
		~AnimatorSystem();

		void addStep(Entity *);
		void subStep(Entity *);
		void updateStep(Entity *);
	protected:
	private:
};

#endif /* !ANIMATORSYSTEM_HPP_ */
