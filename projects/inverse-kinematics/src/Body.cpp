#include "Body.h"

Body::Body(sf::Vector2f pos, float len, float wid, sf::Color col)
{
	sprite.setPosition(pos);
	sprite.setSize(sf::Vector2f(len, wid));
	sprite.setFillColor(col);
}

void Body::update(float& deltaTime)
{
}

void Body::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
