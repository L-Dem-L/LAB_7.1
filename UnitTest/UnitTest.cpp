#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_7.1/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestCreate)
		{
			const int rowCount = 8;
			const int colCount = 6;
			int** z = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				z[i] = new int[colCount];

			Create(z, rowCount, colCount, -10, 10); 

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					Assert::IsTrue(z[i][j] >= -10 && z[i][j] <= 10);

			for (int i = 0; i < rowCount; ++i)
				delete[] z[i];
			delete[] z;
		}

		TEST_METHOD(TestSort)
		{
			const int rowCount = 8;
			const int colCount = 6;
			int** z = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				z[i] = new int[colCount];

			int testArray[rowCount][colCount] = {
				{5, 3, 4, 2, 1, 6},
				{1, 2, 3, 4, 5, 6},
				{6, 5, 4, 3, 2, 1},
				{4, 3, 6, 5, 1, 2},
				{1, 2, 3, 4, 5, 6},
				{6, 5, 4, 3, 2, 1},
				{5, 3, 4, 2, 1, 6},
				{4, 3, 6, 5, 1, 2}
			};

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					z[i][j] = testArray[i][j];

			Sort(z, rowCount, colCount);

			for (int i = 0; i < rowCount - 1; ++i)
				Assert::IsTrue(z[i][0] >= z[i + 1][0] ||
					(z[i][0] == z[i + 1][0] && z[i][1] >= z[i + 1][1]) ||
					(z[i][0] == z[i + 1][0] && z[i][1] == z[i + 1][1] && z[i][3] <= z[i + 1][3]));

			for (int i = 0; i < rowCount; ++i)
				delete[] z[i];
			delete[] z;
		}

		TEST_METHOD(TestPrint)
		{
			const int rowCount = 8;
			const int colCount = 6;
			int** z = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				z[i] = new int[colCount];

			int testArray[rowCount][colCount] = {
				{1, 2, 3, 4, 5, 6},
				{7, 8, 9, 10, 11, 12},
				{13, 14, 15, 16, 17, 18},
				{19, 20, 21, 22, 23, 24},
				{25, 26, 27, 28, 29, 30},
				{31, 32, 33, 34, 35, 36},
				{37, 38, 39, 40, 41, 42},
				{43, 44, 45, 46, 47, 48}
			};

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					z[i][j] = testArray[i][j];

			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf()); // Redirect cout
			Print(z, rowCount, colCount);
			std::cout.rdbuf(old); // Restore cout

			std::string printedOutput = buffer.str();
			std::string expectedOutput = "\n   1   2   3   4   5   6\n"
				"   7   8   9  10  11  12\n"
				"  13  14  15  16  17  18\n"
				"  19  20  21  22  23  24\n"
				"  25  26  27  28  29  30\n"
				"  31  32  33  34  35  36\n"
				"  37  38  39  40  41  42\n"
				"  43  44  45  46  47  48\n\n";
			Assert::AreEqual(expectedOutput, printedOutput);

			for (int i = 0; i < rowCount; ++i)
				delete[] z[i];
			delete[] z;
		}


		TEST_METHOD(TestCalc)
		{
			const int rowCount = 8;
			const int colCount = 6;
			int** z = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				z[i] = new int[colCount];

			int testArray[rowCount][colCount] = {
				{1, 2, 3, 4, 5, 6},
				{-1, -2, -3, -4, -5, -6},
				{0, 0, 0, 0, 0, 0},
				{1, -1, 2, -2, 3, -3},
				{2, 4, 6, 8, 10, 12},
				{-2, -4, -6, -8, -10, -12},
				{1, 3, 5, 7, 9, 11},
				{-1, -3, -5, -7, -9, -11}
			};

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					z[i][j] = testArray[i][j];

			int S, k;
			Calc(z, rowCount, colCount, S, k);

			Assert::AreEqual(S, 56);
			Assert::AreEqual(k, 32); 

			for (int i = 0; i < rowCount; ++i)
				delete[] z[i];
			delete[] z;
		}
	};
}