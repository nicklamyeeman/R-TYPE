/*
** EPITECH PROJECT, 2019
** game_engine
** File description:
** TransformComponent
*/

#include "TransformComponent.hpp"

TransformComponent::TransformComponent(const boost::property_tree::ptree &comp) try
{
	for (const boost::property_tree::ptree::value_type &_comp : comp) {
        if (_comp.first.compare("position") == 0) {
            _positionX = _comp.second.get<float>("x");
            _positionY = _comp.second.get<float>("y");
        }
        if (_comp.first.compare("scale") == 0) {
            _scaleX = _comp.second.get<float>("x");
            _scaleY = _comp.second.get<float>("y");
        }
	}
    _isMoving = false;
    _currentVelocity = 0;
    _maxVelocity = 10;
    _moveX = 0;
    _moveY = 0;
    std::cout << "Transform Component" << std::endl;
} catch(std::exception &e) {
    std::cerr << "Error Transform component" << std::endl;
}

TransformComponent::~TransformComponent()
{
}
