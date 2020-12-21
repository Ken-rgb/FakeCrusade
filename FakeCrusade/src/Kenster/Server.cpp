#include "Kenster/Server.hpp"

#include <iostream>

namespace kenster
{
	Server::Server()
	{

	}

	void Server::open()
	{
		std::cout << "Start Server service" << std::endl;
		if (_listener.listen(3092) != sf::Socket::Done)
		{
			std::cout << "Error initiation port" << std::endl;
		}

		if (_listener.accept(_socket) == sf::Socket::Done)
		{
			std::cout << "New client connected: " << _socket.getRemoteAddress() << std::endl;
		}
		else 
		{
			std::cout << "client rejected" << std::endl;
		}
	}

}