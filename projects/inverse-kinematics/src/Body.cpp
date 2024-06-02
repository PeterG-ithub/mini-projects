#include "Body.h"

Body::Body(sf::Vector2f pos, float len, float wid, sf::Color col)
{
	sprite.setPosition(pos);
	position = pos;
	sprite.setSize(sf::Vector2f(len, wid));
	sprite.setFillColor(col);
}

void Body::update(float& deltaTime)
{
	sprite.setPosition(position);
}

void Body::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Body::move(float velocity, float& deltaTime)
{
	position.x += velocity * deltaTime;
	sprite.setPosition(position);
	std::cout << position.x << std::endl;
}