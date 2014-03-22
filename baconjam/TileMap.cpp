#include "TileMap.h"


TileMap::TileMap() {
}

TileMap::~TileMap() {
}

void TileMap::loadFromFile(std::string fileName, int windowWidth) {
	std::ifstream map(fileName);
	map >> width;
	map >> height;
	int tileWidth = windowWidth/width;

	for(auto y = 0; y < height; y++) {
		tiles.push_back(std::vector<Tile>());
		for (auto x = 0; x < width; x++) {
			int tileValue;
			map >> tileValue;
			Tile tile;
			tile.setPosition(sf::Vector2f(x*tileWidth, y*tileWidth));
			tile.setTexture(tileSet.getTexture(tileValue));
			tile.setSolid(tileSet.isSolid(tileValue));
			int tileScale = tileWidth/tile.getTexture()->getSize().x;
			tile.setScale(sf::Vector2f(tileScale, tileScale));
			tiles.back().push_back(tile);
		}	
	}

}

void TileMap::drawToWindow(sf::RenderWindow& window) {
	for (auto row : tiles) {
		for (auto tile : row) {
			window.draw(tile);
		}
	}
}

const std::vector<std::vector<Tile>>& TileMap::getTiles() {
	return tiles;
}

void TileMap::setTileSet(TileSet tileSet) {
	this->tileSet = tileSet;
}

const int& TileMap::getWidth() {
	return width;
}

const int& TileMap::getHeight() {
	return height;
}
