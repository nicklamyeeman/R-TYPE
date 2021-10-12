/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** RigidBodyComponent
*/

#include "RigidBodyComponent.hpp"

RigidBodyComponent::RigidBodyComponent(const std::string &isRigid)
{
    setRigid(isRigid);
    std::cout << "RigidBody Component: " << _isRigid << std::endl;
}

RigidBodyComponent::~RigidBodyComponent()
{
}
