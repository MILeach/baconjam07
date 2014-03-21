#include "TileMap.h"


TileMap::TileMap() {
}

TileMap::TileMap(std::string fileName) {
	loadFromFile(fileName);
}

TileMap::~TileMap() {
}

void TileMap::loadFromFile(std::string fileName) {
	std::ifstream map(fileName);
	map >> width;
	map >> height;

	for(auto y = 0; y < height; y++) {
		tiles.push_back(std::vector<int>());
		for (auto x = 0; x < width; x++) {
			int tileValue;
			map >> tileValue;
			tiles.back().push_back(tileValue);
		}	
	}

}

const std::vector<std::vector<int>>& TileMap::getTiles() {
	return tiles;
}

const int& TileMap::getWidth() {
	return width;
}

const int& TileMap::getHeight() {
	return height;
}
