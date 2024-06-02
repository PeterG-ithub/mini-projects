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
	window.draw(legBaseSprite);
}

void Body::move(float velocity, float& deltaTime)
{
	position.x += velocity * deltaTime;
	sprite.setPosition(position);
	std::cout << position.x << std::endl;
}

//Set leg base position relative to the position of body
void Body::setLegBasePosition(sf::Vector2f pos)
{
	legBasePos = position + pos;

	//Setup the sprite
	float radius = 10.0f;
	legBaseSprite.setRadius(radius);
	legBaseSprite.setOrigin(sf::Vector2f(radius, radius));
	legBaseSprite.setPosition(legBasePos);
	legBaseSprite.setFillColor(sf::Color::Magenta);
}

//Get leg base position relative to the window
sf::Vector2f Body::getLegBasePosition()
{
	return legBasePos;
}
