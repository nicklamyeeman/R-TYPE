/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** RigidBodySystem
*/

#ifndef RIGIDBODYSYSTEM_HPP_
#define RIGIDBODYSYSTEM_HPP_

#include "ISystem.hpp"

class RigidBodySystem : public ISystem {
	public:
		RigidBodySystem();
		~RigidBodySystem();

        void detectCollision(std::vector<Entity *> &, int);
};

#endif /* !RIGIDBODYSYSTEM_HPP_ */
