#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool lessVal(const string& val_1, const string& val_2) {
	int n, num1 = val_1.size(), num2 = val_2.size();
	int temp_1, temp_2;
	n = num1 * num2;
	for (int i = 0; i < n; i++) {
		temp_1 = val_1[i % num1] - '0';
		temp_2 = val_2[i % num2] - '0';
		if (temp_1 > temp_2) { return false; } else if (temp_1 < temp_2) { return true; }
	}
	return false;
}

void sortByNum(vector<string>& values) {
	int n = values.size();
	string temp;
	for (int i = 1; i < n; i++) {
		temp = values[i];
		int j = i;
		while ((j > 0) && lessVal(temp, values[j - 1])) {
			values[j] = values[j - 1];
			j -= 1;
		}
		values[j] = temp;
	}
}

void printNumber(vector<string>& values) {
	for (auto it = values.rbegin(); it != values.rend(); it++) {
		cout << *it;
	}
}

int main() {
	int n;
	cin >> n;
	vector<string> numbers(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	sortByNum(numbers);
	printNumber(numbers);
		
	return 0;
}