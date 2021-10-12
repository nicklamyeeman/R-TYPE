/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** TransformComponent
*/

#ifndef TRANSFORMCOMPONENT_HPP_
#define TRANSFORMCOMPONENT_HPP_

#include <utility>
#include "IComponent.hpp"

class TransformComponent : public IComponent {
	public:
		TransformComponent(const boost::property_tree::ptree &comp);
		~TransformComponent();
		TransformComponent(TransformComponent *copy) {
			_isMoving = copy->_isMoving;
			_positionX = copy->_positionX;
			_positionY = copy->_positionY;
			_scaleX = copy->_scaleX;
			_scaleY = copy->_scaleY;
		};

	public:
		const std::pair<float, float> getPositions(void) const { return (std::pair<float, float>(_positionX, _positionY)); };
		const std::pair<float, float> getScales(void) const { return (std::pair<float, float>(_scaleX, _scaleY)); };
		const std::pair<float, float> getMove(void) const { return (std::pair<float, float>(_moveX, _moveY)); };
		const float getCurrentVelocity(void) const { return _currentVelocity; };
		const float getMaxVelocity(void) const { return _maxVelocity; };
		const bool getIsMoving(void) const { return _isMoving; }

		void setPositions(const float x, const float y) { _positionX = x; _positionY = y; };
		void setScale(const float x, const float y) { _scaleX = x; _scaleY = y; };
		void setMove(const float x, const float y) { _moveX = x; _moveY = y; };
		void setCurrentVelocity(const float vel) { _currentVelocity += vel; };
		void setMaxVelocity(const float maxVel) { _maxVelocity = maxVel; };
		void isMoving(bool isMoving) { _isMoving = isMoving; }

		void resetCurrentVelocity(void) { _currentVelocity = 0; };

	private:
		bool _isMoving;
		float _positionX;
		float _positionY;
		float _scaleX;
		float _scaleY;
		float _moveX;
		float _moveY;
		float _currentVelocity;
		float _maxVelocity;
};

#endif /* !TRANSFORMCOMPONENT_HPP_ */
