#ifndef KENSTER_WINDOW_HPP
#define KENSTER_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include <SFML/Window/Event.hpp>

#include "Kenster/TextButton.hpp"
#include "Kenster/DisplayState.hpp"
#include "Kenster/GameWorld.hpp"

namespace kenster
{
	class Window
	{
		public:
			Window(const Window&) = delete;
			Window& operator=(const Window&) = delete;

			Window(const std::string& name);

			//my own function
			void inputCases(const sf::Event& event);
			void processEvent(sf::Event& event);
			void update(sf::Time deltaTime);
			void render();

			//standard function
			bool isOpen();
			bool pollEvent(sf::Event& event);

			//might delete later and create own class
			void openServer();


		private:
			sf::RenderWindow _window;

			enum Status
			{
				StatusMenu,
				StatusGameworld,
				StatusHost
			};

			Status _status;
			DisplayState _menu;
			DisplayState _host;
			GameWorld _gameworld; // compared to "DisplayState" is has update

			//might delete later and create own class

	};
}

#endif // !KENSTER_WINDOW_HPP
