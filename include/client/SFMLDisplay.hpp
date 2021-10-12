/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SFMLDisplay
*/

#ifndef SFMLDISPLAY_HPP_
#define SFMLDISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <algorithm>
#include <list>
#include <queue>
#include "Sprite.hpp"
#include "IDisplay.hpp"
#include "TransformComponent.hpp"
#include "RenderComponent.hpp"
#include "ShotComponent.hpp"
#include "RigidBodyComponent.hpp"
#include "EventComponent.hpp"
#include "AnimatorComponent.hpp"
#include "BehaviorComponent.hpp"
#include "HealthComponent.hpp"

class SFMLDisplay : public IDisplay {
	public:
		SFMLDisplay();
		~SFMLDisplay();

        void closeWindow();
        bool isOpen() const;
        void clear();
        void display();
        bool events(std::vector<Entity *> &, TransformSystem *, ShotSystem *, std::string & toSend, bool inGame);

        void createSprites(std::vector<Entity *>);
        void createBackground(void);
        void displayBackground(void);
        void drawSprite(std::vector<Entity *> &, std::map<std::string, ISystem *> &, std::string &, std::string &toSend);
        // void moveSprites(std::vector<Entity *>);
        void createShot(std::vector<Entity *> &entities, Entity *, ShotSystem *, std::string &);
        void detectCollision(std::vector<Entity *> &, std::map<std::string, ISystem *> &);

        void moveUp(Entity *, TransformSystem *, EventComponent *, std::string &);
        void moveDown(Entity *, TransformSystem *, EventComponent *, std::string &);
        void moveLeft(Entity *, TransformSystem *, EventComponent *, std::string &);
        void moveRight(Entity *, TransformSystem *, EventComponent *, std::string &);

        sf::RenderWindow &getWindow(void) { return _window; }
        void handleShots(std::vector<Entity *> &, TransformSystem *, ShotSystem *, int);
        void handleEnnemies(std::vector<Entity *> &, TransformSystem *, ShotSystem *, int, std::string &toSend);

        template <typename T>
        T *getSystem(std::map<std::string, ISystem *> & _systems, const std::string &sys) { return dynamic_cast<T *>(_systems[sys]); }

        const sf::Time &getTime() const { return _time; }

        void updateClock(Entity *entity, sf::Time elapsed, RenderComponent *render, std::map<std::string, ISystem *> &systems);

	private:
        bool _bossTime;
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Clock _clock;
        sf::Time _time;
        sf::Clock _dt;
        sf::Music _mainSong;
        sf::SoundBuffer _fireBuffer;
        sf::Sound       _fireSound;
        Sprite  *_bg;
        Sprite  *_gbg;
        Sprite  *_wbg;
        Sprite  *_wbg2;
};

#endif /* !SFMLDISPLAY_HPP_ */
