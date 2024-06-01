#pragma once

#include <SFML/Graphics.hpp>
#include "Calc.h"

class Leg
{
public:

	Leg(sf::Vector2f pos = sf::Vector2f(500.0f, 300.0f), float len = 100.0f, float thick = 10.0f, sf::Color col = sf::Color::Black);

	sf::Vector2f position;
	
	void update(float& deltaTime);
	void draw(sf::RenderWindow& window);
	void rotate(float angle);
	void setColor(sf::Color col);
	void setPosition(sf::Vector2f pos);
	void updateEndPos();
	sf::Vector2f getEndPos();
	float angleTo(sf::Vector2f pos);
private:
	float length;
	float thickness;
	float angle;
	sf::Color color;
	sf::RectangleShape sprite;
	sf::Vector2f endPos;
};

