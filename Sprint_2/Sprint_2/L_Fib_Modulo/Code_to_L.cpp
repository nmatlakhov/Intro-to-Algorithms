#include<iostream>
#include<cmath>
using namespace std;

int Fib(int n, int dec) {
	int last = 1;
	int prev_last = 1;
	if ((n == 0) || (n == 1)) {
		return 1;
	}

	for (int i = 2; i <= n; i++) {
		int new_val = (last + prev_last) % dec;
		prev_last = last;
		last = new_val;
	}
	
	return last;
	
}

int main() {
	int n,k, dec;
	cin >> n >> k;
	dec = pow(10, k);
	cout << Fib(n, dec) << endl;
	return 0;
}