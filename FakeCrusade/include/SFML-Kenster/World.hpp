#ifndef KENSTER_WORLD_HPP
#define KENSTER_WORLD_HPP

#include <vector>
#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML-Kenster/Configuration.hpp>


namespace kenster
{
	class Entity;
	class World : public sf::Drawable
	{
		public:
			World(const World&) = delete;
			World& operator = (const World&) = delete;

			World(float x, float y);

			void clear();

			void update(sf::Time deltaTime);
			void add(Entity* entity);
			void remove(int id);

#if MY_DEBUG == 1
			void show();
#endif


		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
			std::vector<Entity*> _entities;


			const int _max_size = 60; //number of Game-OBJ
			int _entity_last = -1;
			int _x;
			int _y;
			
	};
}

#endif // !KENSTER_WORLD_HPP
