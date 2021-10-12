/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <string>
#include <vector>
#include "SFMLDisplay.hpp"
#include "Entity.hpp"

class Scene {
	public:
		Scene(const std::string &name);
		~Scene();

	public:
		void addEntity(Entity *entity);
		void clearEntities(void);

	public:
		std::vector<Entity *> getEntities(void) const { return _entities;};

	private:
		std::vector<Entity *> _entities;
		std::string _name;
};

#endif /* !SCENE_HPP_ */
