#pragma once
#include "../Objects/Object.hpp"
class Barrel : public Object {
public:
	Barrel(int x, int y, int z);

	void act() override;
};