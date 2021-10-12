/*
** EPITECH PROJECT, 2019
** game_engine
** File description:
** RenderComponent
*/

#ifndef RENDERCOMPONENT_HPP_
#define RENDERCOMPONENT_HPP_

#include "Sprite.hpp"
#include "IComponent.hpp"

class RenderComponent : public IComponent {
	public:
		RenderComponent(const boost::property_tree::ptree &comp);
		~RenderComponent();
		RenderComponent(RenderComponent *copy) {
			_path = copy->_path;
			_sprite = new Sprite(_path);
			_display = true;
		};

		const std::string getPath() const { return _path; }
		Sprite *getSprite() const { return _sprite; }
		bool getDisplay() { return _display; }

		void setSprite(Sprite *sprite) { _sprite = sprite; }
		void setDisplay(bool display) { _display = display; }

	private:
		std::string _path;
		Sprite *_sprite;
		bool	_display;
};

#endif /* !RENDERCOMPONENT_HPP_ */
