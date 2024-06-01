#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "SFML Window", sf::Style::Default);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Clock clock;
    int frameCount = 0;
    float elapsedTime = 0.0f;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        frameCount++;
        elapsedTime += dt;
        if (elapsedTime > 1.0f) {
            std::cout << "FPS: " << frameCount/elapsedTime << std::endl;
            frameCount = 0;
            elapsedTime = 0.0f;
        }
        

        window.clear(sf::Color::White);
        window.draw(shape);
        window.display();
    }

    return 0;
}

