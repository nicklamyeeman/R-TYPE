/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Engine
*/

#include "Engine.hpp"
#include "Explode.hpp"

Engine::Engine(char *addr, char *port, boost::asio::io_service &io_service) : _inGame(false), _port(std::stoi(port)), _gamePort(0), _addr(addr), socket_(io_service), game_socket_(io_service), remote_endpoint_(ip::address::from_string(_addr), _port)
{
	_toSend = "";
	_i = 0;
	_gameStarted = false;
	_isListening = true;
	_isSending = "false";
	socket_.open(udp::v4());
    socket_.set_option(socket_base::broadcast(true));
    game_socket_.open(udp::v4());
    game_socket_.set_option(socket_base::broadcast(true));
	recv_buffer_.fill('\0');
	_win = new SFMLDisplay();
	try {
		DirFiles files("../src/game_engine/entities");
		for (const std::string &fileName : files.getNames()) {
			createEntity("../src/game_engine/entities/" + fileName);
		}
		DirFiles files_level("../src/game_engine/entities/level1");
		for (const std::string &fileName : files_level.getNames()) {
			createEntity("../src/game_engine/entities/level1/" + fileName);
		}
	} catch (std::exception &e) {
		std::cerr << "An error occured while getting Json file " << e.what() << std::endl;
	}
	initStates();
	initExecs();
	initScenes();
	initSystems();
}

Engine::~Engine()
{
}

void Engine::initStates(void)
{
	_state["creation"] = &Engine::isCreation;
	_state["start"] = &Engine::isStarted;
	_state["622"] = &Engine::isEnded;
	_state["602"] = &Engine::isEnded;
	_state["up"] = &Engine::isMoveUp;
	_state["down"] = &Engine::isMoveDown;
	_state["left"] = &Engine::isMoveLeft;
	_state["right"] = &Engine::isMoveRight;
	_state["fire"] = &Engine::isFire;
	_state["player"] = &Engine::isJoined;
}

void Engine::initExecs(void)
{
	_exec["creation"] = &Engine::execCreation;
	_exec["start"] = &Engine::execStarted;
	_exec["622"] = &Engine::execEnded;
	_exec["602"] = &Engine::execEnded;
	_exec["up"] = &Engine::execMoveUp;
	_exec["down"] = &Engine::execMoveDown;
	_exec["left"] = &Engine::execMoveLeft;
	_exec["right"] = &Engine::execMoveRight;
	_exec["fire"] = &Engine::execFire;
	_exec["player"] = &Engine::execJoined;
}

void Engine::initSystems(void)
{
	_systems["HealthSystem"] = new HealthSystem();
	_systems["TransformSystem"] = new TransformSystem();
	_systems["RenderSystem"] = new RenderSystem();
	_systems["RigidBodySystem"] = new RigidBodySystem();
	_systems["ShotSystem"] = new ShotSystem();
	_systems["AnimatorSystem"] = new AnimatorSystem();
	_systems["BehaviorSystem"] = new BehaviorSystem();
}

void Engine::initScenes(void)
{
	try {
		boost::property_tree::ptree root;
		boost::property_tree::read_json("../src/game_engine/config/sceneConfig.json", root);

		for (boost::property_tree::ptree::value_type &elem : root.get_child("scene")) {
			_scenes.insert(std::make_pair(elem.second.data(), new Scene(elem.second.data())));
		}
	} catch (std::exception &exception) {
		std::cerr << "An error occured while getting the [Scene] config file please verify that the Scene.json file does exist in" << std::endl;
	}
}

int Engine::getNewID() {
	static int id = 0;

	std::cout << std::endl << "NEW FORM ID: " << id << std::endl;
	return id++;
}

void Engine::createEntity(const std::string & path) {
	const int id = getNewID();

	try {
		_entities.push_back(new Entity(path, id));
	} catch (std::exception &e) {
		std::cout << "classe not loaded" << std::endl;
	}
}

void Engine::deleteEntity(const int id) {
	// _availableIds.push(id);
}

void Engine::deleteEntity(void) {
}

Entity *Engine::getEntityByIP(const std::string &ip) {
	for (Entity *entity : _entities) {
		if (ip.compare(entity->getIP()) == 0) {
			return entity;
		}
	}
	return nullptr;
}

void Engine::start_send(void)
{
	std::cout << "ON ENVOIE PAS DE LA SATA NOSU ? " << _toSend << std::endl;
	if (_inGame == true) {
		game_socket_.send_to(boost::asio::buffer(_toSend), *game_endpoint_);
	} else
		socket_.send_to(boost::asio::buffer(_toSend), remote_endpoint_);
}

