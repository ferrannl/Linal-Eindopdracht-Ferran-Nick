#pragma once
#include "../Matrixes/Vector.hpp"
#include "../Matrixes/Matrix.hpp"
#include "../Objects/Object.hpp"

class Camera {
public:
	Vector* eye; // current pos needs to change using blue matrix
	Vector* look_at; // camera angle needs to change using black matrix

	Vector* _right;
	Vector* _up;
	Vector* _direction;

	//Perspectif matrix used for depth

	Matrix* get_eye_m(Vector* _eye);
	Matrix* get_look_at_m(Vector* _eye, Vector* _lookat);
	Matrix* get_pers_m();

	Matrix* get_eye_look_m();

	Matrix* get_camera_m();

	bool thirdperson = false;

	Object* tracked_object;

	Camera();

	//je pakt eye maakt matrix die het zou verplaatsen naar 0,0,0
	//je pakt look at maakt een matrix voor draaien naar direction of naar z as
	//je pakt perspectif matrix voor diepte

	//voeg ze bij elkaar

	//maak een copy van de objecten
	//loop erover heen en pas alles aan, aan de hand van die matrix
	//teken deze objecten met hun x en y met SDL_drawline
};