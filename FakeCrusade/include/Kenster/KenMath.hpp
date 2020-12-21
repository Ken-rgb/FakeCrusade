#ifndef KENSTER_MATH_HPP
#define KENSTER_MATH_HPP

#include <cmath>
#include <SFML/System/Vector2.hpp>

namespace kenster
{
	class KenMath
	{
	public:
		KenMath() = delete;
		KenMath(const KenMath&) = delete;
		KenMath& operator=(const KenMath&) = delete;

		static sf::Vector2f pow(sf::Vector2f& vector, int exponent);

		static float distance(sf::Vector2f& vector, sf::Vector2f& other);
	};
}

#endif // !KENSTER_MATH_HPP
