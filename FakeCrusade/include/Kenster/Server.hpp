#ifndef KENSTER_SERVER_HPP
#define KENSTER_SERVER_HPP

#include <SFML/Network.hpp>

namespace kenster
{
	class Server
	{
	public:
		Server(const Server&) = delete;
		Server& operator=(const Server&) = delete;

		Server();

		void open();


	private:
		sf::TcpListener		_listener;
		sf::TcpSocket		_socket;
	};
}


#endif // !KENSTER_SERVER_HPP
