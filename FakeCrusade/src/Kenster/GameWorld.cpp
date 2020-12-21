


#include "Kenster/GameWorld.hpp"
#include "Kenster/Setting.hpp"

namespace kenster
{
	GameWorld::GameWorld(sf::RenderWindow& window) : _entities(2), _window(window)
	{
		_rect.setFillColor(sf::Color::Red);
		_rect.setSize(sf::Vector2f(200,300));
		_rect.setPosition(setting::resolutionX/2, setting::resolutionY/2);
		

		_player.setPosition(200, 300);
		_entities.add(_player);
		

		//sf::CircleShape white_circle = sf::CircleShape(30);
		//white_circle.setPosition(200, 300);
		//_entities.add(white_circle);
	}

	void GameWorld::controlInput()
	{
		for (int i = 0; i < _entities.getLength(); i++)
		{
			_entities[i].controlInput(_window);
		}
	}

	void GameWorld::update(sf::Time& delta_time)
	{
		for (int i = 0; i < _entities.getLength(); i++)
		{
			_entities[i].update(delta_time);
		}
	}

	void GameWorld::draw(sf::RenderTarget& target, sf::RenderStates states)const
	{
		target.draw(_rect, states);
		
		for (int i = 0; i < _entities.getLength(); i++)
		{
			target.draw(_entities[i], states);
		}
	}
}