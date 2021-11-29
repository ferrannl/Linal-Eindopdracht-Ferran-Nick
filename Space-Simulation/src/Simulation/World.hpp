#pragma once
#include <vector>
#include "../Objects/Object.hpp"
#include <SDL.h>
class World {
public:
	std::vector<Object*> objects;
	World();
	void shoot_bullet();
	int simulate();

	Object* controlled_object;
};