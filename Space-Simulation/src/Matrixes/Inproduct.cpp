#include "../Matrixes/Inproduct.hpp"
#include "../Matrixes/Matrix.hpp"
#include <math.h>
#define PI 3.14159265

double Inproduct::in_product(Vector v1, Vector v2)
{
	Vector mul = v1;
	double top = mul.mul(v2);

	double sqv1 = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	double sqv2 = sqrt(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z);

	double bot = sqv1 * sqv2;

	double res = top / bot;

	return acos(res) * 180 / PI;
}
