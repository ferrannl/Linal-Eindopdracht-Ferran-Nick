#include "pch.h"
#include "CppUnitTest.h"
#include "../Space-Simulation/src/Matrixes/Matrix.hpp"
#include "../Space-Simulation/src/Matrixes/Matrix.cpp"
#include "../Space-Simulation/src/Matrixes/Vector.hpp"
#include "../Space-Simulation/src/Matrixes/Vector.cpp"
#include <math.h>
#define M_PI 3.14159265

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(Fill_array)
		{
			Matrix* m1 = new Matrix(4, 4);
			Matrix* ma = new Matrix(4, 4);
			ma->matrix_array[0][0] = 0.0; ma->matrix_array[0][1] = 0.0; ma->matrix_array[0][2] = 0.0; ma->matrix_array[0][3] = 0.0;
			ma->matrix_array[1][0] = 0.0; ma->matrix_array[1][1] = 0.0; ma->matrix_array[1][2] = 0.0; ma->matrix_array[1][3] = 0.0;
			ma->matrix_array[2][0] = 0.0; ma->matrix_array[2][1] = 0.0; ma->matrix_array[2][2] = 0.0; ma->matrix_array[2][3] = 0.0;
			ma->matrix_array[3][0] = 0.0; ma->matrix_array[3][1] = 0.0; ma->matrix_array[3][2] = 0.0; ma->matrix_array[3][3] = 0.0;

			m1->fill_array(0);

			Assert::AreEqual(m1, ma);
		}

		TEST_METHOD(Add)
		{
			Matrix* m1 = new Matrix(4, 4);
			Matrix* m2 = new Matrix(4, 4);
			Matrix* ma = new Matrix(4, 4);

			m1->fill_array(1);
			m2->fill_array(2);
			ma->fill_array(3);

			Assert::AreEqual(ma, m1->add(m2));
		}

		TEST_METHOD(Sub)
		{
			Matrix* m1 = new Matrix(4, 4);
			Matrix* m2 = new Matrix(4, 4);
			Matrix* ma = new Matrix(4, 4);
			Matrix* mb = new Matrix(4, 4);

			m1->fill_array(2);
			m2->fill_array(3);
			ma->fill_array(1);
			mb = m1->sub(m2);

			Assert::AreEqual(ma, mb);
		}

		TEST_METHOD(Mul_scalair)
		{
			Matrix* m1 = new Matrix(4, 4);
			Matrix* m2 = new Matrix(4, 4);
			Matrix* ma = new Matrix(4, 4);

			m1->fill_array(2);
			m2 = m1->mul_scalair(2);
			ma->fill_array(4);

			Assert::AreEqual(m2, ma);
		}

		TEST_METHOD(Get_scaling_matrix)
		{
			Matrix* m1 = new Matrix(4, 4);
			Matrix* m2 = new Matrix(4, 4);
			Matrix* m3 = new Matrix(4, 4);

			m1->fill_array(1);
			m2 = m1->get_scaling_matrix(1, 1, 1);

			m3->matrix_array[0][0] = 1.0; m3->matrix_array[0][1] = 0.0; m3->matrix_array[0][2] = 0.0; m3->matrix_array[0][3] = 0.0;
			m3->matrix_array[1][0] = 0.0; m3->matrix_array[1][1] = 1.0; m3->matrix_array[1][2] = 0.0; m3->matrix_array[1][3] = 0.0;
			m3->matrix_array[2][0] = 0.0; m3->matrix_array[2][1] = 0.0; m3->matrix_array[2][2] = 1.0; m3->matrix_array[2][3] = 0.0;
			m3->matrix_array[3][0] = 0.0; m3->matrix_array[3][1] = 0.0; m3->matrix_array[3][2] = 0.0; m3->matrix_array[3][3] = 1.0;

			Assert::AreEqual(m2, m3);
		}

		TEST_METHOD(Get_translation_matrix)
		{
			Matrix* m1 = new Matrix(4, 4);
			Matrix* m2 = new Matrix(4, 4);


			m1->fill_array(1);
			m2 = m1->get_translation_matrix(1, 1, 1);
			Matrix* m3 = new Matrix(4, 4);
			m3->matrix_array[0][0] = 1.0; m3->matrix_array[0][1] = 0.0; m3->matrix_array[0][2] = 0.0; m3->matrix_array[0][3] = 1.0;
			m3->matrix_array[1][0] = 0.0; m3->matrix_array[1][1] = 1.0; m3->matrix_array[1][2] = 0.0; m3->matrix_array[1][3] = 1.0;
			m3->matrix_array[2][0] = 0.0; m3->matrix_array[2][1] = 0.0; m3->matrix_array[2][2] = 1.0; m3->matrix_array[2][3] = 1.0;
			m3->matrix_array[3][0] = 0.0; m3->matrix_array[3][1] = 0.0; m3->matrix_array[3][2] = 0.0; m3->matrix_array[3][3] = 1.0;

			Assert::AreEqual(m2, m3);
		}

		TEST_METHOD(Get_rotation_matrix_x)
		{
			Matrix* m1 = new Matrix(4, 4);


			m1 = m1->get_rotation_matrix_x(90);

			double a = (double)90 / 180 * M_PI;

			Matrix* ma = new Matrix(4, 4);
			ma->matrix_array[0][0] = 1; ma->matrix_array[0][1] = 0.0; ma->matrix_array[0][2] = 0.0; ma->matrix_array[0][3] = 0.0;
			ma->matrix_array[1][0] = 0.0; ma->matrix_array[1][1] = cos(a); ma->matrix_array[1][2] = -sin(a); ma->matrix_array[1][3] = 0.0;
			ma->matrix_array[2][0] = 0.0; ma->matrix_array[2][1] = sin(a); ma->matrix_array[2][2] = cos(a); ma->matrix_array[2][3] = 0.0;
			ma->matrix_array[3][0] = 0.0; ma->matrix_array[3][1] = 0.0; ma->matrix_array[3][2] = 0.0; ma->matrix_array[3][3] = 1;

			Assert::AreEqual(m1, ma);
		}

		TEST_METHOD(Get_rotation_matrix_y)
		{
			Matrix* m1 = new Matrix(4, 4);


			m1 = m1->get_rotation_matrix_y(90);

			double a = (double)90 / 180 * M_PI;
			Matrix* ma = new Matrix(4, 4);
			ma->matrix_array[0][0] = cos(a); ma->matrix_array[0][1] = 0.0; ma->matrix_array[0][2] = sin(a); ma->matrix_array[0][3] = 0.0;
			ma->matrix_array[1][0] = 0.0; ma->matrix_array[1][1] = 1.0; ma->matrix_array[1][2] = 0.0; ma->matrix_array[1][3] = 0.0;
			ma->matrix_array[2][0] = -sin(a); ma->matrix_array[2][1] = 0.0; ma->matrix_array[2][2] = cos(a); ma->matrix_array[2][3] = 0.0;
			ma->matrix_array[3][0] = 0.0; ma->matrix_array[3][1] = 0.0; ma->matrix_array[3][2] = 0.0; ma->matrix_array[3][3] = 1.0;

			Assert::AreEqual(m1, ma);
		}

		TEST_METHOD(Get_rotation_matrix_z)
		{
			Matrix* m1 = new Matrix(4, 4);


			m1 = m1->get_rotation_matrix_z(90);

			double a = (double)90 / 180 * M_PI;
			Matrix* ma = new Matrix(4, 4);
			double z = cos(a);
			ma->matrix_array[0][0] = cos(a); ma->matrix_array[0][1] = -sin(a); ma->matrix_array[0][2] = 0.0; ma->matrix_array[0][3] = 0.0;
			ma->matrix_array[1][0] = sin(a); ma->matrix_array[1][1] = cos(a); ma->matrix_array[1][2] = 0.0; ma->matrix_array[1][3] = 0.0;
			ma->matrix_array[2][0] = 0.0; ma->matrix_array[2][1] = 0.0; ma->matrix_array[2][2] = 1.0; ma->matrix_array[2][3] = 0.0;
			ma->matrix_array[3][0] = 0.0; ma->matrix_array[3][1] = 0.0; ma->matrix_array[3][2] = 0.0; ma->matrix_array[3][3] = 1.0;

			Assert::AreEqual(m1, ma);
		}

		TEST_METHOD(Multiply)
		{
			Matrix* m1 = new Matrix(4, 4);
			Matrix* m2 = new Matrix(4, 4);
			Matrix* ma = new Matrix(4, 4);

			m1->fill_array(2);
			m2->fill_array(3);
			ma->fill_array(24);

			m1 = m1->multiply(m2, m1);

			Assert::AreEqual(ma, m1);
		}


	};
}