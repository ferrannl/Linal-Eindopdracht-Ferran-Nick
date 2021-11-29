#include "../Simulation/Camera.hpp"
#include "Math.h"
#include "../Matrixes/Outproduct.hpp"
#define PI 3.14159265

Matrix* Camera::get_eye_m(Vector* _eye)
{
	Matrix* m = new Matrix(4, 4);
	m->matrix_array[0][0] = 1.0; m->matrix_array[0][1] = 0.0; m->matrix_array[0][2] = 0.0; m->matrix_array[0][3] = -_eye->x;
	m->matrix_array[1][0] = 0.0; m->matrix_array[1][1] = 1.0; m->matrix_array[1][2] = 0.0; m->matrix_array[1][3] = -_eye->y;
	m->matrix_array[2][0] = 0.0; m->matrix_array[2][1] = 0.0; m->matrix_array[2][2] = 1.0; m->matrix_array[2][3] = -_eye->z;
	m->matrix_array[3][0] = 0.0; m->matrix_array[3][1] = 0.0; m->matrix_array[3][2] = 0.0; m->matrix_array[3][3] = 1.0;
	return m;
}

Matrix* Camera::get_look_at_m(Vector* _eye, Vector* _look_at)
{
	Vector tussen = *_eye;
	tussen.sub(*_look_at);
	//direction//lookat
	_direction = new Vector(tussen.x, tussen.y, tussen.z);
	_direction->normalize();

	//pak right
	_right = Outproduct::out_product(*_up, *_direction);
	_right->normalize();

	//up
	_up = Outproduct::out_product(*_direction, *_right);
	_up->normalize();

	//Matrix
	Matrix* m = new Matrix(4, 4);
	m->matrix_array[0][0] = _right->x; m->matrix_array[0][1] = _right->y; m->matrix_array[0][2] = _right->z; m->matrix_array[0][3] = 0.0;
	m->matrix_array[1][0] = _up->x; m->matrix_array[1][1] = _up->y; m->matrix_array[1][2] = _up->z; m->matrix_array[1][3] = 0.0;
	m->matrix_array[2][0] = _direction->x; m->matrix_array[2][1] = _direction->y; m->matrix_array[2][2] = _direction->z; m->matrix_array[2][3] = 0.0;
	m->matrix_array[3][0] = 0.0; m->matrix_array[3][1] = 0.0; m->matrix_array[3][2] = 0.0; m->matrix_array[3][3] = 1.0;

	return m;
}

Matrix* Camera::get_pers_m()
{
	double near = 0.1;
	double far = 10000;
	double fov = 60;
	double scale = near * tan(fov / 180 * PI * 0.5);
	Matrix* m = new Matrix(4, 4);
	m->matrix_array[0][0] = scale; m->matrix_array[0][1] = 0.0; m->matrix_array[0][2] = 0.0; m->matrix_array[0][3] = 0.0;
	m->matrix_array[1][0] = 0.0; m->matrix_array[1][1] = scale; m->matrix_array[1][2] = 0.0; m->matrix_array[1][3] = 0.0;
	m->matrix_array[2][0] = 0.0; m->matrix_array[2][1] = 0.0; m->matrix_array[2][2] = -far / (far - near); m->matrix_array[2][3] = -1.0;
	m->matrix_array[3][0] = 0.0; m->matrix_array[3][1] = 0.0; m->matrix_array[3][2] = (-far * near) / (far - near); m->matrix_array[3][3] = 0.0;
	return m;
}

Matrix* Camera::get_eye_look_m()
{
	Matrix* m = new Matrix(4, 4);
	if (thirdperson) {

		m = m->multiply(get_look_at_m(tracked_object->camera, tracked_object->get_heading()), get_eye_m(tracked_object->camera));
	}
	else {
		m = m->multiply(get_look_at_m(eye, look_at), get_eye_m(eye));
	}
	return m;
}

Matrix* Camera::get_camera_m()
{

	Matrix* m = new Matrix(4, 4);
	Matrix* z = new Matrix(4, 4);
	if (thirdperson) {
		m = m->multiply(get_pers_m(), get_look_at_m(tracked_object->camera, tracked_object->get_heading()));

		z = z->multiply(m, get_eye_m(tracked_object->camera));
	}
	else {
		m = m->multiply(get_pers_m(), get_look_at_m(eye, look_at));

		z = z->multiply(m, get_eye_m(eye));
	}
	delete m;
	return z;
}

Camera::Camera()
{
	eye = new Vector(0, 0, 100);
	look_at = new Vector(0, 0, -100);
	_up = new Vector(0, -10, 0);
}
