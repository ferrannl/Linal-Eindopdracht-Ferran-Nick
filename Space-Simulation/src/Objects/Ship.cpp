#include "../Objects/Ship.hpp"
#include "../Objects/Barrel.hpp"

Ship::Ship(int x, int y, int z)
{
	type = "ship";
	//rechtsboven front
	vectors.push_back(new Vector(x + 10, y + 10, z + -100));
	//rechtsonder front
	vectors.push_back(new Vector(x + 10, y + -10, z + -100));
	//linksboven front
	vectors.push_back(new Vector(x + -10, y + 10, z + -100));
	//linksonder front
	vectors.push_back(new Vector(x + -10, y + -10, z + -100));

	//rechtsboven front back bottom
	vectors.push_back(new Vector(x + 40, y + 10, z + -200));
	//rechtsonder front back bottom
	vectors.push_back(new Vector(x + 40, y + -10, z + -200));
	//linksboven front back bottom
	vectors.push_back(new Vector(x + -40, y + 10, z + -200));
	//linksonder front back bottom
	vectors.push_back(new Vector(x + -40, y + -10, z + -200));

	//rechtsboven back back bottom
	vectors.push_back(new Vector(x + 40, y + 10, z + -220));
	//rechtsonder back back bottom
	vectors.push_back(new Vector(x + 40, y + -10, z + -220));
	//linksboven back back bottom
	vectors.push_back(new Vector(x + -40, y + 10, z + -220));
	//linksonder back back bottom
	vectors.push_back(new Vector(x + -40, y + -10, z + -220));

	//vierkant aan boven kant van space ship(vannuit top view perspectief)
	//rechtsboven
	vectors.push_back(new Vector(x + 10, y + 40, z + -220));
	//rechtsonder
	vectors.push_back(new Vector(x + 10, y + 40, z + -200));
	//linksboven
	vectors.push_back(new Vector(x + -10, y + 40, z + -220));
	//linksonder
	vectors.push_back(new Vector(x + -10, y + 40, z + -200));

	//thruster top
	//front
	//rechtsboven
	vectors.push_back(new Vector(x + 8, y + 35, z + -220));
	//rechtsonder
	vectors.push_back(new Vector(x + 8, y + 15, z + -220));
	//linksboven
	vectors.push_back(new Vector(x + -8, y + 35, z + -220));
	//linksonder
	vectors.push_back(new Vector(x + -8, y + 15, z + -220));
	//back
	//rechtsboven
	vectors.push_back(new Vector(x + 8, y + 35, z + -230));
	//rechtsonder
	vectors.push_back(new Vector(x + 8, y + 15, z + -230));
	//linksboven
	vectors.push_back(new Vector(x + -8, y + 35, z + -230));
	//linksonder
	vectors.push_back(new Vector(x + -8, y + 15, z + -230));

	//thruster mid
	//rechtsboven
	vectors.push_back(new Vector(x + 8, y + 8, z + -220));
	//rechtsonder
	vectors.push_back(new Vector(x + 8, y + -8, z + -220));
	//linksboven
	vectors.push_back(new Vector(x + -8, y + 8, z + -220));
	//linksonder
	vectors.push_back(new Vector(x + -8, y + -8, z + -220));
	//back
	//rechtsboven
	vectors.push_back(new Vector(x + 8, y + 8, z + -230));
	//rechtsonder
	vectors.push_back(new Vector(x + 8, y + -8, z + -230));
	//linksboven
	vectors.push_back(new Vector(x + -8, y + 8, z + -230));
	//linksonder
	vectors.push_back(new Vector(x + -8, y + -8, z + -230));

	//thruster left
	//front
	//rechtsboven
	vectors.push_back(new Vector(x + -12, y + 8, z + -220));
	//rechtsonder
	vectors.push_back(new Vector(x + -12, y + -8, z + -220));
	//linksboven
	vectors.push_back(new Vector(x + -38, y + 8, z + -220));
	//linksonder
	vectors.push_back(new Vector(x + -38, y + -8, z + -220));
	//back
	//rechtsboven
	vectors.push_back(new Vector(x + -12, y + 8, z + -230));
	//rechtsonder
	vectors.push_back(new Vector(x + -12, y + -8, z + -230));
	//linksboven
	vectors.push_back(new Vector(x + -38, y + 8, z + -230));
	//linksonder
	vectors.push_back(new Vector(x + -38, y + -8, z + -230));

	//thruster right
	//front
	//rechtsboven
	vectors.push_back(new Vector(x + 38, y + 8, z + -220));
	//rechtsonder
	vectors.push_back(new Vector(x + 38, y + -8, z + -220));
	//linksboven
	vectors.push_back(new Vector(x + 12, y + 8, z + -220));
	//linksonder
	vectors.push_back(new Vector(x + 12, y + -8, z + -220));
	//back
	//rechtsboven
	vectors.push_back(new Vector(x + 38, y + 8, z + -230));
	//rechtsonder
	vectors.push_back(new Vector(x + 38, y + -8, z + -230));
	//linksboven
	vectors.push_back(new Vector(x + 12, y + 8, z + -230));
	//linksonder
	vectors.push_back(new Vector(x + 12, y + -8, z + -230));



	back = new Vector(x + 0, y + 0, z + -100);
	front = new Vector(x + 0, y + 0, z + -110);
	camera = new Vector(x + 0, y + 50, z + -250);
	vectors.push_back(front);
	vectors.push_back(back);
	vectors.push_back(camera);

	//front
	lines.push_back(new Line(vectors.at(0), vectors.at(1)));
	lines.push_back(new Line(vectors.at(1), vectors.at(3)));
	lines.push_back(new Line(vectors.at(2), vectors.at(3)));
	lines.push_back(new Line(vectors.at(2), vectors.at(0)));

	//top
	lines.push_back(new Line(vectors.at(12), vectors.at(13)));
	lines.push_back(new Line(vectors.at(13), vectors.at(15)));
	lines.push_back(new Line(vectors.at(15), vectors.at(14)));
	lines.push_back(new Line(vectors.at(14), vectors.at(12)));

	//left
	lines.push_back(new Line(vectors.at(6), vectors.at(7)));
	lines.push_back(new Line(vectors.at(7), vectors.at(11)));
	lines.push_back(new Line(vectors.at(11), vectors.at(10)));
	lines.push_back(new Line(vectors.at(10), vectors.at(6)));

	//right
	lines.push_back(new Line(vectors.at(8), vectors.at(9)));
	lines.push_back(new Line(vectors.at(9), vectors.at(5)));
	lines.push_back(new Line(vectors.at(5), vectors.at(4)));
	lines.push_back(new Line(vectors.at(4), vectors.at(8)));

	//front to top
	lines.push_back(new Line(vectors.at(0), vectors.at(13)));
	lines.push_back(new Line(vectors.at(2), vectors.at(15)));

	//front to left
	lines.push_back(new Line(vectors.at(2), vectors.at(6)));
	lines.push_back(new Line(vectors.at(3), vectors.at(7)));

	//front to rigth
	lines.push_back(new Line(vectors.at(0), vectors.at(4)));
	lines.push_back(new Line(vectors.at(1), vectors.at(5)));

	//top to left
	lines.push_back(new Line(vectors.at(15), vectors.at(6)));
	lines.push_back(new Line(vectors.at(14), vectors.at(10)));

	//top to right
	lines.push_back(new Line(vectors.at(12), vectors.at(8)));
	lines.push_back(new Line(vectors.at(13), vectors.at(4)));

	//bottom line back
	lines.push_back(new Line(vectors.at(9), vectors.at(11)));

	//thrust
	int start = 16;
	for (int i = 0; i < 4; i++) {
		lines.push_back(new Line(vectors.at(16 + i * 8), vectors.at(17 + i * 8)));
		lines.push_back(new Line(vectors.at(17 + i * 8), vectors.at(19 + i * 8)));
		lines.push_back(new Line(vectors.at(19 + i * 8), vectors.at(18 + i * 8)));
		lines.push_back(new Line(vectors.at(18 + i * 8), vectors.at(16 + i * 8)));

		lines.push_back(new Line(vectors.at(20 + i * 8), vectors.at(21 + i * 8)));
		lines.push_back(new Line(vectors.at(21 + i * 8), vectors.at(23 + i * 8)));
		lines.push_back(new Line(vectors.at(23 + i * 8), vectors.at(22 + i * 8)));
		lines.push_back(new Line(vectors.at(22 + i * 8), vectors.at(20 + i * 8)));

		lines.push_back(new Line(vectors.at(20 + i * 8), vectors.at(16 + i * 8)));
		lines.push_back(new Line(vectors.at(21 + i * 8), vectors.at(17 + i * 8)));
		lines.push_back(new Line(vectors.at(22 + i * 8), vectors.at(18 + i * 8)));
		lines.push_back(new Line(vectors.at(23 + i * 8), vectors.at(19 + i * 8)));
	}

	sub_objects.push_back(new Barrel(x, y, z));
}

void Ship::act()
{
	if (velocity != 0) {
		Matrix* m = new Matrix(4, 4);

		Vector* tussenstap = new Vector(back->x, back->y, back->z);
		tussenstap->sub(*front);
		tussenstap->normalize();
		tussenstap->mul(velocity);

		m = m->get_translation_matrix(tussenstap->x, tussenstap->y, tussenstap->z);
		transform(m);

		delete m;
	}

	for (auto& s : sub_objects) {
		s->act();
	}
}
