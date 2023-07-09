#include "pch.h"
#include "CppUnitTest.h"
#include "../Final_Task_2/Final_Task_2.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YandexTesting
{
	TEST_CLASS(Final_Task_2_Test)
	{
	public:
		
		TEST_METHOD(Base_Test_1)
		{
			int n = 3;
			std::vector<int> digit_matrix(9, 0);
			ReadInputLines(digit_matrix, "1231");
			ReadInputLines(digit_matrix, "2..2");
			ReadInputLines(digit_matrix, "2..2");
			ReadInputLines(digit_matrix, "2..2");
			
			int correct_result = 2;
			int result = PossiblePayoff(digit_matrix, n * 2);

			Assert::AreEqual(correct_result, result);
		}

		TEST_METHOD(Base_Test_2)
		{
			int n = 4;
			std::vector<int> digit_matrix(9, 0);
			ReadInputLines(digit_matrix, "1111");
			ReadInputLines(digit_matrix, "9999");
			ReadInputLines(digit_matrix, "1111");
			ReadInputLines(digit_matrix, "9911");

			int correct_result = 1;
			int result = PossiblePayoff(digit_matrix, n * 2);

			Assert::AreEqual(correct_result, result);
		}

		TEST_METHOD(Corner_Cases_1)
		{
			int n = 1;
			std::vector<int> digit_matrix(9, 0);
			ReadInputLines(digit_matrix, "11..");
			ReadInputLines(digit_matrix, "....");
			ReadInputLines(digit_matrix, "....");
			ReadInputLines(digit_matrix, "....");

			int correct_result = 1;
			int result = PossiblePayoff(digit_matrix, n * 2);

			Assert::AreEqual(correct_result, result);
		}

		TEST_METHOD(Corner_Cases_2)
		{
			int n = 1;
			std::vector<int> digit_matrix(9, 0);
			ReadInputLines(digit_matrix, "111.");
			ReadInputLines(digit_matrix, "....");
			ReadInputLines(digit_matrix, "....");
			ReadInputLines(digit_matrix, "....");

			int correct_result = 0;
			int result = PossiblePayoff(digit_matrix, n * 2);

			Assert::AreEqual(correct_result, result);
		}
	};
}
