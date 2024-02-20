#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rectangle Drawer");
    sf::RectangleShape rectangle;
    sf::Vector2f startPos;
    sf::Vector2f endPos;
    bool drawing = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    startPos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    drawing = true;
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    endPos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    drawing = false;
                    std::cout << "Rectangle dimensions: " << startPos.x << "," << startPos.y << ","
                              << endPos.x << "," << endPos.y << std::endl;
                }
            }
        }

        if (drawing)
        {
            endPos = sf::Vector2f(sf::Mouse::getPosition(window));
        }

        rectangle.setPosition(startPos);
        rectangle.setSize(endPos - startPos);

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}

