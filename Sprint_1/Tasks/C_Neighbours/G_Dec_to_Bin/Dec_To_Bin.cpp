#include<iostream>

using namespace std;



int main() {
	int result[30];
	int n, rem;
	int counter = 0;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	while (n > 0) {
		rem = n % 2;
		n = n / 2;

		result[counter] = rem;
		counter++;
	}

	for (int i = counter - 1; i >= 0; --i) {
		cout << result[i];
	}
	cout << '\n';

	return 0;
}