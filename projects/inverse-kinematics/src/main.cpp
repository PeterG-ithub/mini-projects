#include <SFML/Graphics.hpp>
#include <iostream>
#include "Leg.h"
#include "Body.h"
#include "Calc.h"
#include "Environment.h"
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
    Body bod;
    Environment env;
    env.generateFlatGround(sf::Vector2f(0.0f, 650.0f), sf::Vector2f(1300.0f, 80.0f), sf::Color::Green);
    bod.setLegBasePosition(sf::Vector2f(100.0f, 180.0f));
    leg1.setPosition(bod.getLegBasePosition());
    leg2.setColor(sf::Color::Red);
    leg2.setPosition(leg1.getEndPos());
    float len = 100.0f;
    while (window.isOpen())
    {
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
                    sf::Vector2f targetPosition(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
                    sf::Vector2f basePosition(leg1.position);
                    //std::cout << "target Position: (" << targetPosition.x << ", " << targetPosition.y << ")" << std::endl;
                    //std::cout << "Base Position: (" << basePosition.x << ", " << basePosition.y << ")" << std::endl;
                    //Inverse Kinematics trigger
                    float distance = Calc::distance(basePosition, targetPosition);
                    if (distance < 2.0f * len)
                    {
                        float l1 = leg1.getLength();
                        float l2 = leg2.getLength();
                        float x = targetPosition.x - basePosition.x;
                        float y = -(targetPosition.y - basePosition.y);
                        std::cout << "(x: " << x << ", y: " << y << ")" << std::endl;

                        //ARC TAN from WHERE? idk, but this fixes things // maybe we can use atan2 //check for later
                        float eTan = 0.0f;
                        if (x < 0) 
                            eTan = M_PI + atan(y / x);
                        else
                            eTan = atan(y / x);
                        std::cout << "Tan: " << eTan << std::endl;

                        //EQ 1
                        float test = ((l1 * l1) + (x * x) + (y * y) - (l2 * l2)) / (2.0f * l1 * std::sqrt(x * x + y * y));
                        float angle1 = acos(test) + eTan;
                        float angle1D = angle1 * 180.0f / M_PI;
                        if (angle1D > 180.0f)
                            angle1D = angle1D - 360.0f;
                        std::cout << "Angle 1: " << angle1D << std::endl;
                        //EQ 2
                        float angle2 = acos((l1 * l1 + l2 * l2 - (x*x + y*y)) / (2.0f * l1 * l2));
                        float angle2D = angle2 * 180.0f / M_PI;

                        std::cout << "Angle 2: " << angle2D << std::endl;
                        leg1.rotate(angle1D);
                        leg2.setPosition(leg1.getEndPos());

                        //calculating the angle relative to the X axis of leg2
                        float theAngle = 180.0f - (angle1D + angle2D);
                        if (theAngle > 180.0f)
                            theAngle = theAngle - 360.0f;

                        std::cout << "The Angle: " << theAngle << std::endl;
                        leg2.rotate(-theAngle); // F = 180 - angle1 + angle2
                    }
                    std::cout << "Distance: " << distance << std::endl;
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                isButtonPressed = false;
            }
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            // left key is pressed: move our character
            std::cout << "position.x" << std::endl;
            bod.move(100.0f, dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            // left key is pressed: move our character
            std::cout << "position.x" << std::endl;
            bod.move(-100.0f, dt);
        }
        //update
        leg1.update(dt);
        leg2.update(dt);


        window.clear(sf::Color::White);
        bod.draw(window);
        env.draw(window);
        leg1.draw(window);
        leg2.draw(window);
        window.display();
    }

    return 0;
}

