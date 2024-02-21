#include <SFML/Graphics.hpp>
#include <iostream>

bool isRedCircle = false;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Circle Drawer");
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Blue);
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
                    isRedCircle = !isRedCircle;
                }
            }
        }

        if (drawing)
        {
            endPos = sf::Vector2f(sf::Mouse::getPosition(window));
        }

        if (isRedCircle)
            circle.setFillColor(sf::Color::Red);
        else
            circle.setFillColor(sf::Color::Blue);

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}


 flip() {

}
