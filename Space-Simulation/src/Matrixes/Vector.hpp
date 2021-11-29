#pragma once
#include "../Matrixes/Matrix.hpp"
class Matrix;
class Vector {

public:
	double x;
	double y;
	double z;
	double w;
	Vector(double _x, double _y);
	Vector(double _x, double _y, double _z);

	void add(Vector vector);
	void sub(Vector vector);
	void mul(double scalair);
	double mul(Vector vector);
	void normalize();
	Vector* transformed_copy(Matrix* matrix);
};