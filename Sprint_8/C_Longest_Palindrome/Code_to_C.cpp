#include<string>
#include<iostream>
using namespace std;

int main() {
	int alpha[26] = { 0 };
	string line;
	getline(cin, line);

	for (size_t i = 0; i < line.size(); i++) {
		alpha[line[i] - 'a']++;
	}

	string palindrome = "", reverse = "";
	int check_num = -1;

	for (int i = 0; i < 26; i++) {

		if (alpha[i] > 0) {
			string temp( alpha[i] / 2, 'a' + i);
			alpha[i] -= 2*(alpha[i] / 2);
			palindrome = palindrome + temp;
			reverse = temp + reverse;
			
			if ((check_num == -1) & (alpha[i] == 1)) {
				check_num = i;
			}
		}

	}

	if (check_num > -1) {
		palindrome += 'a' + check_num;
	}
	palindrome += reverse;

	cout << palindrome << endl;

	return 0;
}