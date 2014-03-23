#ifndef CHEESEBURGLAR_H
#define CHEESEBURGLAR_H

#include <SFML/Graphics.hpp>

class CheeseBurglar : public sf::Sprite {
	public:
		CheeseBurglar();
		~CheeseBurglar();
		void update(sf::Vector2f nearestTarget, float frameTime);
};

#endif
