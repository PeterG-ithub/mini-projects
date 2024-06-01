#include <SFML/Graphics.hpp>
#include <iostream>
#include "Leg.h"
#include "Calc.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "SFML Window", sf::Style::Default);
    sf::Clock clock;    //Var for dt

    //Variable for FPS counter
    int frameCount = 0;    
    float elapsedTime = 0.0f;

    bool isButtonPressed = false;

    Leg leg1;
    Leg leg2;

    leg2.setColor(sf::Color::Red);
    leg2.rotate(90.0f);
    leg2.setPosition(leg1.getEndPos());
    float len = 100.0f;
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
                    sf::Vector2f mousePositionF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
                    std::cout << "Mouse Position: (" << localPosition.x << ", " << localPosition.y << ")" << std::endl;

                    //Inverse Kinematics trigger
                    float distance = Calc::distance(leg1.position, mousePositionF);
                    if (distance < 2.0f * len)
                    {

                        float angle = acos(distance / (2.0f * len));
                        std::cout << "Angle: " << angle << std::endl;

                        // Calculating the local end position
                        float x = len * cos(angle); // H * cos(ang) = x
                        float y = len * sin(angle); // H * sin(ang) = y
                        sf::Vector2f calculatedEndPos(leg1.position.x + x, leg1.position.y + y);
                        std::cout << "calculated Position: (" << calculatedEndPos.x << ", " << calculatedEndPos.y << ")" << std::endl;
                        leg2.setPosition(calculatedEndPos);
                        leg2.setEndPosition(mousePositionF);
                        leg1.setEndPosition(calculatedEndPos);
                    }
                    std::cout << "Distance: " << distance << std::endl;
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                isButtonPressed = false;
            }
        }
        //update
        

        //deltaTime
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        //FPS counter
        frameCount++;
        elapsedTime += dt;
        if (elapsedTime > 1.0f) {
            //std::cout << "FPS: " << frameCount/elapsedTime << std::endl;
            frameCount = 0;
            elapsedTime = 0.0f;
        }
        
        //update
        leg1.update(dt);
        leg2.update(dt);


        window.clear(sf::Color::White);
        leg1.draw(window);
        leg2.draw(window);
        window.display();
    }

    return 0;
}

