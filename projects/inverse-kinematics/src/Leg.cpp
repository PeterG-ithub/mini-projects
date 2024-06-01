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

//Rotate leg with pivot pos as pivot
void Leg::rotate(float angle) {
	sprite.setRotation(angle);
}

void Leg::setColor(sf::Color col)
{
	sprite.setFillColor(col);
}

//Find the angle needed to point at position
float Leg::angleTo(sf::Vector2f pos)
{
	sf::Vector2f position = sprite.getPosition();
	sf::Vector2f diffVector = pos - position; 
	sf::Vector2f normalizedVector = Calc::normalize(diffVector);
	float angle = Calc::angleV(normalizedVector);
	return angle;
}
