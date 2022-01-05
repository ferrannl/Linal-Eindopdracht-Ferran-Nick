#include "../Controllers/MainController.hpp"

MainController::MainController()
{
	world = new World();
	camera = new Camera();
}

void MainController::input(SDL_Event event)
{
	switch (event.key.keysym.sym) {
		//toggle first person
	case SDLK_c:
		if (camera->thirdperson) {
			camera->thirdperson = false;
		}
		else {
			camera->thirdperson = true;
			camera->tracked_object = world->controlled_object;
		}
		break;

	case SDLK_PAGEUP:
		camera->eye->z -= 10;
		camera->look_at->z -= 10;
		break;
	case SDLK_PAGEDOWN:
		camera->eye->z += 10;
		camera->look_at->z += 10;
		break;
	case SDLK_RIGHT:
		camera->eye->x -= 10;
		camera->look_at->x -= 10;
		break;
	case SDLK_LEFT:
		camera->eye->x += 10;
		camera->look_at->x += 10;
		break;
	case SDLK_UP:
		camera->eye->y += 10;
		camera->look_at->y += 10;
		break;
	case SDLK_DOWN:
		camera->eye->y -= 10;
		camera->look_at->y -= 10;
		break;
	case SDLK_HOME:
		camera->look_at->x += 10;
		break;
	case SDLK_END:
		camera->look_at->x -= 10;
		break;
	case SDLK_INSERT:
		camera->look_at->y -= 10;
		break;
	case SDLK_DELETE:
		camera->look_at->y += 10;
		break;

	case SDLK_w:
	{
		Vector* vector3 = world->controlled_object->get_local_y_axis();
		vector3->normalize();
		Vector* centrum3 = world->controlled_object->get_center();

		Matrix* matrix3 = world->controlled_object->calculate_matrix(vector3, centrum3, 5.0);
		world->controlled_object->transform(matrix3);
		break;
	}
	case SDLK_s:
	{
		Vector* vector4 = world->controlled_object->get_local_y_axis();
		vector4->normalize();
		Vector* centrum4 = world->controlled_object->get_center();

		Matrix* matrix4 = world->controlled_object->calculate_matrix(vector4, centrum4, -5.0);
		world->controlled_object->transform(matrix4);
	}
	break;
	//qe roll
	case SDLK_q:
	{
		Vector* vector = world->controlled_object->get_local_x_axis();
		vector->normalize();
		Vector* centrum1 = world->controlled_object->get_center();

		Matrix* matrix = world->controlled_object->calculate_matrix(vector, centrum1, 5.0);
		world->controlled_object->transform(matrix);
	}
	break;
	case SDLK_e:
	{
		Vector* vector2 = world->controlled_object->get_local_x_axis();
		vector2->normalize();
		Vector* centrum2 = world->controlled_object->get_center();

		Matrix* matrix2 = world->controlled_object->calculate_matrix(vector2, centrum2, -5.0);
		world->controlled_object->transform(matrix2);
	}
	break;
	//Yaw ad
	case SDLK_d:
	{
		Vector* vector5 = world->controlled_object->get_local_z_axis();
		vector5->normalize();
		Vector* centrum5 = world->controlled_object->get_center();

		Matrix* matrix5 = world->controlled_object->calculate_matrix(vector5, centrum5, 5.0);
		world->controlled_object->transform(matrix5);
	}
	break;
	case SDLK_a:
	{
		Vector* vector6 = world->controlled_object->get_local_z_axis();
		vector6->normalize();
		Vector* centrum6 = world->controlled_object->get_center();

		Matrix* matrix6 = world->controlled_object->calculate_matrix(vector6, centrum6, -5.0);
		world->controlled_object->transform(matrix6);
	}
	break;
	//gas = shift
	case SDLK_LSHIFT:
	{
		world->controlled_object->velocity += 0.1;
	}
	break;
	case SDLK_LCTRL:
	{
		world->controlled_object->velocity -= 0.1;
	}
	break;
	//shoot bullet
	case SDLK_SPACE:
		world->shoot_bullet();
		break;
	}
}

int MainController::simulate()
{
	return world->simulate();

}

void MainController::draw(SDL_Renderer* gRenderer)
{
	Matrix* m = camera->get_camera_m();
	int startPointCanvasX = SCREEN_WIDTH / 2;
	int startPointCanvasY = SCREEN_HEIGHT / 2;

	SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
	for (auto o : world->objects) {
		for (int i = 0; i < o->lines.size(); ++i) {
			Vector* begin = o->lines[i]->begin->transformed_copy(m);
			Vector* end = o->lines[i]->end->transformed_copy(m);

			begin->x = startPointCanvasX + ((begin->x / begin->w) * startPointCanvasX);
			begin->y = startPointCanvasY + ((begin->y / begin->w) * startPointCanvasY);
			end->x = startPointCanvasX + ((end->x / end->w) * startPointCanvasX);
			end->y = startPointCanvasY + ((end->y / end->w) * startPointCanvasY);

			if (begin->w > 0 && end->w > 0) {
				//SDL_RenderDrawLine(gRenderer, nulpuntCanvasX + begin->x, nulpuntCanvasY + begin->y, nulpuntCanvasX + end->x, nulpuntCanvasY + end->y);
				SDL_RenderDrawLine(gRenderer, begin->x, begin->y, end->x, end->y);
			}
			delete begin;
			delete end;
		}
	}
	delete m;
}
