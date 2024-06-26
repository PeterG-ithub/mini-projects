#include "Calc.h"

float Calc::angleV(sf::Vector2f& vector)
{
    return std::atan2(vector.y, vector.x) * 180 / M_PI;
}

sf::Vector2f Calc::normalize(sf::Vector2f& vector)
{
    // Calculate the magnitude of the vector
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    // Avoid division by zero
    if (magnitude != 0) {
        // Normalize the vector components
        return sf::Vector2f(vector.x / magnitude, vector.y / magnitude);
    }
    else {
        // Return a zero vector if the input vector has zero magnitude
        return sf::Vector2f(0.0f, 0.0f);
    }
}

float Calc::distance(sf::Vector2f& v1, sf::Vector2f& v2)
{
    float dx = v2.x - v1.x;
    float dy = v2.y - v1.y;
    return std::sqrt(dx * dx + dy * dy);
}
