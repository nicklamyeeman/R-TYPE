/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** RigidBodyComponent
*/

#ifndef RIGIDBODYCOMPONENT_HPP_
#define RIGIDBODYCOMPONENT_HPP_

#include "IComponent.hpp"

class RigidBodyComponent : public IComponent {
	public:
		RigidBodyComponent(const std::string &isRigid);
		~RigidBodyComponent();
		RigidBodyComponent(RigidBodyComponent *) {};

        void setRigid(const std::string &tmp) { _isRigid = tmp; }

	private:
        std::string _isRigid;
};

#endif /* !RIGIDBODYCOMPONENT_HPP_ */
