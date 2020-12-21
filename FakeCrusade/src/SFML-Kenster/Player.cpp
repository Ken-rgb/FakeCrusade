#include "SFML-Kenster/Player.hpp"
#include <cmath>
#include <corecrt_math_defines.h>

#include "SFML-Kenster/Configuration.hpp"
#include <SFML-Kenster/Collision.hpp>
#include <iostream>

namespace kenster
{
	Player::Player() : Entity(Configuration::Textures::Player)
		,ActionTarget(Configuration::playerInputs)
		, _is_moving(false)
		, _rotation(0)
	{

		bind(Configuration::PlayerInputs::Up, [this](const sf::Event&) {
			_is_moving = true;
		});

		bind(Configuration::PlayerInputs::Left, [this](const sf::Event&) {
			_rotation -= 1;
		});

		bind(Configuration::PlayerInputs::Right, [this](const sf::Event&) {
			_rotation += 1;
		});
	}

	void Player::processEvents()
	{
		_is_moving = false;
		_rotation = 0;
		ActionTarget::processEvents();
	}

	void Player::update(sf::Time deltaTime)
	{
		float seconds = deltaTime.asSeconds();

		if (_rotation != 0)
		{
			float angle = _rotation * 180 * seconds;
			_sprite.rotate(angle);
		}

		if (_is_moving)
		{
			float radiant = _sprite.getRotation() / 180 * M_PI;
			_velocity += sf::Vector2f(std::sin(radiant), -std::cos(radiant)) * 600.f * seconds;
		}
		else
		{
			_velocity = _velocity * static_cast<float>(0.999);	
		}

		_sprite.move(seconds * _velocity);
	}

	bool Player::isCollide(const Entity& other)const
	{
		return Collision::circleTest(_sprite, other._sprite);
	}

	void Player::onDestroy()const
	{
		Configuration::player = nullptr;
		Configuration::lives--;
	}
}
			