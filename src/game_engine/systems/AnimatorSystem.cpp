/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AnimatorSystem
*/

#include "AnimatorSystem.hpp"
#include "AnimatorComponent.hpp"

AnimatorSystem::AnimatorSystem()
{
}

AnimatorSystem::~AnimatorSystem()
{
}

void AnimatorSystem::addStep(Entity *entity)
{
    AnimatorComponent *animator = entity->getComponent<AnimatorComponent>("Animator");

    if (animator->getStep().first + 1 >= animator->getFrames().first) {
        if (animator->getStep().second + 1 > animator->getFrames().second);
        else {
            animator->setStep(0, animator->getStep().second + 1);
        }
    } else {
        animator->setStep(animator->getStep().first + 1, animator->getStep().second);
    }
}

void AnimatorSystem::subStep(Entity *entity)
{
    AnimatorComponent *animator = entity->getComponent<AnimatorComponent>("Animator");

    if (animator->getStep().first - 1 <= 0) {
        if (animator->getStep().second == 0);
        else {
            animator->setStep(animator->getFrames().first - 1, animator->getStep().second - 1);
        }
    } else {
        animator->setStep(animator->getStep().first - 1, animator->getStep().second);
    }
}

void AnimatorSystem::updateStep(Entity *entity)
{
    AnimatorComponent *animator = entity->getComponent<AnimatorComponent>("Animator");

    if (animator->getIsRewind() == false) {
        if (animator->getStep().first + 1 >= animator->getFrames().first &&
            animator->getStep().second >= animator->getFrames().second - 1) {
            if (animator->getRewind().compare("true") == 0) {
                animator->setIsRewind(true);
                subStep(entity);
            } else if (animator->getLoop().compare("true") == 0)
                animator->setStep(0, 0);
        } else
            addStep(entity);
    } else {
        if (animator->getStep().first - 1 == 0 &&
            animator->getStep().second == 0) {
            if (animator->getLoop().compare("true") == 0) {
                animator->setIsRewind(false);
                addStep(entity);
            }
        } else
            subStep(entity);
    }
}
