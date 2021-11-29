#include "../Matrixes/Vector.hpp"
#include <math.h>


Vector::Vector(double _x, double _y) : x{ _x }, y{ _y }, z{ 0 } {}

Vector::Vector(double _x, double _y, double _z) : x{ _x }, y{ _y }, z{ _z }, w{ 1 } {}

void Vector::add(Vector vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
}

void Vector::sub(Vector vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
}

void Vector::mul(double scalair)
{
	x = x * scalair;
	y = y * scalair;
	z = z * scalair;
}

double Vector::mul(Vector vector)
{
	x = x * vector.x;
	y = y * vector.y;
	z = z * vector.z;
	return x + y + z;
}

void Vector::normalize()
{
	double length = sqrt(x * x + y * y + z * z);
	x = x / length;
	y = y / length;
	z = z / length;
}

Vector* Vector::transformed_copy(Matrix* matrix)
{
	double nx = matrix->matrix_array[0][0] * x + matrix->matrix_array[0][1] * y + matrix->matrix_array[0][2] * z + matrix->matrix_array[0][3] * w;
	double ny = matrix->matrix_array[1][0] * x + matrix->matrix_array[1][1] * y + matrix->matrix_array[1][2] * z + matrix->matrix_array[1][3] * w;
	double nz = matrix->matrix_array[2][0] * x + matrix->matrix_array[2][1] * y + matrix->matrix_array[2][2] * z + matrix->matrix_array[2][3] * w;
	double nw = matrix->matrix_array[3][0] * x + matrix->matrix_array[3][1] * y + matrix->matrix_array[3][2] * z + matrix->matrix_array[3][3] * w;
	Vector* v = new Vector(nx, ny, nz);
	v->w = nw;
	return v;
}
