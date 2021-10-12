/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SFMLDisplay
*/

#include "SFMLDisplay.hpp"

SFMLDisplay::SFMLDisplay() : _window(sf::VideoMode(1080, 720), "SFML window")
{
    _window.setKeyRepeatEnabled(true);
    _window.setFramerateLimit(60);
}

SFMLDisplay::~SFMLDisplay()
{
    _bossTime = false;
}

void SFMLDisplay::closeWindow()
{
    _window.close();
}

bool SFMLDisplay::isOpen() const
{
    return _window.isOpen();
}

void SFMLDisplay::clear()
{
    _window.clear();
}

void SFMLDisplay::display()
{
    _window.display();
}

void SFMLDisplay::moveUp(Entity *entity, TransformSystem *transformSystem, EventComponent *event, std::string &toSend)
{
    TransformComponent *transform = entity->getComponent<TransformComponent>("Transform");
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Key(event->getUp())) {
        transform->setMove(0, -200 * _time.asSeconds());
        transform->isMoving(true);
        toSend = "626";
        std::cout << "accelerate Up" << std::endl;
    }
    if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Key(event->getUp())) {
        transform->isMoving(false);
        RenderComponent *render = entity->getComponent<RenderComponent>("Render");
        if (render != nullptr)
            std::cout << render->getPath() << " decelerate up" << std::endl;
    }
}

void SFMLDisplay::createBackground(void)
{
    _mainSong.openFromFile("../sprites/rtype.ogg");
    _fireBuffer.loadFromFile("../sprites/laser.wav");
    _fireSound.setBuffer(_fireBuffer);
    _bg = new Sprite("../sprites/space.png");
    _bg->setTextureRepeated(true);
    _bg->setTextureRect(0, 0, 1920, 1080);
    _gbg = new Sprite("../sprites/glass.png");
    _gbg->setTextureRepeated(true);
    _gbg->setTextureRect(0, 0, 1080, 720);
    _wbg = new Sprite("../sprites/upwall.png");
    _wbg->setTextureRect(0, 0, 1394, 84);
    _wbg->setTextureRepeated(true);
    _wbg->setScaleSprite(std::pair<float, float>(2, 2));
    _wbg2 = new Sprite("../sprites/downwall.png");
    _wbg2->setPositionSprite(std::pair<float, float>(0, 555));
    _wbg2->setTextureRect(0, 0, 1394, 84);
    _wbg2->setTextureRepeated(true);
    _wbg2->setScaleSprite(std::pair<float, float>(2, 2));
    _mainSong.play();
}

void SFMLDisplay::displayBackground(void)
{
    if (_bossTime == false) {
        _bg->setTextureRect(_bg->getTextureRect().left + 1, 0, 1920, 1080);
        _gbg->setTextureRect(_gbg->getTextureRect().left + 3, 0, 1080, 720);
        _wbg->setTextureRect(_wbg->getTextureRect().left + 2, 0, 1394, 84);
        _wbg2->setTextureRect(_wbg->getTextureRect().left + 2, 0, 1394, 84);
    }
    _window.draw(_bg->getSprite());
    _window.draw(_gbg->getSprite());
    _window.draw(_wbg->getSprite());
    _window.draw(_wbg2->getSprite());
}

void SFMLDisplay::moveDown(Entity *entity, TransformSystem *transformSystem, EventComponent *event, std::string &toSend)
{
    TransformComponent *transform = entity->getComponent<TransformComponent>("Transform");
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Key(event->getDown())) {
        transform->setMove(0, 200 * _time.asSeconds());
        transform->isMoving(true);
        toSend = "627";
        std::cout << "accelerate Down" << std::endl;
    }
    if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Key(event->getDown())) {
        transform->isMoving(false);
        RenderComponent *render = entity->getComponent<RenderComponent>("Render");
        if (render != nullptr) {
            std::cout << render->getPath() << " decelerate down" << std::endl;
        }
    }
}

void SFMLDisplay::moveLeft(Entity *entity, TransformSystem *transformSystem, EventComponent *event, std::string &toSend)
{
    TransformComponent *transform = entity->getComponent<TransformComponent>("Transform");
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Key(event->getLeft())) {
        transform->setMove(-200 * _time.asSeconds(), 0);
        transform->isMoving(true);
        toSend = "628";
        std::cout << "accelerate Left" << std::endl;
    }
    if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Key(event->getLeft())) {
        transform->isMoving(false);
        RenderComponent *render = entity->getComponent<RenderComponent>("Render");
        if (render != nullptr)
            std::cout << render->getPath() << " decelerate left" << std::endl;
    }
}

