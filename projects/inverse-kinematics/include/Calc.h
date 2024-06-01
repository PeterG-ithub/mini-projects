#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

# define M_PI           3.14159265358979323846  /* pi */

class Calc
{
public:
	static float angleV(sf::Vector2f& vector);
	static sf::Vector2f normalize(sf::Vector2f& vector);
	static float distance(sf::Vector2f& v1, sf::Vector2f& v2);
};

