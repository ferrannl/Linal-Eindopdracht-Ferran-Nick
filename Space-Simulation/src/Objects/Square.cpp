#include "../Objects/Square.hpp"

Square::Square(int x, int y, int z)
{
	type = "square";
	vectors.push_back(new Vector(x + 10, y + 10, z + -50));
	vectors.push_back(new Vector(x + 10, y + 10, z + -70));
	vectors.push_back(new Vector(x + -10, y + 10, z + -70));
	vectors.push_back(new Vector(x + -10, y + 10, z + -50));
	vectors.push_back(new Vector(x + 10, y + -10, z + -50));
	vectors.push_back(new Vector(x + 10, y + -10, z + -70));
	vectors.push_back(new Vector(x + -10, y + -10, z + -70));
	vectors.push_back(new Vector(x + -10, y + -10, z + -50));


	//vectors.push_back(new Vector(x + 150 + 1 , y + 40, z + 100));
	//vectors.push_back(new Vector(x + 150 , y + 40 + 1, z + 100));
	//double l = Inproduct::in_product(*vectors.at(8), *vectors.at(9));
	//Vector l = Outproduct::out_product(*vectors.at(8), *vectors.at(9));
	//bovenste lijntjes
	lines.push_back(new Line(vectors.at(0), vectors.at(1)));
	lines.push_back(new Line(vectors.at(1), vectors.at(2)));
	lines.push_back(new Line(vectors.at(2), vectors.at(3)));
	lines.push_back(new Line(vectors.at(3), vectors.at(0)));
	//staande lijntjes
	lines.push_back(new Line(vectors.at(0), vectors.at(4)));
	lines.push_back(new Line(vectors.at(1), vectors.at(5)));
	lines.push_back(new Line(vectors.at(2), vectors.at(6)));
	lines.push_back(new Line(vectors.at(3), vectors.at(7)));
	//onderste lijntjes
	lines.push_back(new Line(vectors.at(4), vectors.at(5)));
	lines.push_back(new Line(vectors.at(5), vectors.at(6)));
	lines.push_back(new Line(vectors.at(6), vectors.at(7)));
	lines.push_back(new Line(vectors.at(7), vectors.at(4)));

	back = vectors.at(1);
	front = vectors.at(0);
}

void Square::act()
{
	if (counter_should_act == 10) {
		counter_should_act = 0;
		if (growing) {
			Vector* centrum = get_centrum();
			Matrix* m = new Matrix(4, 4);

			transform(m->get_translation_matrix(-centrum->x, -centrum->y, -centrum->z));
			transform(m->get_scaling_matrix(1.25, 1.25, 1.25));
			transform(m->get_translation_matrix(centrum->x, centrum->y, centrum->z));

			++growth_counter;
			if (growth_counter == 10) {
				growth_counter = 0;
				growing = false;
			}
			delete centrum;
			delete m;
		}
		else {
			Vector* centrum = get_centrum();
			Matrix* m = new Matrix(4, 4);

			transform(m->get_translation_matrix(-centrum->x, -centrum->y, -centrum->z));
			transform(m->get_scaling_matrix(0.8, 0.8, 0.8));
			transform(m->get_translation_matrix(centrum->x, centrum->y, centrum->z));

			++growth_counter;
			if (growth_counter == 10) {
				growth_counter = 0;
				growing = true;
			};
			delete centrum;
			delete m;
		}
	}
	else {
		++counter_should_act;
	}
}