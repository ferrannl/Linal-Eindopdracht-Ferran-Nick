#include "../Objects/Object.hpp"
#include "../Matrixes/Inproduct.hpp"
#include "../Matrixes/Outproduct.hpp"

Matrix* Object::translation_matrix_heading_pos()
{
	Matrix* m = new Matrix(4, 4);

	Vector* intermediate_step = new Vector(back->x, back->y, back->z);
	intermediate_step->sub(*front);

	m = m->get_translation_matrix(intermediate_step->x, intermediate_step->y, intermediate_step->z);
	return m;
}

Vector* Object::get_local_x_axis()
{
	Vector* vector = new Vector(back->x - front->x,
		back->y - front->y,
		back->z - front->z);
	return vector;
}

Vector* Object::get_local_y_axis()
{
	Vector* vector = new Vector(vectors.at(2)->x - vectors.at(0)->x,
		vectors.at(2)->y - vectors.at(0)->y,
		vectors.at(2)->z - vectors.at(0)->z);
	return vector;
}

Vector* Object::get_local_z_axis()
{
	Vector* vector = new Vector(vectors.at(0)->x - vectors.at(1)->x,
		vectors.at(0)->y - vectors.at(1)->y,
		vectors.at(0)->z - vectors.at(1)->z);
	return vector;
}

Vector* Object::get_center()
{
	double x_total = 0;
	double y_total = 0;
	double z_total = 0;

	for (int i = 0; i < vectors.size(); i++) {
		x_total += vectors.at(i)->x;
		y_total += vectors.at(i)->y;
		z_total += vectors.at(i)->z;
	}

	Vector* vector = new Vector(x_total / vectors.size(),
		y_total / vectors.size(),
		z_total / vectors.size());

	return vector;
}

Vector* Object::get_heading()
{
	Vector* v = new Vector(front->x - camera->x, front->y - camera->y, front->z - camera->z);
	//Vector* v = new Vector(camera->x- front->x  ,   camera->y-front->y,   camera->z-front->z);
	v->normalize();
	return v;
}

Vector* Object::get_gun_heading()
{
	Vector* tussenstap = new Vector(back->x, back->y, back->z);
	tussenstap->sub(*front);
	tussenstap->normalize();
	return tussenstap;
}

Vector* Object::gun_location()
{
	double x_total = 0;
	double y_total = 0;
	double z_total = 0;

	for (int i = 0; i < 4; i++) {
		x_total += sub_objects.at(0)->vectors.at(i)->x;
		y_total += sub_objects.at(0)->vectors.at(i)->y;
		z_total += sub_objects.at(0)->vectors.at(i)->z;
	}

	Vector* vector = new Vector(x_total / 4,
		y_total / 4,
		z_total / 4);

	return vector;
}

Object::Object() {
	lines = {};
	vectors = {};
	sub_objects = {};
	growing = true;
	translation_matrix_pos_x = new Matrix(4, 4);
	translation_matrix_pos_y = new Matrix(4, 4);
	translation_matrix_neg_x = new Matrix(4, 4);
	translation_matrix_neg_y = new Matrix(4, 4);
	translation_matrix_pos_z = new Matrix(4, 4);
	translation_matrix_neg_z = new Matrix(4, 4);
	translation_matrix_pos_x = translation_matrix_pos_x->get_translation_matrix(10.0, 0.0, 0.0);
	translation_matrix_pos_y = translation_matrix_pos_y->get_translation_matrix(0.0, 10.0, 0.0);
	translation_matrix_neg_x = translation_matrix_neg_x->get_translation_matrix(-10.0, 0.0, 0.0);
	translation_matrix_neg_y = translation_matrix_neg_y->get_translation_matrix(0.0, -10.0, 0.0);
	translation_matrix_pos_z = translation_matrix_neg_z->get_translation_matrix(0.0, 0.0, 10.0);
	translation_matrix_neg_z = translation_matrix_neg_z->get_translation_matrix(0.0, 0.0, -10.0);

	rotation_matrix_pos_x = new Matrix(4, 4);
	rotation_matrix_pos_y = new Matrix(4, 4);
	rotation_matrix_neg_x = new Matrix(4, 4);
	rotation_matrix_neg_y = new Matrix(4, 4);
	rotation_matrix_pos_z = new Matrix(4, 4);
	rotation_matrix_neg_z = new Matrix(4, 4);
	rotation_matrix_pos_x = rotation_matrix_pos_x->get_rotation_matrix_x(5.0);
	rotation_matrix_pos_y = rotation_matrix_pos_y->get_rotation_matrix_y(5.0);
	rotation_matrix_neg_x = rotation_matrix_neg_x->get_rotation_matrix_x(-5.0);
	rotation_matrix_neg_y = rotation_matrix_neg_y->get_rotation_matrix_y(-5.0);
	rotation_matrix_pos_z = rotation_matrix_pos_z->get_rotation_matrix_z(5.0);
	rotation_matrix_neg_z = rotation_matrix_neg_z->get_rotation_matrix_z(-5.0);

}

