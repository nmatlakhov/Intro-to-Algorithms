/* ID 74526436 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int PossiblePayoff(const vector<int>& matrix, int total_key) { 
	int payoff = 0;

	for (int k = 0; k < matrix.size(); k++) {
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
	vector<int> digit_matrix(9,0);		//Вектор размера 9, поскольку 0 исключен.
	cin >> key_per_person;

	for (int j = 0; j < 4; ++j) {
		string inp_line;
		cin >> inp_line;
		ReadInputLines(digit_matrix, inp_line);
	}


	print(PossiblePayoff(digit_matrix,key_per_person*2));
	return 0;
}