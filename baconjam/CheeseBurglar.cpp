#include "CheeseBurglar.h"
#include <cmath>
#include <SFML/Graphics.hpp>

CheeseBurglar::CheeseBurglar() {
}

CheeseBurglar::~CheeseBurglar() {
}

void CheeseBurglar::update(sf::Vector2f nearestTarget, float frameTime) {
	sf::Vector2f target = nearestTarget - getPosition();
	float scale = sqrt(target.x*target.x + target.y*target.y);
	target /= scale;
	move(target*frameTime*100.0f);
}
