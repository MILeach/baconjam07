#include <SFML/Graphics.hpp>
#include "TileMap.h"

int main() {
    
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gaussm Bacon Jam");
    sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);

	TileMap map;
	TileSet tileSet;
	tileSet.addTexture("tile1.png");
	tileSet.addTexture("water.png");
	map.setTileSet(tileSet);
	map.loadFromFile("testmap.txt", window.getSize().x);

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
		map.drawToWindow(window);
        window.display();
    }

    return 0;
}
