#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite {
	public:
		Tile();
		~Tile();
		void setSolid(const bool& solid);
		const bool& isSolid();

	private:
		bool solid;
};

#endif


