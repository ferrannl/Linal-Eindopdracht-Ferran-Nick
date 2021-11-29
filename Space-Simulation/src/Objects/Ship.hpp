#pragma once
#include "../Objects/Object.hpp"
class Ship : public Object {
public:
	Ship(int x, int y, int z);

	void act() override;
};