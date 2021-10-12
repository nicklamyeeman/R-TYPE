/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** BehaviorComponent
*/

#include "BehaviorComponent.hpp"

BehaviorComponent::BehaviorComponent(const boost::property_tree::ptree &comp) try
{
    for (const boost::property_tree::ptree::value_type &_comp : comp) {
        if (_comp.first.compare("move") == 0) {
            _x = _comp.second.get<float>("x");
            _y = _comp.second.get<float>("y");
        }
    }

} catch (std::exception &e) {
    std::cerr << "Error Behavior component" << std::endl;
}

BehaviorComponent::~BehaviorComponent()
{
}
