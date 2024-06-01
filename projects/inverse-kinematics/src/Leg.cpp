#include "Leg.h"
#include <iostream>
//Constructor
Leg::Leg(sf::Vector2f pos, float len, float thick, sf::Color col) :
	position(pos), length(len), thickness(thick), color(col)
{
	setPosition(position);
	sprite.setOrigin(sf::Vector2f(0, thickness / 2.0f));
	sprite.setSize(sf::Vector2f(length, thickness));
	sprite.setFillColor(color);
	angle = 0.0f;
	endPos = sf::Vector2f(position.x + length, position.y);
}

void Leg::update(float& deltaTime)
{
}

void Leg::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

//Rotate leg with pivot pos as pivot
void Leg::rotate(float ang) {
	angle = ang;
	sprite.setRotation(ang);
	updateEndPos();
}

void Leg::setColor(sf::Color col)
{
	sprite.setFillColor(col);
}

void Leg::setPosition(sf::Vector2f pos)
{
	position = pos;
	sprite.setPosition(position);
}

void Leg::setEndPosition(sf::Vector2f pos)
{
	endPos = pos;
	angle = angleTo(pos);
	rotate(angle);
	updateEndPos();
}

sf::Vector2f Leg::getEndPos()
{
	return endPos;
}

//Update end position base on angle of leg
void Leg::updateEndPos()
{
	sf::Vector2f origin = sprite.getOrigin();
	float angleRadians = angle * M_PI / 180.0f;
	float x = length * cos(angleRadians); // H * cos(ang) = x
	float y = length * sin(angleRadians); // H * sin(ang) = y
	//std::cout << "x, y: (" << x << ", " << y << ")" << std::endl;
	endPos = sf::Vector2f(position.x + x, position.y + y);
	//std::cout << "End Position: (" << endPos.x << ", " << endPos.y << ")" << std::endl;
}


//Find the angle needed to point at position
float Leg::angleTo(sf::Vector2f pos)
{
	sf::Vector2f position = sprite.getPosition();
	sf::Vector2f diffVector = pos - position; 
	float angle = Calc::angleV(diffVector);
	return angle;
}
