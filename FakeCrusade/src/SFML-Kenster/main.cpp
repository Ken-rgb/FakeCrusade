
#include "SFML-Kenster/Game.hpp"

#ifdef KENSTER_DEBUG
#include <iostream>
#endif 

int main()
{

#ifdef KENSTER_DEBUG
	std::cout << "KENSTER_DEBUG - Mode is on" << std::endl;
#endif
	kenster::Game game;

	game.run();

	return 0;
}