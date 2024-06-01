#include <SFML/Graphics.hpp>
#include <iostream>
#include "Leg.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "SFML Window", sf::Style::Default);
    sf::Clock clock;    //Var for dt

    //Variable for FPS counter
    int frameCount = 0;    
    float elapsedTime = 0.0f;

    bool isButtonPressed = true;

    Leg leg2;
    Leg leg1;
    leg1.setColor(sf::Color::Red);
    leg1.rotate(21.7f);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (!isButtonPressed)
                {
                    isButtonPressed = true;
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    float angle = leg2.angleTo(sf::Vector2f(localPosition));
                    std::cout << angle << std::endl;
                    leg2.rotate(angle);
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                isButtonPressed = false;
            }
        }


        //deltaTime
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        //FPS counter
        frameCount++;
        elapsedTime += dt;
        if (elapsedTime > 1.0f) {
            std::cout << "FPS: " << frameCount/elapsedTime << std::endl;
            frameCount = 0;
            elapsedTime = 0.0f;
        }
        


        window.clear(sf::Color::White);
        leg2.draw(window);
        leg1.draw(window);
        window.display();
    }

    return 0;
}

