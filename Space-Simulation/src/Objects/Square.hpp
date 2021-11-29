#pragma once
#include "../Objects/Object.hpp"
class Square : public Object {
public:
	Square(int x, int y, int z);

	void act() override;
};