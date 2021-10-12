/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AnimatorComponent
*/

#include "AnimatorComponent.hpp"

AnimatorComponent::AnimatorComponent(const boost::property_tree::ptree &comp) try
{
    for (const boost::property_tree::ptree::value_type &_comp : comp) {
        if (_comp.first.compare("origin") == 0) {
            _originX = _comp.second.get<float>("x");
            _originY = _comp.second.get<float>("y");
        }
        if (_comp.first.compare("rect") == 0) {
            _rectX = _comp.second.get<float>("x");
            _rectY = _comp.second.get<float>("y");
        }
        if (_comp.first.compare("padding") == 0) {
            _paddingX = _comp.second.get<float>("x");
            _paddingY = _comp.second.get<float>("y");
        }
        if (_comp.first.compare("frames") == 0) {
            _framesX = _comp.second.get<int>("x");
            _framesY = _comp.second.get<int>("y");
        }
        if (_comp.first.compare("loop") == 0)
            _loop = _comp.second.data();
        if (_comp.first.compare("rewind") == 0)
            _rewind = _comp.second.data();
    }
    _stepX = 0;
    _stepY = 0;
    _isRewind = false;
    std::cout << "Animator Component" << std::endl;
} catch(std::exception &e) {
    std::cerr << "Error Animator component" << std::endl;
}

AnimatorComponent::~AnimatorComponent()
{
}

AnimatorComponent::AnimatorComponent(const AnimatorComponent *copy)
{
    _originX = copy->_originX;
    _originY = copy->_originY;
    _rectX = copy->_rectX;
    _rectY = copy->_rectY;
    _paddingX = copy->_paddingX;
    _paddingY = copy->_paddingY;
    _framesX = copy->_framesX;
    _framesY = copy->_framesY;
    _stepX = copy->_stepX;
    _stepY = copy->_stepY;
    _loop = copy->_loop;
    _rewind = copy->_rewind;
    _isRewind = copy->_isRewind;
}