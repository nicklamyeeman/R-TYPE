/*
** EPITECH PROJECT, 2019
** game_engine
** File description:
** RenderSystem
*/

#ifndef RENDERSYSTEM_HPP_
#define RENDERSYSTEM_HPP_

#include <SFML/Graphics.hpp>
#include "ISystem.hpp"

class RenderSystem : public ISystem {
	public:
		RenderSystem();
		~RenderSystem();

        void drawSprite(Entity *entity, sf::RenderWindow &window);
};

#endif /* !RENDERSYSTEM_HPP_ */
