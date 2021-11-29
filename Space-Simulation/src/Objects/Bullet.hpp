#pragma once
#include "../Objects/Object.hpp"
class Bullet : public Object {
public:
	Bullet(int x, int y, int z, Object* controlled_object);

	void act() override;
};