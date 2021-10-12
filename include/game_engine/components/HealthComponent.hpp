/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Health
*/

#ifndef HEALTHCOMPONENT_HPP_
#define HEALTHCOMPONENT_HPP_

#include "IComponent.hpp"

class HealthComponent : public IComponent {
	public:
		HealthComponent(const int health): _currentHealth(health), _maxHealth(health) {std::cout << "Health Component " << health << std::endl;};
		~HealthComponent() {};
		HealthComponent(HealthComponent *comp) {};

	public:
		const int getCurrentHealth() const {return _currentHealth;};
		const int getMaxHealth() const {return _maxHealth;};

	public:
		void setCurrentHealth(const int currentHealth) {_currentHealth = currentHealth;};
		void setMaxHealth(const int maxHealth) {_maxHealth = maxHealth;};
	
	private:
		int _currentHealth;
		int _maxHealth;
};

#endif /* !HEALTHCOMPONENT_HPP_ */