void Engine::start_receive(void)
{
	try {
		std::cout << "ON RECOIT PAS DE LA DATA NOSU?" << std::endl;
		recv_buffer_.fill('\0');
		if (_inGame != true) {
			std::cout << "NOT IN GAME" << std::endl;
			socket_.receive_from(boost::asio::buffer(recv_buffer_), remote_endpoint_);
		} else {
			std::cout << "IN GAME" << std::endl;
			game_socket_.receive_from(boost::asio::buffer(recv_buffer_), *game_endpoint_);
		}
		std::cout << "RESPONSE = " << recv_buffer_.c_array() << std::endl;
	} catch (std::exception & excep) {
		std::cout << excep.what() << std::endl;
	}
	handle_receive();
	start_receive();
}

void Engine::handle_receive(/* const boost::system::error_code& error, std::size_t bytes_transferred */)
{
    std::string answer;
    std::string addr = remote_endpoint_.address().to_string();

	std::cout << "Handle Receive" << std::endl;
	if (_toSend.empty() == true || _toSend.size() == 0) {
		recv_buffer_.fill('\0');
	}
	answer = recv_buffer_.c_array();
	std::vector<std::string> tab = Explode::explode(answer, ':');
	std::cout << "Received from [" + addr + "]: " << answer << std::endl;
	std::cout << _ip << ":SENDED MESSAGE: [" << _toSend << "]" << std::endl;
	if (answer.compare(0, 17, "Command not found") == 0) {
		_ip = answer.substr(18, -1);
		_ip.pop_back();
	} else if (_state[tab.at(0)] != nullptr && (this->*(_state[tab.at(0)]))(answer) == 0) {
		std::cout << "Executing state..." << std::endl;
		(this->*(_exec[tab.at(0)]))(answer);
	}
}

void Engine::run() {
	std::cout << "Run" << std::endl;
	_toSend = "600";
	start_send();
	static bool send = false;
	_win->createSprites(_entities);
	std::future<void> asyncThread = std::async(&Engine::start_receive, this);
	while (_win->isOpen()) {
		_win->clear();
		if (_win->events(_entities, getSystem<TransformSystem>("TransformSystem"), getSystem<ShotSystem>("ShotSystem"), _toSend, _gameStarted) == true) {
			std::cout << "event send" << std::endl;
			std::future<void> asy = std::async(&Engine::start_send, this);
		}
		if (_gameStarted == true) {
			_win->detectCollision(_entities, _systems);
			_win->displayBackground();
			_win->drawSprite(_entities, _systems, _isSending, _toSend);
		}
		if (_isSending == "true") {
			std::future<void> asy = std::async(&Engine::start_send, this);
			_isSending = "false";
		}
		_win->display();
	}
}

int Engine::addColorToPlayer(std::string &answer)
{
	std::string ipAddresses(answer.substr(6, -1));
	std::vector<std::string> addrs = Explode::explode(ipAddresses, ';');
	int isMe = -1;
	for (int a = 0; a != addrs.size(); a++) {
		for (Entity *entity : _entities) {
			if (_ip.compare(addrs[a]) == 0) {
				EventComponent *event = entity->getComponent<EventComponent>("Event");
				RenderComponent *render = entity->getComponent<RenderComponent>("Render");
				if (render != nullptr && event != nullptr) {
					Sprite *sprite = render->getSprite();
					sprite->setColor(a);
					isMe = a;
				}
			}
		}
	}
	return isMe;
}

void Engine::addPlayers(int isMe, std::string &answer)
{
	std::string ipAddresses(answer.substr(6, -1));
	std::vector<std::string> addrs = Explode::explode(ipAddresses, ';');
	for (int a = 0; a <= addrs.size() - 1; a++) {
		if (a != isMe) {
			_entities.push_back(new Entity("../src/game_engine/shots/non-player.json", Engine::getNewID()));
			RenderComponent *render = _entities.back()->getComponent<RenderComponent>("Render");
			_entities.back()->setIP(addrs[a]);
			if (render != nullptr) {
				Sprite *sprite = new Sprite(render->getPath());
				TransformComponent *transform = _entities.back()->getComponent<TransformComponent>("Transform");
				if (transform != nullptr) {
					transform->setPositions(10, 40 * a);
					sprite->setPositionSprite(transform->getPositions());
					sprite->setScaleSprite(transform->getScales());
				}
				render->setSprite(sprite);
			}
			AnimatorComponent *animator = _entities.back()->getComponent<AnimatorComponent>("Animator");
			if (render != nullptr && animator != nullptr) {
				Sprite *sprite = render->getSprite();
				sprite->setColor(a);
				int left = animator->getOrigin().first * animator->getRect().first + animator->getPadding().first;
				int top = animator->getOrigin().second * animator->getRect().second + animator->getPadding().second;
				sprite->setTextureRect(left, top, animator->getRect().first, animator->getRect().second);
			}
		}
	}
}

