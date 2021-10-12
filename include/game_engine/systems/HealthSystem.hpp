/*
** EPITECH PROJECT, 2019
** game_engine
** File description:
** HealthSystem
*/

#ifndef HEALTHSYSTEM_HPP_
#define HEALTHSYSTEM_HPP_

#include <iostream>
#include "ISystem.hpp"

class HealthSystem : public ISystem {
	public:
		HealthSystem();
		~HealthSystem();

        void takeDamage(Entity *entity, int damage);

	private:
};

#endif /* !HEALTHSYSTEM_HPP_ */
