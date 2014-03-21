#include <SFML/Graphics.hpp>
#include "TileMap.h"

int main() {
    
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gaussm Bacon Jam");
    sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);

	TileMap map("testmap.txt");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
			switch (event.type) {

			case sf::Event::Closed:
                window.close();
				break;

			case sf::Event::KeyPressed:
				
				break;

			default:
				break;
			}
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
