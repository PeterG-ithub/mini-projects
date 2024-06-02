#include "Environment.h"

void Environment::generateFlatGround(sf::Vector2f pos, sf::Vector2f size, sf::Color color)
{
	sprite.setPosition(pos);
	sprite.setSize(size);
	sprite.setFillColor(color);
}

void Environment::update(float& deltaTime)
{
}

void Environment::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
