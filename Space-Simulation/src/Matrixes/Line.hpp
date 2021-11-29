#pragma once
#include "../Matrixes/Vector.hpp"
#include <vector>
class Line {
public:
	Vector* begin;
	Vector* end;
	Line(Vector* begin, Vector* end);
};
