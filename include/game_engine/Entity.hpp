/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <vector>
#include "IComponent.hpp"

class Entity {
	public:
		Entity(const std::string &path, int id);
		Entity(const Entity &copy);

		~Entity();

		template <typename T>
		T *getComponent(const std::string &componentType) {
			for (auto it = _components.begin(); it != _components.end(); it++) {
				if (it->first.compare(componentType) == 0)				
					return dynamic_cast<T *>(it->second);
			}
			return nullptr;
		}

		void setIP(const std::string &ip) { _ip = ip; };

		const int getID() const { return _id; }
		const std::string getType() const { return _type; }
		const std::string getFrom() const { return _from; }
		const std::string getIP() const { return _ip; };
		const std::map<std::string, IComponent *> getComponents() const { return _components; }

	private:
		int _id;
		std::string _type;
		std::string _from;
		std::string _name;
		std::string _sprite;
		std::string _ip;
		std::map<std::string, IComponent *> _components;
};

#endif /* !ENTITY_HPP_ */
