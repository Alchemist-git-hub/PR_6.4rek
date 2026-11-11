#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.4rek/pr6.4r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testPR64rek
{
	TEST_CLASS(testPR64rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a[] = { -5, 3, -2, 4, -1 };
			Assert::IsTrue(SumNegative(a, 5) == -8);
		}
		TEST_METHOD(TestMethod2)
		{
			double a[] = { 3, 5, 8, 7, 4 };

			Assert::IsTrue(FindNextEven(a, 5, 0) == 2);
		}
	};
}
