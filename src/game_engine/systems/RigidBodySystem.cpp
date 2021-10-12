/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** RigidBodySystem
*/

#include "RigidBodyComponent.hpp"
#include "RenderComponent.hpp"
#include "ShotComponent.hpp"
#include "RigidBodySystem.hpp"
#include "HealthComponent.hpp"

RigidBodySystem::RigidBodySystem()
{
}

RigidBodySystem::~RigidBodySystem()
{
}

void RigidBodySystem::detectCollision(std::vector<Entity *> &entities, int i)
{
    RenderComponent *renderM = entities.at(i)->getComponent<RenderComponent>("Render");
    for (Entity *entity : entities) {
        RenderComponent *renderL = entity->getComponent<RenderComponent>("Render");
        if (entity != entities.at(i) && entities.at(i)->getType() == "ally" && entity->getType() == "ennemy" && renderM->getDisplay() == true) {
            if (renderM->getSprite()->getSprite().getGlobalBounds().intersects(renderL->getSprite()->getSprite().getGlobalBounds())) {
                std::cout << "ally " << "collided with " << "ennemy" << std::endl;
                renderM->setDisplay(false);
                std::cout << "YOU LOSE" << std::endl;
                return;
            }
        }
        RenderComponent *renderS = entities.at(i)->getComponent<RenderComponent>("Render");
        if (entity != entities.at(i) && entities.at(i)->getType() == "shot") {
            if (entities.at(i)->getFrom() == "ally" && renderS->getDisplay() == true && entity->getType() == "ennemy") {
                if (renderM->getSprite()->getSprite().getGlobalBounds().intersects(renderL->getSprite()->getSprite().getGlobalBounds())) {
                    HealthComponent *health = entity->getComponent<HealthComponent>("Health");
                    renderS->setDisplay(false);
                    health->setCurrentHealth(health->getCurrentHealth() - 50);
                    std::cout << "Shot from " << "ally " << " collided with " << "ennemy" << std::endl;
                    return;
                }
            }
        }
    }
}