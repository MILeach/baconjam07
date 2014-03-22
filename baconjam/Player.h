#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include <string>

#include "TileMap.h"

class Player : public sf::Sprite {
	public:
		Player();
		Player(const sf::Vector2f& startPosition, const std::string& fileName);
		~Player();
		void update(TileMap& map, float frameTime);
		void setMovingUp	(const bool& moving);
		void setMovingDown	(const bool& moving);
		void setMovingLeft	(const bool& moving);
		void setMovingRight	(const bool& moving);	

	private:
		bool movingUp, movingDown, movingLeft, movingRight;
		sf::Texture texture;
		float speed;
};

#endif
