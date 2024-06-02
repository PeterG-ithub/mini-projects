#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Body
{
public:
	Body(sf::Vector2f pos = sf::Vector2f(200.0f, 300.0f), float len = 250.0f, float wid = 200.0f, sf::Color col = sf::Color::Blue);
	void update(float& deltaTime);
	void draw(sf::RenderWindow& window);
	void move(float velocity, float& deltaTime);
	void setLegBasePosition(sf::Vector2f pos);
	sf::Vector2f getLegBasePosition();
private:
	sf::RectangleShape sprite;
	sf::CircleShape legBaseSprite;
	sf::Vector2f position;
	sf::Vector2f legBasePos;
};

