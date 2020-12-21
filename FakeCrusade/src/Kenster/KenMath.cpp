#include "Kenster/KenMath.hpp"

namespace kenster
{
	
	sf::Vector2f KenMath::pow(sf::Vector2f& vector, int exponent)
	{

		return sf::Vector2f(std::pow(vector.x, exponent), std::pow(vector.y, exponent));
	}

	float KenMath::distance(sf::Vector2f& vector, sf::Vector2f& other)
	{
		sf::Vector2f some_value = other - vector;
		sf::Vector2f powed = pow(some_value, 2);
		float distance = std::sqrt(powed.x + powed.y);
		return distance;
	}
}