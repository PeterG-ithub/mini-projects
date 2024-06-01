#include "Leg.h"

//Constructor
Leg::Leg(sf::Vector2f pos, float len, float thick, sf::Color col) :
	position(pos), length(len), thickness(thick), color(col)
{
	sprite.setPosition(position);
	sprite.setSize(sf::Vector2f(length, thickness));
	sprite.setFillColor(color);
}

void Leg::update(float& deltaTime)
{
}

void Leg::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
