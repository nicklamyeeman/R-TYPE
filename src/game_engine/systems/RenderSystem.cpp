/*
** EPITECH PROJECT, 2019
** game_engine
** File description:
** RenderSystem
*/

#include "RenderComponent.hpp"
#include "RenderSystem.hpp"

RenderSystem::RenderSystem()
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::drawSprite(Entity *entity, sf::RenderWindow &window) {
	RenderComponent *render = entity->getComponent<RenderComponent>("Render");

	if (render != nullptr && render->getDisplay() == true)
        window.draw(render->getSprite()->getSprite());
}