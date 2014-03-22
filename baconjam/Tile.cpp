#include "Tile.h"

Tile::Tile() {
}

Tile::~Tile() {
}

void Tile::setSolid(const bool& solid) {
	this->solid = solid;
}

const bool& Tile::isSolid() {
	return solid;
}
