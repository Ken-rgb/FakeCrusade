

#include "Kenster/Player.hpp"
#include "Kenster/KenMath.hpp"

#include <iostream>

namespace kenster
{

	Player::Player() 
	{
		sf::CircleShape player;
		_body.setFillColor(sf::Color::White);
		_body.setRadius(30);
		_body.setPosition(200, 300);
		sf::FloatRect bounds = _body.getGlobalBounds();
		_body.setOrigin(bounds.width/2, bounds.height/2); // this bullshit dont work always (0,0)
	}

	Player::Player(const Player& player) : _body(player._body)
	{
		std::cout << "Player copy constuctur created" << std::endl;
		std::cout << "destination_click copy :" << _destination_click.x << "\t " << _destination_click.y << std::endl;
	}

	void Player::controlInput(sf::RenderWindow& window) // click and move Object
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && window.hasFocus())
		{
			_destination_click = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
			std::cout << _destination_click.x << "\t " << _destination_click.y << std::endl;
		}
	}

	bool notDone = true;
	void Player::update(sf::Time& delta_time)
	{
		if (notDone)
		{
			_destination_click = sf::Vector2f(200.f, 300.f);
			std::cout << "destination_click done :" << _destination_click.x << "\t " << _destination_click.y << std::endl;
			notDone = false;
		}
		sf::Vector2f current_position = _body.getPosition();
		float distance = KenMath::distance(current_position, _destination_click);
		if (distance > 1.f)
		{
			//std::cout << _destination_click.x << "\t " << _destination_click.y << std::endl;
			float seconds = delta_time.asSeconds();
			sf::Vector2f direction = (_destination_click - current_position)/distance;
			sf::Vector2f new_position = _body.getPosition() + direction * 300.f * seconds;
			_body.setPosition(new_position);
		}
	}

	void Player::draw(sf::RenderTarget& target, sf::RenderStates states)const
	{
		target.draw(_body,states);
	}
}