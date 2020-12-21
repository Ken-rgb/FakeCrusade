#include <SFML-Kenster/World.hpp>
#include <SFML-Kenster/Entity.hpp>

#include <SFML-Kenster/Player.hpp>
#include <iostream>
#include <winsock.h>
#if MY_DEBUG == 1
#endif

namespace kenster
{

	World::World(float x, float y) : _x(x), _y(y)
	{
		_entities.reserve(_max_size);

	}

	void World::clear()
	{
		for (Entity* entity : _entities)
		{
			delete entity;
		}
	}

	void World::update(sf::Time deltaTime)
	{
		for (Entity* entity : _entities)
		{
			entity->update(deltaTime);
			 //BOARDER CHeck
			sf::Vector2f pos = entity->getPosition();
			
				//boarder check for X-ordinate
			if (pos.x < 0)
			{
				pos.x = _x;
				pos.y = _y - pos.y;
			}
			else if (pos.x > _x)
			{
				pos.x = 0;
				pos.y = _y - pos.y;
			}

				//boarder check for Y-abscissa
			else if(pos.y < 0)
			{
				pos.x = _x - pos.x;
                pos.y = _y;
			}
			else if (pos.y > _y)
			{
				pos.x = _x - pos.x;
				pos.y = 0;
			}
			
			entity->setPosition(pos);
		}

		//COLLLISION
		for (int entity_first = 0; entity_first < _entity_last; entity_first++)
		{

			for (int entity_other = entity_first + 1; entity_other <= _entity_last; entity_other++)
			{
				if (_entities[entity_first]->isCollide(*_entities[entity_other]) &&
					_entities[entity_first]->isAlive())
				{
					_entities[entity_first]->onDestroy();
				}

				if (_entities[entity_other]->isCollide(*_entities[entity_first]) &&
					_entities[entity_other]->isAlive())
				{
					_entities[entity_other]->onDestroy();
				}
			}
		}

		//remove all dead Entitys, that collided
		for (int entity = 0; entity <= _entity_last; entity++)
		{
			if (!_entities[entity]->isAlive())
			{
				remove(entity);
				entity--; // after remove,  array got shorter 
			}
		} //somehow play is not nullptr after delete
	}

	void World::add(Entity* entity)
	{
		std::cout << "Entity has been added to index "<< _entities.size() << std::endl;
		_entities.emplace_back(entity);
		_entity_last++;
		std::cout << "_entity_last is :" << _entity_last << std::endl;
		std::cout << "entity_size is  >" << _entities.size() << std::endl;
	}

	void World::remove(int index)
	{
		std::swap(_entities[_entities.size()-1], _entities[index]);
		_entities[_entities.size() - 1] = nullptr;
		delete _entities[_entities.size() - 1];
		_entities.pop_back();
		_entity_last--;
		std::cout << "is removed got triggered" << std::endl;
		std::cout << "entity_size is  >" << _entities.size() << std::endl;
	}

#if MY_DEBUG == 1

	void World::show()
	{
		std::cout << "current world size is : "<< _entities.size() << std::endl;
	}
#endif

	void World::draw(sf::RenderTarget& target, sf::RenderStates states)const
	{
		for (Entity* entity : _entities)
		{
			target.draw(*entity, states);
		}
	}
}