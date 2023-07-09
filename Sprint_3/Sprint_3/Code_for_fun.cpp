#include<iostream>
#include<string>
using namespace std;

string as_binary_string(int n) {
	if (n < 0) {
		return "-" + as_binary_string(-n);
	}
	if ((n == 0) || (n == 1)) {
		return to_string(n);
	}
	int last_digit;
	last_digit = n % 2;
	return as_binary_string(n / 2) + to_string(last_digit);
}

void gen_binary(int n, string prefix) {
	if (n == 0) {
		cout << prefix << endl;
	}
	else {
		gen_binary(n - 1, prefix + "0");
		gen_binary(n - 1, prefix + "1");
	}
}

int main() {
	//cout << as_binary_string(4) << endl;
	gen_binary(10,"");
	return 0;
}