#include "../Matrixes/Matrix.hpp"
#include <iostream>
#include <math.h>
#define N 4
#define M_PI 3.14159265

Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	fill_array(0);

}


using namespace std;

// This function returns 1 if A[][] and B[][] are identical
// otherwise returns 0
bool Matrix::compare(Matrix* matrix)
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (matrix_array[i][j] != matrix->matrix_array[i][j])
				return 0;
	return 1;
}

void Matrix::fill_array(double number) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; j++) {
			matrix_array[i][j] = number;
		}
	}
}

Matrix* Matrix::add(Matrix* matrix1)
{
	Matrix* return_matrix = new Matrix(rows, cols);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; j++)
		{
			return_matrix->matrix_array[i][j] = matrix1->matrix_array[i][j] + matrix_array[i][j];
		}
	}
	return return_matrix;
}

Matrix* Matrix::sub(Matrix* matrix1)
{
	Matrix* return_matrix = new Matrix(rows, cols);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; j++)
		{
			return_matrix->matrix_array[i][j] = matrix1->matrix_array[i][j] - matrix_array[i][j];
		}
	}
	return return_matrix;
}

Matrix* Matrix::mul_scalair(double scalair) {
	Matrix* return_matrix = new Matrix(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; j++) {
			return_matrix->matrix_array[i][j] = scalair * matrix_array[i][j];
		}
	}
	return return_matrix;
}

Matrix* Matrix::get_scaling_matrix(double sx, double sy, double sz) {
	Matrix* return_matrix = new Matrix(rows, cols);
	return_matrix->matrix_array[0][0] = sx; 	return_matrix->matrix_array[0][1] = 0; 	return_matrix->matrix_array[0][2] = 0; return_matrix->matrix_array[0][3] = 0;
	return_matrix->matrix_array[1][0] = 0; 	return_matrix->matrix_array[1][1] = sy; 	return_matrix->matrix_array[1][2] = 0; return_matrix->matrix_array[1][3] = 0;
	return_matrix->matrix_array[2][0] = 0; 	return_matrix->matrix_array[2][1] = 0; 	return_matrix->matrix_array[2][2] = sz; return_matrix->matrix_array[2][3] = 0;
	return_matrix->matrix_array[3][0] = 0; 	return_matrix->matrix_array[3][1] = 0; 	return_matrix->matrix_array[3][2] = 0; return_matrix->matrix_array[3][3] = 1;
	return return_matrix;
}

Matrix* Matrix::get_translation_matrix(double tx, double ty, double tz) {
	Matrix* return_matrix = new Matrix(rows, cols);
	return_matrix->matrix_array[0][0] = 1; 	return_matrix->matrix_array[0][1] = 0; 	return_matrix->matrix_array[0][2] = 0; return_matrix->matrix_array[0][3] = tx;
	return_matrix->matrix_array[1][0] = 0; 	return_matrix->matrix_array[1][1] = 1; 	return_matrix->matrix_array[1][2] = 0; return_matrix->matrix_array[1][3] = ty;
	return_matrix->matrix_array[2][0] = 0; 	return_matrix->matrix_array[2][1] = 0; 	return_matrix->matrix_array[2][2] = 1; return_matrix->matrix_array[2][3] = tz;
	return_matrix->matrix_array[3][0] = 0; 	return_matrix->matrix_array[3][1] = 0; 	return_matrix->matrix_array[3][2] = 0; return_matrix->matrix_array[3][3] = 1;

	return return_matrix;
}

Matrix* Matrix::get_rotation_matrix_x(double angle_x_degrees)
{
	double a = angle_x_degrees / 180 * M_PI;
	Matrix* return_matrix = new Matrix(rows, cols);
	return_matrix->matrix_array[0][0] = 1; 	return_matrix->matrix_array[0][1] = 0; return_matrix->matrix_array[0][2] = 0; return_matrix->matrix_array[0][3] = 0;
	return_matrix->matrix_array[1][0] = 0; 	return_matrix->matrix_array[1][1] = cos(a); 	return_matrix->matrix_array[1][2] = -sin(a); return_matrix->matrix_array[1][3] = 0;
	return_matrix->matrix_array[2][0] = 0; 	return_matrix->matrix_array[2][1] = sin(a); 	return_matrix->matrix_array[2][2] = cos(a); return_matrix->matrix_array[2][3] = 0;
	return_matrix->matrix_array[3][0] = 0; 	return_matrix->matrix_array[3][1] = 0; 	return_matrix->matrix_array[3][2] = 0; return_matrix->matrix_array[3][3] = 1;
	return return_matrix;
}

