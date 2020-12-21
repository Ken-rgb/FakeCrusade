#include <SFML-Kenster/Meteor.hpp>
#include <SFML-Kenster/random.hpp>
#include <SFML-Kenster/Collision.hpp>


namespace kenster
{
	Meteor::Meteor(Configuration::Textures text_id) : 
		Entity((Configuration::Textures)
			kenster::random(Configuration::Textures::BigMeteor1, Configuration::Textures::BigMeteor4))

	{
		_velocity = sf::Vector2f(100, 100);
	}

	void Meteor::update(sf::Time deltaTime)
	{
		float seconds = deltaTime.asSeconds();
		_sprite.move(seconds * _velocity);
	}

	bool Meteor::isCollide(const Entity& other)const
	{
		return Collision::circleTest(_sprite, other._sprite);
	}

	void Meteor::onDestroy()const
	{

	}
}