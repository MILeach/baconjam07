#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TileMap.h"
#include "Player.h"
#include "CheeseBurglar.h"
#include "KetchupPickup.h"
#include "KetchupPuddle.h"

int main() {

    
	sf::RenderWindow window(sf::VideoMode(800, 600), "Double Bacon Cheeseburglars");
	sf::Clock clock;
	unsigned long int score = 0;
	float scoreTimer = 0.0f;

	std::vector<CheeseBurglar> cheeseBurglars;
	sf::Texture cbTexture;
	cbTexture.loadFromFile("cheeseburglar.png");

	CheeseBurglar testcb;
	testcb.setTexture(cbTexture);
	testcb.setPosition(100, 100);
	cheeseBurglars.push_back(testcb);

	std::vector<KetchupPickup> ketchupPickups;
	sf::Texture ketchupPickupTexture;
	ketchupPickupTexture.loadFromFile("ketchupbottle.png");

	KetchupPickup testkp;
	testkp.setTexture(ketchupPickupTexture);
	testkp.setPosition(600, 500);
	ketchupPickups.push_back(testkp);

	sf::Font font;
	font.loadFromFile("District.ttf");
	sf::Text ketchupRemainingText;
	ketchupRemainingText.setFont(font);
	ketchupRemainingText.setString("Ketchup remaining: 5");
	ketchupRemainingText.setCharacterSize(24);
	ketchupRemainingText.setColor(sf::Color::White);
	ketchupRemainingText.setPosition(500, 0);

	sf::SoundBuffer buffer;
	buffer.loadFromFile("ketchupsound.wav");
	sf::Sound ketchupSound;
	ketchupSound.setBuffer(buffer);

	sf::Text pointsText;
	pointsText.setFont(font);
	pointsText.setString("Points: 0");
	pointsText.setCharacterSize(24);
	pointsText.setColor(sf::Color::White);
	pointsText.setPosition(38, 0);

	const int MAX_KETCHUPS = 5;
	int ketchups = MAX_KETCHUPS;
	std::vector<KetchupPuddle> ketchup;
	sf::Texture ketchupTexture;
	ketchupTexture.loadFromFile("ketchup.png");
		
	TileMap map;
	TileSet tileSet;
	tileSet.addTexture("floortile.png", false);
	tileSet.addTexture("wall.png", true);
	tileSet.addTexture("wetsign.png", true);
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

					case sf::Keyboard::Space:
						if (ketchups > 0) {
							ketchup.emplace_back();
							ketchup.back().setPosition(player.getPosition().x + 25, player.getPosition().y + 16);
							ketchup.back().setTexture(ketchupTexture);
							ketchup.back().setOrigin(16, 16);
							ketchup.back().scale(0.1f, 0.1f);
							ketchups -= 1;
							ketchupSound.play();
							sf::String kt = "Ketchup remaining: " + std::to_string(ketchups);
							ketchupRemainingText.setString(kt);
						}
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
	float frameTime = clock.restart().asSeconds();
	scoreTimer += frameTime;
	if(scoreTimer > 0.05f) {
		score += (1+ketchups)*5;
		scoreTimer -= 0.05f;
		sf::String scoreText = "Points: " + std::to_string(score);
		pointsText.setString(scoreText);
	}

		// Remove cheeseburglars who were marked last frame
	cheeseBurglars.erase(std::remove_if(std::begin(cheeseBurglars), std::end(cheeseBurglars), [] (CheeseBurglar& c) { return c.isMarkedForRemoval(); }), std::end(cheeseBurglars));
		player.update(map, frameTime);
		for (auto &cb : cheeseBurglars) {
			// Calculate nearest target
			sf::Vector2f nearest = player.getPosition();
			sf::Vector2f diff = cb.getPosition() - player.getPosition();
			float diffsize = diff.x*diff.x + diff.y*diff.y;
			for (auto &k : ketchup) {
				sf::Vector2f kdiff = cb.getPosition() - k.getPosition();
				kdiff.x += 16;
				kdiff.y += 25;
				float kdiffsize = kdiff.x*kdiff.x + kdiff.y*kdiff.y;
				if (kdiffsize <= diffsize) {
					diffsize = kdiffsize;
					nearest  = k.getPosition();
					if (kdiffsize < 400)
						k.startCountdown();
				}
			}
			
			cb.update(sf::Vector2f(nearest.x-16, nearest.y-25), frameTime);
			// Check if the player has been caught
			diff = cb.getPosition() - player.getPosition();
			if ((diff.x*diff.x + diff.y*diff.y) < 30)
				player.setPosition(0, 0);
			
		}
		for (auto &k : ketchup) {
			if (k.getScale().x < 1.0f)
			k.scale(1.1f, 1.1f);
			// Ketchup puddle has been eaten
			k.update(frameTime);
			if (k.isFinished()) {
				// Remove nearby cheeseburglars
				for (auto &cb : cheeseBurglars) {
					sf::Vector2f kdiff = cb.getPosition() - k.getPosition();
					kdiff.x += 16;
					kdiff.y += 25;
					float kdiffsize = kdiff.x*kdiff.x + kdiff.y*kdiff.y;
					if (kdiffsize < 400)
						cb.markForRemoval();	
				}	
			}
		}
		for (auto &kp : ketchupPickups) {
			sf::Vector2f playerPos = player.getPosition();
			playerPos.x += 25;
			playerPos.y += 16;
			sf::Vector2f kpPos = kp.getPosition();
			kpPos.x += 8;
			kpPos.y += 12;	
			if (ketchups < 5 && ((playerPos.x-kpPos.x)*(playerPos.x-kpPos.x) + (playerPos.y-kpPos.y)*(playerPos.y-kpPos.y)) < 400) {
				ketchups += 1;
				score += 25;
				sf::String kt = "Ketchup remaining: " + std::to_string(ketchups);
				ketchupRemainingText.setString(kt);
				kp.setPosition(-30.0f, -30.0f);
		}
		}

		// Spawn new ketchup bottles
		if (rand() % 1000 > 996) {
			KetchupPickup testkp;
			testkp.setTexture(ketchupPickupTexture);
			testkp.setPosition(50+rand()%700, 50+rand()%500);
			ketchupPickups.push_back(testkp);
		}

        window.clear();
		map.drawToWindow(window);
		for (auto k : ketchup) {
			window.draw(k);
		}
		for (auto kp : ketchupPickups) {
			window.draw(kp);
		}
		for (auto cb : cheeseBurglars) {
			window.draw(cb);
		}
		window.draw(player);
		window.draw(ketchupRemainingText);
		window.draw(pointsText);
        window.display();
    }
	ketchupSound.stop();
    return 0;
}
