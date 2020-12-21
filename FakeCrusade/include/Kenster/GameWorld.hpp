#ifndef KENSTER_GAMEWORLD_HPP
#define KENSTER_GAMEWORLD_HPP

#include <SFML/Graphics.hpp>

#include "Kenster/Dataholder.hpp"
#include "Kenster/Player.hpp"

namespace kenster
{
	class GameWorld : public sf::Drawable
	{
	public:
		GameWorld(const GameWorld&) = delete;
		GameWorld& operator=(const GameWorld&) = delete;

		GameWorld(sf::RenderWindow& window);

		void controlInput();

		void update(sf::Time& delta_time);



	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

		Dataholder<Player>		_entities; //integrate the world

		sf::RectangleShape		_rect;
		sf::RenderWindow&		_window;

		Player					_player;

	};
}

#endif // !KENSTER_GAMEWORLD_HPP