void SFMLDisplay::moveRight(Entity *entity, TransformSystem *transformSystem, EventComponent *event, std::string &toSend)
{
    TransformComponent *transform = entity->getComponent<TransformComponent>("Transform");
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Key(event->getRight())) {
        transform->setMove(200 * _time.asSeconds(), 0);
        transform->isMoving(true);
        toSend = "629";
    }
    if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Key(event->getRight())) {
        transform->isMoving(false);
        RenderComponent *render = entity->getComponent<RenderComponent>("Render");
        if (render != nullptr)
            std::cout << render->getPath() << " decelerate right" << std::endl;
    }
}

void SFMLDisplay::detectCollision(std::vector<Entity *> &entities, std::map<std::string, ISystem *> &systems)
{
    for (int i = 0; i < entities.size(); i++) {
        RigidBodyComponent *rbComponent = entities.at(i)->getComponent<RigidBodyComponent>("RigidBody");
        if (rbComponent != nullptr) {
            RigidBodySystem *rbSystem = getSystem<RigidBodySystem>(systems, "RigidBodySystem");
            rbSystem->detectCollision(entities, i);
        }
    }
}

void SFMLDisplay::SFMLDisplay::createShot(std::vector<Entity *> &entities, Entity *entity, ShotSystem *shotSystem, std::string &toSend)
{
    Entity *newEntity = shotSystem->createShotEntity(entity);
    if (newEntity != nullptr) {
        toSend = "625";
        entities.push_back(newEntity);
    } else
        toSend = "";
}

bool SFMLDisplay::events(std::vector<Entity *> &entities, TransformSystem *transformSystem, ShotSystem *shotSystem, std::string & toSend, bool inGame)
{
    _time = _dt.restart();
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape))
            _window.close();
        if (inGame == true) {
            for (Entity *elem : entities) {
                EventComponent *event = elem->getComponent<EventComponent>("Event");
                TransformComponent *transform = elem->getComponent<TransformComponent>("Transform");
                if (event != nullptr && transform != nullptr && (_event.type == sf::Event::KeyPressed || _event.type == sf::Event::KeyReleased)) {
                    moveUp(elem, transformSystem, event, toSend);
                    moveRight(elem, transformSystem, event, toSend);
                    moveLeft(elem, transformSystem, event, toSend);
                    moveDown(elem, transformSystem, event, toSend);
                    if ((_event.type == sf::Event::KeyPressed) && (_event.key.code == event->getAction())) {
                        createShot(entities, elem, shotSystem, toSend);
                        if (toSend.empty() == false) {
                            _fireSound.play();
                            return true;
                        }
                        return false;
                    }
                    if ((_event.type == sf::Event::KeyReleased) && (_event.key.code == event->getAction())) {
                        ShotComponent *shot = elem->getComponent<ShotComponent>("Shot");
                        shot->setShotAvailable(true);
                    }
                }
            }
        }
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::A) { toSend = "521"; return true;}
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Z) { toSend = "531"; return true;}
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::E) { toSend = "532"; return true;}
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::R) { toSend = "522"; return true;}
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::T) { toSend = "520"; return true;}
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::J) { toSend = "5300"; return true;}
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Enter) { toSend = "600"; return true;}
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Q && inGame == false) { toSend = "602"; return true;}
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Q && inGame == true) { toSend = "622"; return true;}
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::F) { toSend = "625"; std::cout << "FIRED" << std::endl; return true;}
    }
    return false;
}

void SFMLDisplay::createSprites(std::vector<Entity *> entities)
{
    for (Entity *entity : entities) {
    	RenderComponent *render = entity->getComponent<RenderComponent>("Render");
        if (render != nullptr) {
            Sprite *sprite = new Sprite(render->getPath());
        	TransformComponent *transform = entity->getComponent<TransformComponent>("Transform");
            if (transform != nullptr) {
                sprite->setPositionSprite(transform->getPositions());
                sprite->setScaleSprite(transform->getScales());
            }
            render->setSprite(sprite);
        }
        AnimatorComponent *animator = entity->getComponent<AnimatorComponent>("Animator");
        if (render != nullptr && animator != nullptr) {
            Sprite *sprite = render->getSprite();
            int left = animator->getOrigin().first * animator->getRect().first + animator->getPadding().first;
            int top = animator->getOrigin().second * animator->getRect().second + animator->getPadding().second;
            sprite->setTextureRect(left, top, animator->getRect().first, animator->getRect().second);
        }
    }
}

