#include "basetile.h"

BaseTile::BaseTile(int in_id)
: id(in_id), pos(Vect2(-1, -1)), name(""), tileType(TileType::MAX), symbol('.') {
	
}

BaseTile::BaseTile(int in_id, Vect2 in_pos, string in_name, TileType::Enum in_type, char in_sym)
: id(in_id), pos(in_pos), name(in_name), tileType(in_type), symbol(in_sym) {
	
}

BaseTile::~BaseTile() {
	
}
