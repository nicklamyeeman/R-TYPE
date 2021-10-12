/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include <iostream>
#include <SFML/Audio.hpp>
#include "Entity.hpp"
#include "RenderSystem.hpp"
#include "TransformSystem.hpp"
#include "RigidBodySystem.hpp"
#include "ShotSystem.hpp"
#include "AnimatorSystem.hpp"
#include "ISystem.hpp"

class IDisplay {
	public:
		virtual ~IDisplay() = default;

		virtual void closeWindow() = 0;
		virtual bool isOpen() const = 0;
		virtual void clear() = 0;
		virtual void display() = 0;
		virtual bool events(std::vector<Entity *> &, TransformSystem *, ShotSystem *, std::string &, bool) = 0;
        virtual void createSprites(std::vector<Entity *>) = 0;
        virtual void createBackground(void) = 0;
        virtual void displayBackground(void) = 0;
		// virtual void moveSprites(std::vector<Entity *>) = 0;
		virtual void drawSprite(std::vector<Entity *> &, std::map<std::string, ISystem *> &, std::string &, std::string &) = 0;
		virtual void detectCollision(std::vector<Entity *> &, std::map<std::string, ISystem *> &) = 0;
        // virtual void createSprites() = 0;
        // virtual void setPositionSprite() = 0;
};

#endif /* !IDISPLAY_HPP_ */
