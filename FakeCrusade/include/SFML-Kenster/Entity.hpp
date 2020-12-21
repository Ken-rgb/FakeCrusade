#ifndef KENSTER_ENTITY_HPP
#define KENSTER_ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <SFML-Kenster/Configuration.hpp>

namespace kenster
{
	class Entity : public sf::Drawable
	{
		public:

#if MY_DEBUG == 1
			Entity(const Entity&);
#else
			Entity(const Entity&) = delete;
#endif
			Entity& operator= (const Entity&) = delete;
			Entity(Configuration::Textures text_id);

			//defined in Entity.cpp

			const sf::Vector2f& getPosition()const;
			template<typename ... Args>
			void setPosition(Args&& ... args);


			virtual void update(sf::Time deltaTime) = 0;
			virtual bool isCollide(const Entity& other)const = 0;

			virtual bool isAlive()const;
			virtual void onDestroy();

		protected:
			friend class Meteor;
			friend class Player;

			bool _alive;


		private:
			//defined in Entity.cpp
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
			sf::Sprite		_sprite;
			sf::Vector2f	_velocity;
	};
}

//template
#include <utility>

namespace kenster
{
	template<typename ... Args>
	void Entity::setPosition(Args&& ... args)
	{
		_sprite.setPosition(std::forward<Args>(args)...);
	}
}


#endif // !KENSTER_ENTITY_HPP
