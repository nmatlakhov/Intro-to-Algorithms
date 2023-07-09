#include<iostream>
using namespace std;

int main() {
	int n, X = 0, K,temp_int;
	int res[5], counter = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp_int;
		X = X*10 + temp_int;
	}

	cin >> K;
	X += K;
	
	while (X > 0) {
		temp_int = X % 10;
		res[counter] = temp_int;
		X = (X - temp_int) / 10;
		counter++;
	}

	for (int i = counter - 1; i >= 0; i--) {
		cout << res[i] << " ";
	}

	return 0;
}