#include<iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	if (n == 0) {
		cout << "False";
		return 0;
	}

	while (n != 1) {
		if (n % 4 != 0) {
			cout << "False";
			return 0;
		}
		n = n / 4;
	}


	cout << "True";
	
	return 0;
}