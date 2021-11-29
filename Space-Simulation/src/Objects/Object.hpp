#pragma once
#include <vector>
#include "../Matrixes/Line.hpp"
#include "../Matrixes/Matrix.hpp"
#include <sstream>
class Object {

public:
	bool growing;
	int growth_counter;
	std::vector<Line*> lines;
	std::vector<Vector*> vectors;
	Matrix* translation_matrix_pos_x;
	Matrix* translation_matrix_pos_y;
	Matrix* translation_matrix_neg_x;
	Matrix* translation_matrix_neg_y;
	Matrix* translation_matrix_pos_z;
	Matrix* translation_matrix_neg_z;

	Matrix* translation_matrix_heading_pos();

	Matrix* rotation_matrix_pos_x;
	Matrix* rotation_matrix_pos_y;
	Matrix* rotation_matrix_neg_x;
	Matrix* rotation_matrix_neg_y;
	Matrix* rotation_matrix_pos_z;
	Matrix* rotation_matrix_neg_z;

	Vector* get_local_x_axis();
	Vector* get_local_y_axis();
	Vector* get_local_z_axis();
	Vector* get_center();

	Vector* front;
	Vector* back;

	Vector* camera;
	Vector* get_heading();
	Vector* get_gun_heading();

	double velocity = 0;

	Matrix* heading;

	Vector* v_heading;

	Vector* gun_location();

	int counter_should_act = 0;

	Object();

	std::string type;

	void transform(Matrix* matrix);

	virtual void act() = 0;

	Matrix* calculate_matrix(Vector* rotation, Vector* centrum, double degrees);

	bool check_collision(Object* bullet);

	Vector* get_min();
	Vector* get_max();

	std::vector<Object*> sub_objects;
};