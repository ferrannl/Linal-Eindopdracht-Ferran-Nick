#include "../Matrixes/Outproduct.hpp"

Vector* Outproduct::out_product(Vector v1, Vector v2)
{
	Vector* res = new Vector(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
	return res;
}
