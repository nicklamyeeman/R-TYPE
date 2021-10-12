/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AnimatorComponent
*/

#ifndef ANIMATORCOMPONENT_HPP_
#define ANIMATORCOMPONENT_HPP_

#include "IComponent.hpp"

class AnimatorComponent : public IComponent {
	public:
		AnimatorComponent(const boost::property_tree::ptree &);
                AnimatorComponent(const AnimatorComponent *copy);
		~AnimatorComponent();

        const std::pair<float, float> getOrigin(void) const { return (std::pair<float, float>(_originX, _originY)); };
        const std::pair<float, float> getRect(void) const { return (std::pair<float, float>(_rectX, _rectY)); };
        const std::pair<float, float> getPadding(void) const { return (std::pair<float, float>(_paddingX, _paddingY)); };
        const std::pair<int, int> getFrames(void) const { return (std::pair<int, int>(_framesX, _framesY)); };
        const std::pair<int, int> getStep(void) const { return (std::pair<int, int>(_stepX, _stepY)); };

        const std::string getLoop(void) const { return _loop; };
        const std::string getRewind(void) const { return _rewind; };
        const bool getIsRewind(void) const { return _isRewind; };

        void setOrigin(const float x, const float y) { _originX = x; _originY = y; };
        void setRect(const float x, const float y) { _rectX = x; _rectY = y; };
        void setPadding(const float x, const float y) { _paddingX = x; _paddingY = y; };
        void setFrames(const int x, const int y) { _framesX = x; _framesY = y; };
        void setStep(const int x, const int y) { _stepX = x; _stepY = y; };

        void setLoop(const std::string loop) { _loop = loop; };
        void setRewind(const std::string rewind) { _rewind = rewind; };
        void setIsRewind(const bool isRewind) { _isRewind = isRewind; };

	protected:
	private:
        float _originX;
        float _originY;
        float _rectX;
        float _rectY;
        float _paddingX;
        float _paddingY;
        int _framesX;
        int _framesY;
        int _stepX;
        int _stepY;

        std::string _loop;
        std::string _rewind;
        bool _isRewind;
};

#endif /* !ANIMATORCOMPONENT_HPP_ */