Matrix* Matrix::get_rotation_matrix_y(double angle_x_degrees)
{
	double a = angle_x_degrees / 180 * M_PI;
	Matrix* return_matrix = new Matrix(rows, cols);
	return_matrix->matrix_array[0][0] = cos(a); 	return_matrix->matrix_array[0][1] = 0; return_matrix->matrix_array[0][2] = sin(a); return_matrix->matrix_array[0][3] = 0;
	return_matrix->matrix_array[1][0] = 0; 	return_matrix->matrix_array[1][1] = 1; 	return_matrix->matrix_array[1][2] = 0; return_matrix->matrix_array[1][3] = 0;
	return_matrix->matrix_array[2][0] = -sin(a); 	return_matrix->matrix_array[2][1] = 0; 	return_matrix->matrix_array[2][2] = cos(a); return_matrix->matrix_array[2][3] = 0;
	return_matrix->matrix_array[3][0] = 0; 	return_matrix->matrix_array[3][1] = 0; 	return_matrix->matrix_array[3][2] = 0; return_matrix->matrix_array[3][3] = 1;
	return return_matrix;
}

Matrix* Matrix::get_rotation_matrix_z(double angle_x_degrees)
{
	double a = angle_x_degrees / 180 * M_PI;
	Matrix* return_matrix = new Matrix(rows, cols);
	return_matrix->matrix_array[0][0] = cos(a); 	return_matrix->matrix_array[0][1] = -sin(a); return_matrix->matrix_array[0][2] = 0; return_matrix->matrix_array[0][3] = 0;
	return_matrix->matrix_array[1][0] = sin(a); 	return_matrix->matrix_array[1][1] = cos(a); 	return_matrix->matrix_array[1][2] = 0; return_matrix->matrix_array[1][3] = 0;
	return_matrix->matrix_array[2][0] = 0; 	return_matrix->matrix_array[2][1] = 0; 	return_matrix->matrix_array[2][2] = 1; return_matrix->matrix_array[2][3] = 0;
	return_matrix->matrix_array[3][0] = 0; 	return_matrix->matrix_array[3][1] = 0; 	return_matrix->matrix_array[3][2] = 0; return_matrix->matrix_array[3][3] = 1;
	return return_matrix;
}

Matrix* Matrix::get_rotation_matrix_m1(Vector* axis)
{
	Matrix* m = new Matrix(4, 4);

	double xz = sqrt(axis->x * axis->x + axis->z * axis->z);

	if (xz == 0.0) {
		m->matrix_array[0][0] = 1.0; m->matrix_array[0][1] = 0.0; m->matrix_array[0][2] = 0.0; m->matrix_array[0][3] = 0.0;
		m->matrix_array[1][0] = 0.0; m->matrix_array[1][1] = 1.0; m->matrix_array[1][2] = 0.0; m->matrix_array[1][3] = 0.0;
		m->matrix_array[2][0] = 0.0; m->matrix_array[2][1] = 0.0; m->matrix_array[2][2] = 1.0; m->matrix_array[2][3] = 0.0;
		m->matrix_array[3][0] = 0.0; m->matrix_array[3][1] = 0.0; m->matrix_array[3][2] = 0.0; m->matrix_array[3][3] = 1.0;
	}
	else {
		m->matrix_array[0][0] = axis->x / xz; m->matrix_array[0][1] = 0.0; m->matrix_array[0][2] = axis->z / xz; m->matrix_array[0][3] = 0.0;
		m->matrix_array[1][0] = 0.0; m->matrix_array[1][1] = 1.0; m->matrix_array[1][2] = 0.0; m->matrix_array[1][3] = 0.0;
		m->matrix_array[2][0] = -axis->z / xz; m->matrix_array[2][1] = 0.0; m->matrix_array[2][2] = axis->x / xz; m->matrix_array[2][3] = 0.0;
		m->matrix_array[3][0] = 0.0; m->matrix_array[3][1] = 0.0; m->matrix_array[3][2] = 0.0; m->matrix_array[3][3] = 1.0;
	}

	return m;
}

