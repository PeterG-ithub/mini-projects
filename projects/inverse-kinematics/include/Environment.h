#pragma once
#include <SFML/Graphics.hpp>
class Environment
{
public:
	void generateFlatGround(sf::Vector2f pos, sf::Vector2f size, sf::Color col);
	void update(float& deltaTime);
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape sprite;
};

