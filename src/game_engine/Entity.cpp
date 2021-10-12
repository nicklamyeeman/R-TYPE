/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Entity
*/

#include <vector>
#include <boost/optional/optional.hpp>
#include "Entity.hpp"
#include "Engine.hpp"
#include "ComponentFactory.hpp"

Entity::Entity(const std::string &path, int id) try {
	ComponentFactory facto;
	boost::property_tree::ptree root;
	boost::property_tree::ptree components;
	boost::property_tree::read_json(path, root);
	boost::optional<std::string> from;

	components = root.get_child("components");
	_type = root.get<std::string>("type");
	from = root.get_optional<std::string>("from");
	if (from)
		_from = from.value();
	_id = id;
	std::cout <<"Entity n°" << _id << std::endl;
	for (boost::property_tree::ptree::value_type &comp : components) {
		std::pair<std::string, IComponent *> pairComponent = facto.getComponent(comp);
		_components.insert(pairComponent);
	}
} catch (std::exception) {
	std::cerr << "File \"" << path << "\" is a json file but maybe wrong format" << std::endl; 
}

Entity::~Entity() {
	for (auto const &x : _components) {
		std::cout << "Delete component" << std::endl;
		delete (x.second);
	}
	std::cout << "DELETE" << std::endl;
}

Entity::Entity(const Entity &copy) {
	ComponentFactory facto;
	std::cout << "Copy" << std::endl;
	_components = copy._components;
	for (std::pair<std::string, IComponent *> elem : _components) {
		_components[elem.first] = facto.getComponent(elem.first, elem.second).second;
	}
	_type = copy._type;
	_id = Engine::getNewID();
	_sprite = copy._sprite;
	if (copy._from.size() != 0)
		_from = copy._from;
}
