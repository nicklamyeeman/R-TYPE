/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Scene
*/

#include "Scene.hpp"

Scene::Scene(const std::string &name)  {
	_name = name;
	std::cout << "Scene " << name << " created." << std::endl;
}

Scene::~Scene() {}

void Scene::addEntity(Entity *entity) {
	_entities.push_back(entity);
}

void Scene::clearEntities(void) {
	_entities.clear();
}
