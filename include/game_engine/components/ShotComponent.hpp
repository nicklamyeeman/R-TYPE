/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ShotComponent
*/

#ifndef SHOTCOMPONENT_HPP_
#define SHOTCOMPONENT_HPP_

#include "IComponent.hpp"
#include "Entity.hpp"

class ShotComponent : public IComponent {
	public:
		ShotComponent(const std::string &path, const std::string &from);
		~ShotComponent();
		ShotComponent(ShotComponent *copy): _baseShot(copy->_baseShot) {};

		const std::string getPath() const { return _path; }
		const std::string getFrom() const { return _from; }
		const bool getShotAvailable() const { return _isShotAvailable; }
		Entity getBaseShot() { return _baseShot; }

		void setShotAvailable(bool tmp) { _isShotAvailable = tmp; }

	private:
		bool		_isShotAvailable;
        std::string _path;
		std::string _from;
		Entity _baseShot;
};

#endif /* !SHOTCOMPONENT_HPP_ */
