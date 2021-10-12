/*
** EPITECH PROJECT, 2019
** game_engine
** File description:
** TransformSystem
*/

#include "TransformComponent.hpp"
#include "RenderComponent.hpp"
#include "TransformSystem.hpp"

TransformSystem::TransformSystem()
{
}

TransformSystem::~TransformSystem()
{
}

void TransformSystem::setPosition(Entity *entity, float x, float y)
{
    TransformComponent *transform = entity->getComponent<TransformComponent>("Transform");
    RenderComponent *render = entity->getComponent<RenderComponent>("Render");        

    if (transform != nullptr && render != nullptr) {
        transform->setPositions(transform->getPositions().first + x, transform->getPositions().second + y);
        render->getSprite()->setPositionSprite(transform->getPositions());
    }
}

void TransformSystem::setScale(Entity *entity, float x, float y)
{
}

void TransformSystem::setMove(Entity *entity, float x, float y)
{
    RenderComponent *render = entity->getComponent<RenderComponent>("Render");        
    TransformComponent *transform = entity->getComponent<TransformComponent>("Transform");

    if (render != nullptr) {
        Sprite *sprite = render->getSprite();
        sprite->moveSprite(x, y);
        sf::Vector2f pair = render->getSprite()->getSprite().getPosition();
        transform->setPositions(pair.x, pair.y);
    }
}