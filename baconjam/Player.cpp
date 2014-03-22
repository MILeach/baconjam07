#include "Player.h"
#include <cmath>

Player::Player() {
}

Player::Player(const sf::Vector2f& startPosition, const std::string& fileName) {
	sf::Texture texture;
	if (!texture.loadFromFile(fileName)) {
	} else {
		setTexture(texture);
	}
	setPosition(startPosition);
	movingUp 	= false;
	movingDown 	= false;
	movingLeft 	= false;
	movingRight 	= false;
}

Player::~Player() {
}


void Player::update(TileMap& map) {
	sf::Vector2f initialPosition = getPosition();

	sf::Vector2f velocity(0.0f, 0.0f);
	if (movingUp)
		velocity += sf::Vector2f(0.0f, -1.0f);
	if (movingDown)
		velocity += sf::Vector2f(0.0f, 1.0f);
	if (movingLeft)
		velocity += sf::Vector2f(-1.0f, 0.0f);
	if (movingRight)
		velocity += sf::Vector2f(1.0f, 0.0f);

	// Normalize velocity
	float scale = 1.0f;
	if (velocity.x != 0.0f && velocity.y != 0.0f)
		scale = sqrt(velocity.x*velocity.x + velocity.y*velocity.y);
	velocity /= scale;
	move(velocity);

	// Check if we are colliding
	std::vector<std::vector<Tile>> tiles = map.getTiles();
	// Convert position to tile numbers
	sf::Vector2f newPosition = getPosition();
	// TODO: get rid of magic constant
	int tilex = floor(newPosition.x+10)/32;
	int tiley = floor(newPosition.y+10)/32;
	if (tiles[tiley][tilex].isSolid())
		setPosition(initialPosition);
}

void Player::setMovingUp	(const bool& moving) {
	movingUp = moving;
}

void Player::setMovingDown	(const bool& moving) {
	movingDown = moving;
}

void Player::setMovingLeft	(const bool& moving) {
	movingLeft = moving;
}

void Player::setMovingRight	(const bool& moving) {
	movingRight = moving;
}

