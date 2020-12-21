#ifndef KENSTER_COLLISION_HPP
#define KENSTER_COLLISION_HPP

#include <SFML/Graphics.hpp> //sprite

namespace kenster
{
	class Collision
	{
		public:
			Collision(const Collision&) = delete;
			Collision& operator=(const Collision&) = delete;
			Collision() = delete;

			static bool circleTest(const sf::Sprite& first, const sf::Sprite& second);
			
	};
}

#endif // !KENSTER_COLLISION_HPP
