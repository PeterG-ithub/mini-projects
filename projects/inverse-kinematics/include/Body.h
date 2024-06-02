#pragma once
#include <SFML/Graphics.hpp>

class Body
{
public:
	Body(sf::Vector2f pos = sf::Vector2f(200.0f, 300.0f), float len = 250.0f, float wid = 200.0f, sf::Color col = sf::Color::Blue);
	void update(float& deltaTime);
	void draw(sf::RenderWindow& window);
private:
	float length;
	float width;
	float angle;
	sf::Color color;
	sf::RectangleShape sprite;
	sf::Vector2f position;
};

