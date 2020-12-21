#ifndef KENSTER_GAME_HPP
#define KENSTER_GAME_HPP


#include "Kenster/Window.hpp"


namespace kenster
{
	class Game
	{
	public:
		//non copyable class
		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;

		Game(int X = 1600, int Y = 900); //< constructor

		void run(int minimum_frame_per_seconds = 60);

	private:

		void processEvents();//< Process events
		void update(sf::Time deltaTime); //< do some updates

		Window _window; //< the window use to display the game
	};
}

#endif

