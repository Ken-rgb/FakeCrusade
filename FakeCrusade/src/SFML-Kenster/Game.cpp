#include "SFML-Kenster\Game.hpp"

#include <SFML/Window.hpp>


namespace kenster
{
	
	//change this
	Game::Game(int X, int Y) : _window("02_Game_Archi")
	{
	}

	//this is perfect
	void Game::run(int minimum_frame_per_seconds)
	{
		sf::Clock clock;
		sf::Time timeSinceLastUpdate;
		sf::Time TimePerFrame = sf::seconds(1.f / minimum_frame_per_seconds);

		while (_window.isOpen())
		{
			processEvents();

			timeSinceLastUpdate = clock.restart();
			while (timeSinceLastUpdate > TimePerFrame)
			{
				timeSinceLastUpdate -= TimePerFrame;
				update(TimePerFrame);
			}

			update(timeSinceLastUpdate);
			_window.render();
		}
	}

	//change this, make a input manager
	void Game::processEvents()
	{
		//to store the events
		sf::Event event;
		//events loop
		while (_window.pollEvent(event))
		{
			_window.processEvent(event);
		}
	}


	void Game::update(sf::Time deltaTime)
	{
		_window.update(deltaTime);
	}
}