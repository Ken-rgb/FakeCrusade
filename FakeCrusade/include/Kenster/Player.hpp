#ifndef KENSTER_PLAYER_HPP
#define KENSTER_PLAYER_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

namespace kenster
{
	class Player : public sf::Drawable
	{
		public:
			Player(const Player&);
			Player& operator=(const Player&) = delete;
			Player();

			template<typename...Args>
			void setPosition(Args&& ... args);

			void controlInput(sf::RenderWindow& window);
			void update(sf::Time& delta_time);//finisch the player

		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

			sf::CircleShape		_body;
			sf::Vector2f		_destination_click /*= sf::Vector2f(200,300)*/;


	};
}


//template
#include <utility>

namespace kenster
{
	template<typename...Args>
	void Player::setPosition(Args&&... args)
	{
		_body.setPosition(std::forward<Args>(args)...);
		_destination_click = _body.getPosition();
	}
}

#endif // !KENSTER_PLAYER_HPP
