/*
** EPITECH PROJECT, 2019
** game_engine
** File description:
** HealthSystem
*/

#include "HealthComponent.hpp"
#include "HealthSystem.hpp"

HealthSystem::HealthSystem() {}

HealthSystem::~HealthSystem() {}

void HealthSystem::takeDamage(Entity *entity, int damage) {
	HealthComponent *health = entity->getComponent<HealthComponent>("Health");
	if (health != nullptr)
		health->setCurrentHealth(health->getCurrentHealth() - damage);
}
