/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include "IComponent.hpp"
#include "ISystem.hpp"
#include "HealthComponent.hpp"
#include "TransformComponent.hpp"
#include "RenderComponent.hpp"
#include "ShotComponent.hpp"
#include "RigidBodyComponent.hpp"
#include "AnimatorComponent.hpp"
#include "EventComponent.hpp"
#include "BehaviorComponent.hpp"

class ComponentFactory {
	public:
		ComponentFactory() {};
		~ComponentFactory() {};

		std::pair<std::string, IComponent *> getComponent(const boost::property_tree::ptree::value_type &comp);
		std::pair<std::string, IComponent *> getComponent(const std::string &name, IComponent *comp);

};

#endif /* !COMPONENTFACTORY_HPP_ */