void Engine::execJoined(std::string & answer)
{
	std::cout << "Joined game " << answer << std::endl;
	_gamePort = 3001;
	std::cout << "Game port: " << _gamePort << std::endl;
	std::cout << "ADDR: " << _addr << std::endl;
	game_endpoint_ = new udp::endpoint(ip::address::from_string(_addr), _gamePort);
	_inGame = true;
	start_send();
}

void Engine::execCreation(std::string & answer)
{
	_win->createSprites(_entities);
	std::cout << "Game port: " << answer.substr(9, 4) << std::endl;
	_gamePort = std::stoi(answer.substr(9, 4));
	std::cout << "Addr: " << _addr << " => port to use: " << _gamePort << std::endl;
	game_endpoint_ = new udp::endpoint(ip::address::from_string(_addr), _gamePort);
	_inGame = true;
}

void Engine::execStarted(std::string & answer)
{
	_win->createSprites(_entities);
	std::cout << "============================" << std::endl;
	std::cout << answer << std::endl;
	if (answer.compare(0, 6, "start:") == 0) {
		int isMe = addColorToPlayer(answer);
		addPlayers(isMe, answer);
	}
	_win->createBackground();
	_gameStarted = true;
}

void Engine::execQuited(std::string & answer)
{
	std::cout << "Quited" << std::endl;
	_inGame = false;
	_gameStarted = false;
}

void Engine::execEnded(std::string & answer)
{
	std::cout << "Ended" << std::endl;
	_inGame = false;
	_gameStarted = false;
}

void Engine::execMoveUp(std::string &answer)
{
	std::vector<std::string> tab = Explode::explode(answer, ':');
	Entity *entity = getEntityByIP(tab.back().substr(0, tab.back().size() - 1));
	if (entity)
		getSystem<TransformSystem>("TransformSystem")->setMove(entity, 0, -200 * reinterpret_cast<SFMLDisplay *>(_win)->getTime().asSeconds());
	else
		std::cout << "NO ENTITY" << std::endl;
	std::cout << tab.back() << " moved " << tab.front() << std::endl;
}

void Engine::execMoveDown(std::string &answer)
{
	std::vector<std::string> tab = Explode::explode(answer, ':');
	Entity *entity = getEntityByIP(tab.back().substr(0, tab.back().size() - 1));
	if (entity)
		getSystem<TransformSystem>("TransformSystem")->setMove(entity, 0, 200 * reinterpret_cast<SFMLDisplay *>(_win)->getTime().asSeconds());
	std::cout << "Move Down" << std::endl;
}

void Engine::execMoveLeft(std::string &answer)
{
	std::vector<std::string> tab = Explode::explode(answer, ':');
	Entity *entity = getEntityByIP(tab.back().substr(0, tab.back().size() - 1));
	if (entity)
		getSystem<TransformSystem>("TransformSystem")->setMove(entity, -200 * reinterpret_cast<SFMLDisplay *>(_win)->getTime().asSeconds(), 0);
	std::cout << "Move Left" << std::endl;
}

void Engine::execMoveRight(std::string &answer)
{
	std::vector<std::string> tab = Explode::explode(answer, ':');
	Entity *entity = getEntityByIP(tab.back().substr(0, tab.back().size() - 1));
	if (entity)
		getSystem<TransformSystem>("TransformSystem")->setMove(entity, 200 * reinterpret_cast<SFMLDisplay *>(_win)->getTime().asSeconds(), 0);
	std::cout << "Move Right" << std::endl;
}

void Engine::execFire(std::string &answer)
{
	std::vector<std::string> tab = Explode::explode(answer, ':');
	Entity *entity = getEntityByIP(tab.back().substr(0, tab.back().size() - 1));
	if (entity) {
		Entity *shotEntity = getSystem<ShotSystem>("ShotSystem")->createShotEntity(entity);
		if (shotEntity != nullptr)
			_entities.push_back(shotEntity);
	    ShotComponent *shot = entity->getComponent<ShotComponent>("Shot");
		shot->setShotAvailable(true);
	}
	std::cout << "Move Right" << std::endl;
}