void SFMLDisplay::handleShots(std::vector<Entity *> &entities, 
                            TransformSystem *transformSystem, 
                            ShotSystem *shotSystem,
                            int pos)
{
    if (entities.at(pos)->getType() == "shot") {
        transformSystem->setPosition(entities.at(pos), 700 *_time.asSeconds(), 0);
        shotSystem->destroyShot(entities, entities.at(pos), pos);
    }
}

void SFMLDisplay::handleEnnemies(std::vector<Entity *> &entities, 
                            TransformSystem *transformSystem, 
                            ShotSystem *shotSystem,
                            int pos, std::string &toSend)
{
    if (entities.at(pos) != nullptr && entities.at(pos)->getType() == "ennemy") {
        
        BehaviorComponent *behavior = entities.at(pos)->getComponent<BehaviorComponent>("Behavior");
        if (behavior != nullptr)
            transformSystem->setPosition(entities.at(pos), behavior->getX() * _time.asSeconds(), behavior->getY() * _time.asSeconds());
        else
            transformSystem->setPosition(entities.at(pos), -100 * _time.asSeconds(), 0);
        
        TransformComponent *transform = entities.at(pos)->getComponent<TransformComponent>("Transform");
        if (transform != nullptr && transform->getPositions().first <= -200)
            return;
        HealthComponent *health = entities.at(pos)->getComponent<HealthComponent>("Health");
        if (health != nullptr) {
            if (health->getMaxHealth() >= 3000 && transform->getPositions().first <= 500)
                _bossTime = true;
            if (health->getCurrentHealth() <= 0) {
                entities.erase(entities.begin() + pos);
                if (health->getMaxHealth() >= 3000)
                    std::cout << "YOU WIN" << std::endl;
            }
        }
    }
}

void SFMLDisplay::drawSprite(std::vector<Entity *> &entities, std::map<std::string, ISystem *> &systems, std::string &isSending, std::string &toSend)
{
    sf::Time elapsed = _clock.getElapsedTime();
    for (int i = 0; i < entities.size() ; i++) {
        TransformComponent *transform = entities.at(i)->getComponent<TransformComponent>("Transform");
    	RenderComponent *render = entities.at(i)->getComponent<RenderComponent>("Render");

        updateClock(entities.at(i), elapsed, render, systems);
        TransformSystem *transformSystem = getSystem<TransformSystem>(systems, "TransformSystem");
        if ((transform != nullptr) && (transform->getIsMoving() == true)) {
            isSending = "true";
            transformSystem->setMove(entities.at(i), transform->getMove().first, transform->getMove().second);
        }
        RenderSystem *renderSystem = getSystem<RenderSystem>(systems, "RenderSystem");
        ShotSystem *shotSystem = getSystem<ShotSystem>(systems, "ShotSystem");
        renderSystem->drawSprite(entities.at(i), _window);
        handleEnnemies(entities, transformSystem, shotSystem, i, toSend);
        handleShots(entities, transformSystem, shotSystem, i);
    }
}

void SFMLDisplay::updateClock(Entity *entity, sf::Time elapsed, RenderComponent *render, std::map<std::string, ISystem *> &systems)
{
    AnimatorComponent *animator = entity->getComponent<AnimatorComponent>("Animator");
    if (elapsed.asMilliseconds() > 100) {
        if (render != nullptr && animator != nullptr) {
            Sprite *sprite = render->getSprite();

            AnimatorSystem *animatorSystem = getSystem<AnimatorSystem>(systems, "AnimatorSystem");

            animatorSystem->updateStep(entity);

            int left = (animator->getOrigin().first * animator->getRect().first + animator->getPadding().first) + animator->getStep().first * animator->getRect().first;
            int top = (animator->getOrigin().second * animator->getRect().second + animator->getPadding().second) + animator->getStep().second * animator->getRect().second;
            sprite->setTextureRect(left, top, animator->getRect().first, animator->getRect().second);
        }
        _clock.restart();
    }
}