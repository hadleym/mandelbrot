#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rectangle Drawer");
    sf::RectangleShape rectangle;
    sf::Vector2f startPos = sf::Vector2f(100, 200);
    sf::Vector2f endPos = sf::Vector2f(300,400);
    rectangle.setPosition(startPos);
    rectangle.setSize(endPos - startPos);
	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		window.draw(rectangle);
		window.display();
	}
	return 0;
}
	
