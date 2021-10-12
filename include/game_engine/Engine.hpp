/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <queue>
#include <map>
#include <utility>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/thread.hpp>
#include <future>
#include "HealthSystem.hpp"
#include "TransformSystem.hpp"
#include "RenderSystem.hpp"
#include "RigidBodySystem.hpp"
#include "ShotSystem.hpp"
#include "AnimatorSystem.hpp"
#include "Entity.hpp"
#include "DirFiles.hpp"
#include "ISystem.hpp"
#include "SFMLDisplay.hpp"
#include "Scene.hpp"
#include "BehaviorSystem.hpp"

using namespace boost::asio;
using ip::udp;

class Engine {
	public:
		Engine(char *addr, char *port, boost::asio::io_service &io_service);
		~Engine();

	public: // Entity
		void createEntity(const std::string &path);
		void deleteEntity(const int id);
		void deleteEntity(void);

		void initStates(void);
		void initExecs(void);
		void initSystems(void);
		void initScenes(void);

		template <typename T>
		T *getSystem(const std::string &sys) { return dynamic_cast<T *>(_systems[sys]); }

		std::vector<Entity *> getEntities() const { return _entities; }

		static int getNewID();

		std::string getIP() const { return _ip; };

		Entity *getEntityByIP(const std::string &);
		void	run();

	private:
		void try_sending(udp::socket & socket, udp::endpoint & end);
		int isCreation(std::string & recv) { return recv.compare(0, 8, "creation"); }
		int isStarted(std::string & recv) { return recv.compare(0, 5, "start"); }
		int isJoined(std::string & recv) { return recv.compare(0, 6, "player"); }
		int isQuited(std::string & recv) { return recv.compare(0, 4, "quit"); }
		int isEnded(std::string & recv) { return recv.compare(0, 3, "end"); }
		int isMoveUp(std::string & recv) { return recv.compare(0, 2, "up"); }
		int isMoveDown(std::string & recv) { return recv.compare(0, 4, "down"); }
		int isMoveLeft(std::string & recv) { return recv.compare(0, 4, "left"); }
		int isMoveRight(std::string & recv) { return recv.compare(0, 5, "right"); }
		int isFire(std::string & recv) { return recv.compare(0, 4, "fire"); }

	private:
		void execCreation(std::string &);
		void execStarted(std::string &);
		void execJoined(std::string &);
		void execQuited(std::string &);
		void execEnded(std::string &);
		void execMoveUp(std::string &);
		void execMoveDown(std::string &);
		void execMoveLeft(std::string &);
		void execMoveRight(std::string &);
		void execFire(std::string &);

	public:
		void start_receive2(udp::socket & socket, udp::endpoint & end);
		void handle_receive2(const boost::system::error_code& error, std::size_t bytes_transferred);

	private:
		void start_send(void);
		void start_receive(void);
		void handle_receive(/* const boost::system::error_code& error, std::size_t bytes_transferred */);
		void handle_send(std::string & line, const boost::system::error_code& error, std::size_t bytes_transferred);

	private:
		int addColorToPlayer(std::string &answer);
		void addPlayers(int isMe, std::string &answer);

	private:
		int							_port;
		int							_gamePort;
		int							_i;
		bool						_isListening;
		bool						_inGame;
		bool						_gameStarted;
		std::string					_toSend;
		std::string					_addr;
		std::string					_ip;
		std::string					_isSending;

		udp::socket 				socket_;
		udp::socket 				game_socket_;
		udp::endpoint 				remote_endpoint_;
		udp::endpoint 				*game_endpoint_;
		boost::array<char, 100> 	recv_buffer_;
		std::map <std::string, int (Engine::*)(std::string &)> 	_state;
		std::map <std::string, void (Engine::*)(std::string &)> _exec;

		IDisplay *_win;
		std::string _currentScene;
		std::vector<Entity *> _entities;
		std::map<std::string, Scene *> _scenes;
		std::map<std::string, ISystem *> _systems;
};

#endif /* !ENGINE_HPP_ */
