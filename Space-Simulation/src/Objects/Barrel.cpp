#include "../Objects/Barrel.hpp"

Barrel::Barrel(int x, int y, int z)
{
	type = "subject";
	//Kanon front
	//front
	//rechtsboven
	vectors.push_back(new Vector(x + 5, y + 5, z + -70));
	//rechtsonder
	vectors.push_back(new Vector(x + 5, y + -5, z + -70));
	//linksboven
	vectors.push_back(new Vector(x + -5, y + 5, z + -70));
	//linksonder
	vectors.push_back(new Vector(x + -5, y + -5, z + -70));
	//back
	//rechtsboven
	vectors.push_back(new Vector(x + 5, y + 5, z + -100));
	//rechtsonder
	vectors.push_back(new Vector(x + 5, y + -5, z + -100));
	//linksboven
	vectors.push_back(new Vector(x + -5, y + 5, z + -100));
	//linksonder
	vectors.push_back(new Vector(x + -5, y + -5, z + -100));

	lines.push_back(new Line(vectors.at(0), vectors.at(1)));
	lines.push_back(new Line(vectors.at(1), vectors.at(3)));
	lines.push_back(new Line(vectors.at(3), vectors.at(2)));
	lines.push_back(new Line(vectors.at(2), vectors.at(0)));

	lines.push_back(new Line(vectors.at(4), vectors.at(5)));
	lines.push_back(new Line(vectors.at(5), vectors.at(7)));
	lines.push_back(new Line(vectors.at(7), vectors.at(6)));
	lines.push_back(new Line(vectors.at(6), vectors.at(4)));

	lines.push_back(new Line(vectors.at(4), vectors.at(0)));
	lines.push_back(new Line(vectors.at(5), vectors.at(1)));
	lines.push_back(new Line(vectors.at(6), vectors.at(2)));
	lines.push_back(new Line(vectors.at(7), vectors.at(3)));

	front = vectors.at(0);
	back = vectors.at(4);
}

void Barrel::act()
{
	Vector* vector = get_local_x_axis();
	vector->normalize();
	Vector* centrum1 = get_centrum();

	Matrix* matrix = calculate_matrix(vector, centrum1, 1.0);
	transform(matrix);
	delete vector;
	delete matrix;
	delete centrum1;
}
