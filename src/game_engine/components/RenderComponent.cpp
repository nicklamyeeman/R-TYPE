/*
** EPITECH PROJECT, 2019
** game_engine
** File description:
** RenderComponent
*/

#include "RenderComponent.hpp"
#include "boost/lexical_cast.hpp"

RenderComponent::RenderComponent(const boost::property_tree::ptree &comp)
{
	for (const boost::property_tree::ptree::value_type &_comp : comp) {
        if (_comp.first.compare("path") == 0)
            _path = _comp.second.data();
        if (_comp.first.compare("display") == 0)
        _display = boost::lexical_cast<bool>(_comp.second.data());
    }
    std::cout << _display << std::endl;
    std::cout << "Render Component " << _path << std::endl;
}

RenderComponent::~RenderComponent()
{
}
