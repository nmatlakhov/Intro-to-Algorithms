#include<iostream>
#include<string>
using namespace std;

void parentheses_generator(int left_par,int right_par, string prefix) {
	if ((left_par == 0) && (right_par == 0)) {
		cout << prefix << endl;
	}
	else if(left_par > 0) {
		if (left_par == right_par) {
			parentheses_generator(left_par - 1, right_par, prefix + "(");
		}
		else {
			parentheses_generator(left_par - 1, right_par, prefix + "(");
			parentheses_generator(left_par, right_par - 1, prefix + ")");
		}
	}
	else if(right_par > 0) {
		parentheses_generator(left_par, right_par - 1, prefix + ")");
	}
}

int main() {
	int num_of_parentheses;
	cin >> num_of_parentheses;
	parentheses_generator(num_of_parentheses, num_of_parentheses, "");
	return 0;
}