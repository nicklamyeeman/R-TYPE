/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Sprite
*/

#include "Sprite.hpp"

Sprite::Sprite(const std::string &path) : _textureRect(0, 0, 0, 0)
{
    if (!_texture.loadFromFile(path))
        std::cout << "Can't load texture" << std::endl;
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(_textureRect);
}

Sprite::~Sprite()
{
}

void Sprite::moveSprite(float x, float y)
{
    sf::Vector2f v2f(x, y);
    _sprite.move(v2f);
}

void Sprite::setColor(int pp)
{
    if (pp == Sprite::player_pos::P1)
        _sprite.setColor(COLOR_P1);
    else if (pp == Sprite::player_pos::P2)
        _sprite.setColor(COLOR_P2);
    else if (pp == Sprite::player_pos::P3)
        _sprite.setColor(COLOR_P3);
    else if (pp == Sprite::player_pos::P4)
        _sprite.setColor(COLOR_P4);
    else
        _sprite.setColor(COLOR_SOLO);
}

void Sprite::setPositionSprite(std::pair<float, float> pos)
{
    _sprite.setPosition(pos.first, pos.second);
}

void Sprite::setScaleSprite(std::pair<float, float> pos)
{
    _sprite.setScale(pos.first, pos.second);
}

void Sprite::setTextureRect(int left, int top, int width, int height)
{
    sf::Rect<int> rect(left, top, width, height);
    _textureRect = rect;
    _sprite.setTextureRect(_textureRect);
}
