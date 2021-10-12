/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"

std::pair<std::string, IComponent *> ComponentFactory::getComponent(const boost::property_tree::ptree::value_type &comp) {
	if (comp.first.compare("Health") == 0)
		return (std::make_pair("Health", new HealthComponent(std::stoi(comp.second.data()))));
	if (comp.first.compare("Transform") == 0)
		return (std::make_pair("Transform", new TransformComponent(comp.second)));
	if (comp.first.compare("Render") == 0)
		return (std::make_pair("Render", new RenderComponent(comp.second)));
	if (comp.first.compare("Shot") == 0) {
		std::string path;
		std::string from;
		for (const boost::property_tree::ptree::value_type &_comp : comp.second) {
			if (_comp.first.compare("path") == 0)
				path = _comp.second.data();
			if (_comp.first.compare("from") == 0)
				from = _comp.second.data();
		}
 		return (std::make_pair("Shot", new ShotComponent(path, from)));
	}
	if (comp.first.compare("RigidBody") == 0)
		return (std::make_pair("RigidBody", new RigidBodyComponent(comp.second.data())));
	if (comp.first.compare("Animator") == 0)
		return (std::make_pair("Animator", new AnimatorComponent(comp.second)));
	if (comp.first.compare("Event") == 0)
		return (std::make_pair("Event", new EventComponent(comp.second)));
	if (comp.first.compare("Behavior") == 0)
		return (std::make_pair("Behavior", new BehaviorComponent(comp.second)));
	return std::make_pair("Error", nullptr);
}

std::pair<std::string, IComponent *> ComponentFactory::getComponent(const std::string &name, IComponent *comp) {
	if (name.compare("Health") == 0)
		return (std::make_pair("Health", new HealthComponent(reinterpret_cast<HealthComponent *>(comp))));
	if (name.compare("Transform") == 0)
		return (std::make_pair("Transform", new TransformComponent(reinterpret_cast<TransformComponent *>(comp))));
	if (name.compare("Render") == 0)
		return (std::make_pair("Render", new RenderComponent(reinterpret_cast<RenderComponent *>(comp))));
	if (name.compare("Shot") == 0)
		return (std::make_pair("Shot", new ShotComponent(reinterpret_cast<ShotComponent *>(comp))));
	if (name.compare("RigidBody") == 0)
		return (std::make_pair("RigidBody", new RigidBodyComponent(reinterpret_cast<RigidBodyComponent *>(comp))));
	if (name.compare("Animator") == 0)
		return (std::make_pair("Animator", new AnimatorComponent(reinterpret_cast<AnimatorComponent *>(comp))));
	if (name.compare("Event") == 0)
		return (std::make_pair("Event", new EventComponent(reinterpret_cast<EventComponent *>(comp))));
	return std::make_pair("Error", nullptr);
}