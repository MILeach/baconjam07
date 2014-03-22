#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <fstream>
#include <string>

#include "TileSet.h"
#include "Tile.h"

class TileMap {

	public:
		TileMap();
		~TileMap();
		void loadFromFile(std::string fileName, int windowWidth);
		const std::vector<std::vector<Tile>>& getTiles();
		void setTileSet(TileSet tileSet);
		const int& getWidth();
		const int& getHeight();
		void drawToWindow(sf::RenderWindow& window);

	private:
		std::vector<std::vector<Tile>> tiles;
		TileSet tileSet;
		int width;
		int height;

};

#endif
