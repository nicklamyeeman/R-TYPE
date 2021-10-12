/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

#define COLOR_SOLO sf::Color(255, 255, 255)
#define COLOR_P1 sf::Color(128, 128, 255)
#define COLOR_P2 sf::Color(255, 128, 128)
#define COLOR_P3 sf::Color(200, 200, 120)
#define COLOR_P4 sf::Color(128, 255, 128)

class Sprite {
	public:
		Sprite(const std::string &path);
		~Sprite();

        enum player_pos {
                P1,
                P2,
                P3,
                P4
        };
        void setPositionSprite(std::pair<float, float>);
        void setScaleSprite(std::pair<float, float>);
        sf::Rect<int> getTextureRect(void) { return _sprite.getTextureRect(); }
        void setTextureRect(int left, int top, int width, int height);
        void setTextureRepeated(const bool b) { _texture.setRepeated(b); }
        void setColor(int);
        void moveSprite(float x, float y);

        sf::Sprite getSprite() const { return _sprite; };
        sf::Texture getTexture() const { return _texture; };
        // sf::Rect getRect() const { return _textureRect; };

	private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::Rect<int> _textureRect;
};

#endif /* !SPRITE_HPP_ */
