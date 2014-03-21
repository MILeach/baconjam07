#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <fstream>
#include <string>

class TileMap {

	public:
		TileMap();
		TileMap(std::string fileName);
		~TileMap();
		void loadFromFile(std::string fileName);
		const std::vector<std::vector<int>>& getTiles();
		const int& getWidth();
		const int& getHeight();

	private:
		std::vector<std::vector<int>> tiles;
		int width;
		int height;

};

#endif
