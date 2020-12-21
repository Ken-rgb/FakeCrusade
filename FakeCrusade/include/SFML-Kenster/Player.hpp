#ifndef KENSTER_PLAYER_HPP
#define KENSTER_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML-Kenster/ActionTarget.hpp>
#include <SFML-Kenster/Entity.hpp>

namespace kenster
{
	class Player : public Entity, public ActionTarget<int>
	{
	public:
		Player(const Player&) = delete;
		Player& operator=(const Player&) = delete;

		Player();


		void processEvents();

		void update(sf::Time deltaTime);

		bool isCollide(const Entity& other) const;

		void onDestroy() const;

	private:

		bool _is_moving;
		int _rotation;

	};
}


#endif // !KENSTER_PLAYER_HPP
