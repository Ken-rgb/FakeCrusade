#include <SFML-Kenster/Entity.hpp>

#if MY_DEBUG == 1
#include <iostream>
#endif

namespace kenster
{
#if MY_DEBUG == 1
	Entity(const Entity&)
	{
		std::cout << "Copie construct Entity" << std::endl;
	}
#endif

	Entity::Entity(Configuration::Textures text_id) :
		_alive(true)
	{
		sf::Texture& texture = Configuration::textures.get(text_id);
		_sprite.setTexture(texture);
		_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
		//_velocity default (0,0)
	}

	const sf::Vector2f& Entity::getPosition()const
	{
		return _sprite.getPosition();
	}

	bool Entity::isAlive()const {
		return _alive;
	}

	void Entity::onDestroy() {
		_alive = false;
	}

	void Entity::draw(sf::RenderTarget& target, sf::RenderStates states)const
	{
		target.draw(_sprite, states);
	}

}