void Object::transform(Matrix* matrix)
{
	for (int i = 0; i < vectors.size(); i++) {
		double x = matrix->matrix_array[0][0] * vectors.at(i)->x + matrix->matrix_array[0][1] * vectors.at(i)->y + matrix->matrix_array[0][2] * vectors.at(i)->z + matrix->matrix_array[0][3] * vectors.at(i)->w;
		double y = matrix->matrix_array[1][0] * vectors.at(i)->x + matrix->matrix_array[1][1] * vectors.at(i)->y + matrix->matrix_array[1][2] * vectors.at(i)->z + matrix->matrix_array[1][3] * vectors.at(i)->w;
		double z = matrix->matrix_array[2][0] * vectors.at(i)->x + matrix->matrix_array[2][1] * vectors.at(i)->y + matrix->matrix_array[2][2] * vectors.at(i)->z + matrix->matrix_array[2][3] * vectors.at(i)->w;
		double w = matrix->matrix_array[3][0] * vectors.at(i)->x + matrix->matrix_array[3][1] * vectors.at(i)->y + matrix->matrix_array[3][2] * vectors.at(i)->z + matrix->matrix_array[3][3] * vectors.at(i)->w;
		vectors.at(i)->x = x;
		vectors.at(i)->y = y;
		vectors.at(i)->z = z;
		vectors.at(i)->w = w;
	}
	for (auto& s : sub_objects) {
		s->transform(matrix);
	}
}


Matrix* Object::calculate_matrix(Vector* rotation, Vector* centrum, double degrees) {
	// translatiematrix naar de oorsprong
	Matrix* to = new Matrix(4, 4);
	to = to->get_translation_matrix(-centrum->x, -centrum->y, -centrum->z);

	Matrix* m1 = new Matrix(4, 4);
	// rotatiematrix om de y-as naar het xy-vlak
	m1 = m1->get_rotation_matrix_m1(rotation);

	// rotatiematrix om de z-as naar de x-as
	Matrix* m2 = new Matrix(4, 4);
	m2 = m2->get_rotation_matrix_m2(rotation);

	//rotatie om de x-as
	Matrix* m3 = new Matrix(4, 4);
	m3 = m3->get_rotation_matrix_x(degrees);

	//rotatie om de z-as terug
	Matrix* m4 = new Matrix(4, 4);
	m4 = m4->get_rotation_matrix_m4(rotation);

	//rotatie om de y-as terug
	Matrix* m5 = new Matrix(4, 4);
	m5 = m5->get_rotation_matrix_m5(rotation);

	//translatiematrix terug
	Matrix* tt = new Matrix(4, 4);
	tt = tt->get_translation_matrix(centrum->x, centrum->y, centrum->z);

	//vermenig alle matrices
	Matrix* m = new Matrix(4, 4);
	m = m->multiply(m1, to);
	m = m->multiply(m2, m);
	m = m->multiply(m3, m);
	m = m->multiply(m4, m);
	m = m->multiply(m5, m);
	m = m->multiply(tt, m);

	return m;

}

bool Object::check_collision(Object* bullet)
{
	Vector this_min = *get_min();
	Vector this_max = *get_max();

	Vector other_min = *bullet->get_min();
	Vector other_max = *bullet->get_max();

	return(this_max.x > other_min.x &&
		this_min.x < other_max.x&&
		this_max.y > other_min.y &&
		this_min.y < other_max.y&&
		this_max.z > other_min.z &&
		this_min.z < other_max.z);
}

Vector* Object::get_min()
{
	Vector* v = new Vector(INT_MAX, INT_MAX, INT_MAX);

	for (auto& a : vectors) {
		if (a->x < v->x) {
			v->x = a->x;
		}
		if (a->y < v->y) {
			v->y = a->y;
		}
		if (a->z < v->z) {
			v->z = a->z;
		}
	}
	for (auto& s : sub_objects) {
		for (auto& a : s->vectors) {
			if (a->x < v->x) {
				v->x = a->x;
			}
			if (a->y < v->y) {
				v->y = a->y;
			}
			if (a->z < v->z) {
				v->z = a->z;
			}
		}
	}
	return v;
}

Vector* Object::get_max()
{
	Vector* v = new Vector(INT_MIN, INT_MIN, INT_MIN);
	for (auto& a : vectors) {
		if (a->x > v->x) {
			v->x = a->x;
		}
		if (a->y > v->y) {
			v->y = a->y;
		}
		if (a->z > v->z) {
			v->z = a->z;
		}
	}
	for (auto& s : sub_objects) {
		for (auto& a : s->vectors) {
			if (a->x > v->x) {
				v->x = a->x;
			}
			if (a->y > v->y) {
				v->y = a->y;
			}
			if (a->z > v->z) {
				v->z = a->z;
			}
		}
	}
	return v;
}
