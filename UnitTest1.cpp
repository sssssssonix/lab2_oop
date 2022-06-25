#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2_oop/lab2_oop.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			QuickSort Arr1;
			int count = 0;
			int obtained[] = { -121, 0, 5, 16, 99 }; 
			int expected[] = { 5, 16, -121, 99, 0 };
			Arr1.Quicksort(expected, 0, 4);
			for (int i = 0; i < 5; i++) {
				if (expected[i] == obtained[i])
					count += 1;
				if (count == 5)
					Logger::WriteMessage("Test1 passed");
			}
		}

		TEST_METHOD(Test2)
		{
			QuickSort Arr1;
			int count = 0;
			int obtained[] = { 13, -3, 13, 13 };
			int expected[] = { -3, 13, 13, 13 };
			Arr1.Insert(&expected[], 0, 3);
			for (int i = 0; i < 4; i++) {
				if (expected[i] == obtained[i])
					count += 1;
				if (count == 4)
					Logger::WriteMessage("Test2 passed");
			}
		}


	};
}
