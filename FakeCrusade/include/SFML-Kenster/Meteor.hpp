#ifndef KENSTER_METEOR_HPP
#define KENSTER_METEOR_HPP

#include <SFML-Kenster/Entity.hpp>

namespace kenster
{
	class Meteor : public Entity
	{
		public:
			Meteor(const Meteor&) = delete;
			Meteor& operator=(const Meteor&) = delete;
			Meteor(Configuration::Textures text_id = Configuration::Textures::BigMeteor1);

		private:

			void update(sf::Time deltaTime);

			bool isCollide(const Entity& other)const;

			void onDestroy()const;
			
	};
}



#endif // !SFML_KENSTER_HPP