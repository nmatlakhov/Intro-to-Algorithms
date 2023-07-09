#include "pch.h"
#include "CppUnitTest.h"
#include "../Final_Task_1/Final_Task_1.cpp"


bool check_vectors(std::vector<int>& first_vec, std::vector<int>& second_vec) {
	if(first_vec.size() != second_vec.size()) {
		return false;
	}
	for (unsigned int i = 0; i < first_vec.size(); i++) {
		if (first_vec[i] != second_vec[i]) {
			return false;
		}
	}
	return true;
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YandexTesting
{
	TEST_CLASS(UnitTestingFinalTask1)
	{
	public:
		
		TEST_METHOD(Yandex_Test_1)
		{
			
			std::vector<int> seq_1 = { 0, 1, 5, 9 , 0 };
			std::vector<int> seq_2 = { 0, 1, 2, 1 , 0 };
			minDistance(seq_1);
			bool check = check_vectors(seq_1,seq_2);
			Assert::AreEqual(true, check);
			
		}

		TEST_METHOD(Yandex_Test_2)
		{

			std::vector<int> seq_1 = { 0, 7,  9,  4,  8,  20 };
			std::vector<int> seq_2 = { 0, 1, 2, 3 , 4, 5 };
			minDistance(seq_1);
			bool check = check_vectors(seq_1, seq_2);
			Assert::AreEqual(true, check);

		}


		TEST_METHOD(Check_Right)
		{

			std::vector<int> seq_1 = { 1, 7,  9,  4,  8,  0 };
			std::vector<int> seq_2 = { 5, 4, 3, 2 , 1, 0 };
			minDistance(seq_1);
			bool check = check_vectors(seq_1, seq_2);
			Assert::AreEqual(true, check);

		}

		TEST_METHOD(Check_Zeros)
		{

			std::vector<int> seq_1 = { 0, 0,  0,  0,  0,  0 };
			std::vector<int> seq_2 = { 0,0 , 0, 0 , 0, 0 };
			minDistance(seq_1);
			bool check = check_vectors(seq_1, seq_2);
			Assert::AreEqual(true, check);

		}

		TEST_METHOD(Check_Eight)
		{

			std::vector<int> seq_1 = { 1,1,  0,  1,  1,  0, 1 ,1 };
			std::vector<int> seq_2 = { 2,1 , 0, 1 , 1, 0 ,1,2};
			minDistance(seq_1);
			bool check = check_vectors(seq_1, seq_2);
			Assert::AreEqual(true, check);

		}

		TEST_METHOD(Check_Nine)
		{

			std::vector<int> seq_1 = { 1,1,  0,  1, 1,  1,  0, 1 ,1 };
			std::vector<int> seq_2 = { 2,1 , 0, 1 ,2, 1, 0 ,1,2 };
			minDistance(seq_1);
			bool check = check_vectors(seq_1, seq_2);
			Assert::AreEqual(true, check);

		}
	};
}
