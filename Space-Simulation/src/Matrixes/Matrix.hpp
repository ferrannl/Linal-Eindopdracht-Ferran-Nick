#pragma once
#include <stdlib.h>
#include "../Matrixes/Vector.hpp"

class Vector;
class Matrix {
private:
	int rows;
	int cols;
public:
	double matrix_array[sizeof(rows)][sizeof(cols)];
	Matrix(int rows, int cols);
	void fill_array(double number);
	Matrix* add(Matrix* matrix1);
	Matrix* sub(Matrix* matrix1);
	Matrix* mul_scalair(double scalair);
	Matrix* get_scaling_matrix(double sx, double sy, double sz);
	Matrix* get_translation_matrix(double tx, double ty, double tz);
	Matrix* get_rotation_matrix_x(double angle_x_degrees);
	Matrix* get_rotation_matrix_y(double angle_x_degrees);
	Matrix* get_rotation_matrix_z(double angle_x_degrees);
	Matrix* get_rotation_matrix_m1(Vector* axis);
	Matrix* get_rotation_matrix_m2(Vector* axis);
	Matrix* get_rotation_matrix_m4(Vector* axis);
	Matrix* get_rotation_matrix_m5(Vector* axis);
	Matrix* multiply(Matrix* l, Matrix* r);
	bool compare(Matrix* matrix);
};