Matrix* Matrix::get_rotation_matrix_m2(Vector* axis)
{
	Matrix* m = new Matrix(4, 4);

	double xz = sqrt(axis->x * axis->x + axis->z * axis->z);
	double xyz = sqrt(axis->x * axis->x + axis->y * axis->y + axis->z * axis->z);

	m->matrix_array[0][0] = xz / xyz; m->matrix_array[0][1] = axis->y / xyz; m->matrix_array[0][2] = 0.0; m->matrix_array[0][3] = 0.0;
	m->matrix_array[1][0] = -axis->y / xyz; m->matrix_array[1][1] = xz / xyz; m->matrix_array[1][2] = 0.0; m->matrix_array[1][3] = 0.0;
	m->matrix_array[2][0] = 0.0; m->matrix_array[2][1] = 0.0; m->matrix_array[2][2] = 1.0; m->matrix_array[2][3] = 0.0;
	m->matrix_array[3][0] = 0.0; m->matrix_array[3][1] = 0.0; m->matrix_array[3][2] = 0.0; m->matrix_array[3][3] = 1.0;

	return m;
}

Matrix* Matrix::get_rotation_matrix_m4(Vector* axis)
{
	Matrix* m = new Matrix(4, 4);

	double xz = sqrt(axis->x * axis->x + axis->z * axis->z);
	double xyz = sqrt(axis->x * axis->x + axis->y * axis->y + axis->z * axis->z);

	m->matrix_array[0][0] = xz / xyz; m->matrix_array[0][1] = -axis->y / xyz; m->matrix_array[0][2] = 0.0; m->matrix_array[0][3] = 0.0;
	m->matrix_array[1][0] = axis->y / xyz; m->matrix_array[1][1] = xz / xyz; m->matrix_array[1][2] = 0.0; m->matrix_array[1][3] = 0.0;
	m->matrix_array[2][0] = 0.0; m->matrix_array[2][1] = 0.0; m->matrix_array[2][2] = 1.0; m->matrix_array[2][3] = 0.0;
	m->matrix_array[3][0] = 0.0; m->matrix_array[3][1] = 0.0; m->matrix_array[3][2] = 0.0; m->matrix_array[3][3] = 1.0;

	return m;
}

Matrix* Matrix::get_rotation_matrix_m5(Vector* axis)
{
	Matrix* m = new Matrix(4, 4);

	double xz = sqrt(axis->x * axis->x + axis->z * axis->z);

	if (xz == 0.0) {
		m->matrix_array[0][0] = 1.0; m->matrix_array[0][1] = 0.0; m->matrix_array[0][2] = 0.0; m->matrix_array[0][3] = 0.0;
		m->matrix_array[1][0] = 0.0; m->matrix_array[1][1] = 1.0; m->matrix_array[1][2] = 0.0; m->matrix_array[1][3] = 0.0;
		m->matrix_array[2][0] = 0.0; m->matrix_array[2][1] = 0.0; m->matrix_array[2][2] = 1.0; m->matrix_array[2][3] = 0.0;
		m->matrix_array[3][0] = 0.0; m->matrix_array[3][1] = 0.0; m->matrix_array[3][2] = 0.0; m->matrix_array[3][3] = 1.0;
	}
	else {
		m->matrix_array[0][0] = axis->x / xz; m->matrix_array[0][1] = 0.0; m->matrix_array[0][2] = -axis->z / xz; m->matrix_array[0][3] = 0.0;
		m->matrix_array[1][0] = 0.0; m->matrix_array[1][1] = 1.0; m->matrix_array[1][2] = 0.0; m->matrix_array[1][3] = 0.0;
		m->matrix_array[2][0] = axis->z / xz; m->matrix_array[2][1] = 0.0; m->matrix_array[2][2] = axis->x / xz; m->matrix_array[2][3] = 0.0;
		m->matrix_array[3][0] = 0.0; m->matrix_array[3][1] = 0.0; m->matrix_array[3][2] = 0.0; m->matrix_array[3][3] = 1.0;
	}

	return m;
}

Matrix* Matrix::multiply(Matrix* l, Matrix* r)
{
	Matrix* m = new Matrix(4, 4);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; j++) {
			m->matrix_array[i][j] =
				l->matrix_array[i][0] * r->matrix_array[0][j] +
				l->matrix_array[i][1] * r->matrix_array[1][j] +
				l->matrix_array[i][2] * r->matrix_array[2][j] +
				l->matrix_array[i][3] * r->matrix_array[3][j];
		}
	}

	return m;
}

