#ifndef TILESET_H
#define TILESET_H

#include <SFML/Graphics.hpp>

class TileSet {
	public:
		TileSet();
		~TileSet();
		void addTexture(std::string fileName);
		const sf::Texture& getTexture(unsigned int tileNumber);
		
	private:
		std::vector<sf::Texture> tileGraphics;
};

#endif
