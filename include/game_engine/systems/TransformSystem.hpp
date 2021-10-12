/*
** EPITECH PROJECT, 2019
** game_engine
** File description:
** TransformSystem
*/

#ifndef TRANSFORMSYSTEM_HPP_
#define TRANSFORMSYSTEM_HPP_

#include "ISystem.hpp"

class TransformSystem : public ISystem {
	public:
		TransformSystem();
		~TransformSystem();

		void setPosition(Entity *, float, float);
		void setScale(Entity *, float, float);
		// void setMove(Entity *, const std::string &);
		void setMove(Entity *, float, float);
};

#endif /* !TRANSFORMSYSTEM_HPP_ */
