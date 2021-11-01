#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab6.3.2\Main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int A[] = { 0, 4, -2, -8 };
			SortArray(A, 4, 0);
			Assert::AreEqual(0, A[2]);
		}
	};
}
