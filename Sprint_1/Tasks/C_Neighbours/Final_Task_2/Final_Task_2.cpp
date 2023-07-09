/* https://contest.yandex.ru/contest/22450/run-report/74888032/ */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int PossiblePayoff(const vector<int>& matrix, int total_key) { 
	int payoff = 0;
	int m_size = matrix.size();
	for (int k = 0; k < m_size; k++) {
		if ((matrix[k] <= total_key) && (matrix[k] > 0)) { payoff++; }
	}

	return payoff;
}

void ReadInputLines(vector<int>& matrix, const string& inp_line) {
	for (auto it = inp_line.begin(); it != inp_line.end(); it++) {
		if (*it != '.') { matrix[*it - '1']++; }
	}
}

void print(int result) {
	cout << result << endl;
}

int main() {
	int key_per_person;
	constexpr const int number_of_digits = 9; // Количество цифр равно 9, поскольку исключаем 0
	constexpr const int number_of_line_inputs = 4; // Количество строк с вводимыми цифрами

	vector<int> digit_matrix(number_of_digits,0);		
	cin >> key_per_person;

	for (int j = 0; j < number_of_line_inputs; ++j) {
		string inp_line;
		cin >> inp_line;
		ReadInputLines(digit_matrix, inp_line);
	}


	print(PossiblePayoff(digit_matrix,key_per_person*2));
	return 0;
}