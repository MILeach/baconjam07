#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Player.h"

int main() {
    
	sf::RenderWindow window(sf::VideoMode(800, 600), "Double Bacon Cheeseburglars");
    sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);

	TileMap map;
	TileSet tileSet;
	tileSet.addTexture("tile1.png", false);
	tileSet.addTexture("water.png", true);
	map.setTileSet(tileSet);
	map.loadFromFile("testmap.txt", window.getSize().x);

	Player player(sf::Vector2f(350.0f, 300.0f), "burger.png");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
			switch (event.type) {

			case sf::Event::Closed:
                window.close();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::W:
						player.setMovingUp(true);
						break;

					case sf::Keyboard::S:
						player.setMovingDown(true);
						break;

					case sf::Keyboard::D:
						player.setMovingRight(true);
						break;

					case sf::Keyboard::A:
						player.setMovingLeft(true);
						break;

					default:
						break;
				}
				break;

			case sf::Event::KeyReleased:
				switch (event.key.code) {
					case sf::Keyboard::W:
						player.setMovingUp(false);
						break;
					
					case sf::Keyboard::S:
						player.setMovingDown(false);
						break;

					case sf::Keyboard::D:
						player.setMovingRight(false);
						break;

					case sf::Keyboard::A:
						player.setMovingLeft(false);
						break;

					default:
						break;
				}
				break;

			default:
				break;
			}
        }

		player.update(map);
        window.clear();
		map.drawToWindow(window);
		window.draw(player);
        window.display();
    }

    return 0;
}
