#include "TileSet.h"

TileSet::TileSet() {
}

TileSet::~TileSet() {
}

void TileSet::addTexture(const std::string& fileName, const bool& solid) {
	sf::Texture texture;
	if (!texture.loadFromFile(fileName)) {
		// TODO: Error handling
	} else {
		tileGraphics.push_back(texture);
		tileSolid.push_back(solid);
	}
}

const sf::Texture& TileSet::getTexture(unsigned int tileNumber) {
	if (tileNumber < tileGraphics.size())
		return tileGraphics[tileNumber];
}

const bool& TileSet::isSolid(unsigned int tileNumber) {
	if (tileNumber < tileSolid.size())
		return tileSolid[tileNumber];
}
