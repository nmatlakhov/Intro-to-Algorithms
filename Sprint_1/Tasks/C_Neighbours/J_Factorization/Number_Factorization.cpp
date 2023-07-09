#include<iostream>
using namespace std;

int main() {
	int n, i =2;

	cin >> n;

	while (i * i <= n) {
		while (n % i == 0) {
			n = n / i;
			cout << i << " ";
		}
		i = i + 1;
	}
	if (n != 1) {
		cout << n << " ";
	}
	


	return 0;
}