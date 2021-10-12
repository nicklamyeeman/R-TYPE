/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ShotSystem
*/

#include "ShotComponent.hpp"
#include "ShotSystem.hpp"
#include "RenderComponent.hpp"
#include "Entity.hpp"
#include "Engine.hpp"

ShotSystem::ShotSystem()
{
}

ShotSystem::~ShotSystem()
{
}

Entity *ShotSystem::createShotEntity(Entity *entity)
{
    ShotComponent *shot = entity->getComponent<ShotComponent>("Shot");
    TransformComponent *transformEntity = entity->getComponent<TransformComponent>("Transform");

    if (shot != nullptr && transformEntity != nullptr && shot->getShotAvailable() == true) {        
        Entity *newEntity = new Entity(shot->getBaseShot());

        RenderComponent *render = newEntity->getComponent<RenderComponent>("Render");
        TransformComponent *transform = newEntity->getComponent<TransformComponent>("Transform");

        if (render != nullptr && transform != nullptr)
            transform->setPositions(transformEntity->getPositions().first + 30, transformEntity->getPositions().second);
        shot->setShotAvailable(false);

        return newEntity;
    }
    return (nullptr);
}

void ShotSystem::destroyShot(std::vector<Entity *> &entities, Entity *entity, int pos)
{
    TransformComponent *transform = entity->getComponent<TransformComponent>("Transform");

    if (transform != nullptr) {
        if (transform->getPositions().first > 1100) {
            entities.erase(entities.begin() + pos);
            delete (entity);
        }
    }
}