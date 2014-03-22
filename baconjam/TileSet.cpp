#include "TileSet.h"

TileSet::TileSet() {
}

TileSet::~TileSet() {
}

void TileSet::addTexture(std::string fileName) {
	sf::Texture texture;
	if (!texture.loadFromFile(fileName)) {
		// TODO: Error handling
	} else {
		tileGraphics.push_back(texture);
	}
}

const sf::Texture& TileSet::getTexture(unsigned int tileNumber) {
	if (tileNumber < tileGraphics.size())
		return tileGraphics[tileNumber];
}

