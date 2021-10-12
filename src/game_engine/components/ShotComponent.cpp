/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ShotComponent
*/

#include "RenderComponent.hpp"
#include "ShotComponent.hpp"
#include "Engine.hpp"

ShotComponent::ShotComponent(const std::string &path, const std::string &from) : _baseShot(path, Engine::getNewID())
{
    std::cout << "Shot Component " << _path << std::endl;
    std::cout << "From: " << _from << std::endl;
    _isShotAvailable = true;
}

ShotComponent::~ShotComponent()
{
}