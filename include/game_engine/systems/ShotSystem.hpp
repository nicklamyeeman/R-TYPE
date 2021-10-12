/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ShotSystem
*/

#ifndef SHOTSYSTEM_HPP_
#define SHOTSYSTEM_HPP_

#include "ISystem.hpp"

class ShotSystem : public ISystem {
	public:
		ShotSystem();
		~ShotSystem();

        Entity *createShotEntity(Entity *);
		void destroyShot(std::vector<Entity *> &, Entity *, int);
};

#endif /* !SHOTSYSTEM_HPP_ */
