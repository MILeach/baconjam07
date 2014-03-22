#ifndef TILESET_H
#define TILESET_H

#include <SFML/Graphics.hpp>

class TileSet {
	public:
		TileSet();
		~TileSet();
		void addTexture(const std::string& fileName, const bool& solid);
		const sf::Texture& getTexture(unsigned int tileNumber);
		const bool& isSolid(unsigned int tileNumber);
		
	private:
		std::vector<sf::Texture> tileGraphics;
		std::vector<bool> tileSolid;
};

#endif
