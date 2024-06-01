#pragma once

#include <SFML/Graphics.hpp>
class Leg
{
public:

	Leg(sf::Vector2f pos = sf::Vector2f(500.0f, 300.0f), float len = 100.0f, float thick = 10.0f, sf::Color col = sf::Color::Black);

	sf::Vector2f position;
	void update(float& deltaTime);
	void draw(sf::RenderWindow& window);
private:
	float length;
	float thickness;
	sf::Color color;
	sf::RectangleShape sprite;
};

