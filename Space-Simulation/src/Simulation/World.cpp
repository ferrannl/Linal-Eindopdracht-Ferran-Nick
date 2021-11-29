#include "../Simulation/World.hpp"
#include "../Objects/Ship.hpp"
#include "../Objects/Square.hpp"
#include "../Objects/Bullet.hpp"

World::World()
{
	Object* s1 = new Ship(-100, -50, -300);
	Object* s2 = new Square(-150, -40, -100);
	objects.push_back(s1);
	objects.push_back(s2);

	controlled_object = s1;
	std::vector<Object*> otemp = objects;
	for (auto& o : otemp) {
		for (auto& s : o->sub_objects) {
			objects.push_back(s);
		}
	}
}

void World::shoot_bullet()
{
	Vector* v = controlled_object->gun_location();
	Object* bullet = new Bullet(v->x, v->y, v->z, controlled_object);
	bullet->velocity = controlled_object->velocity + 3;
	objects.push_back(bullet);
}

int World::simulate()
{
	Object* square = {};
	bool found = false;
	for (auto& o : objects) {
		o->act();
		if (o->type == "square") {
			square = o;
			found = true;
		}
	}
	if (found) {
		for (auto& o : objects) {
			if (o->type == "bullet") {
				if (square->check_collision(o)) {
					//game over;
					objects.erase(objects.begin() + 1);

					return 1;
				}
			}
		}
	}

	for (auto& o : objects) {
		if (o->type != "ship" && o->type != "subject") {
			if (controlled_object->check_collision(o)) {
				//game over;
				objects.erase(objects.begin());

				return 2;
			}
		}
	}

}
