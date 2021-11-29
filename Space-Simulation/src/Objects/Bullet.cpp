#include "../Objects/Bullet.hpp"
#include "../Matrixes/Inproduct.hpp"

Bullet::Bullet(int x, int y, int z, Object* controlled_object)
{
	type = "bullet";
	heading = controlled_object->translation_matrix_heading_pos();
	v_heading = controlled_object->get_gun_heading();

	//Vector* _front = controlled_object->front;
	//Vector* _back = controlled_object->back;
	std::vector<Vector*> v = controlled_object->sub_objects.at(0)->vectors;

	Vector* _front = new Vector(x, y, z);
	Vector* _back = new Vector(x, y, z);

	//front
	vectors.push_back(new Vector(v.at(0)->x, v.at(0)->y, v.at(0)->z + 0));
	vectors.push_back(new Vector(v.at(1)->x, v.at(1)->y, v.at(1)->z + 0));
	vectors.push_back(new Vector(v.at(2)->x, v.at(2)->y, v.at(2)->z + 0));
	vectors.push_back(new Vector(v.at(3)->x, v.at(3)->y, v.at(3)->z + 0));
	//back
	vectors.push_back(new Vector(v.at(4)->x, v.at(4)->y, v.at(4)->z));
	vectors.push_back(new Vector(v.at(5)->x, v.at(5)->y, v.at(5)->z));
	vectors.push_back(new Vector(v.at(6)->x, v.at(6)->y, v.at(6)->z));
	vectors.push_back(new Vector(v.at(7)->x, v.at(7)->y, v.at(7)->z));

	////front
	//vectors.push_back(new Vector(_front->x + 5, _front->y + 5, _front->z + 0));
	//vectors.push_back(new Vector(_front->x + 5, _front->y - 5, _front->z + 0));
	//vectors.push_back(new Vector(_front->x - 5, _front->y + 5, _front->z + 0));
	//vectors.push_back(new Vector(_front->x - 5, _front->y - 5, _front->z + 0));
	////back
	//vectors.push_back(new Vector(_back->x + 5, _back->y + 5, _back->z - 10));
	//vectors.push_back(new Vector(_back->x + 5, _back->y - 5, _back->z - 10));
	//vectors.push_back(new Vector(_back->x - 5, _back->y + 5, _back->z - 10));
	//vectors.push_back(new Vector(_back->x - 5, _back->y - 5, _back->z - 10));


	delete _front;
	delete _back;

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


	back = vectors.at(1);
	front = vectors.at(0);

	/*for (auto v : vectors) {
		double deg = Inproduct::in_product(*v, *v_heading);
		Matrix* m = new Matrix(4, 4);
		m.get
	}*/

	//draaien op basis van heading mmmmm
	Vector* centrum = get_centrum();
	Matrix* m = new Matrix(4, 4);

	transform(m->get_translation_matrix(-centrum->x, -centrum->y, -centrum->z));
	transform(m->get_scaling_matrix(0.5, 0.5, 0.5));
	transform(m->get_translation_matrix(centrum->x, centrum->y, centrum->z));

	transform(heading);
	transform(heading);
	transform(heading);
	transform(heading);
	delete m;
	delete centrum;
}

void Bullet::act()
{
	Matrix* m = new Matrix(4, 4);
	Vector* temp = new Vector(v_heading->x, v_heading->y, v_heading->z);
	temp->mul(velocity);

	m = m->get_translation_matrix(temp->x, temp->y, temp->z);
	transform(m);

	delete temp;
	delete m;
}
