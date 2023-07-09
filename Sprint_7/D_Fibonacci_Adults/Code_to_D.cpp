#include<vector>
#include<iostream>
using namespace std;

int main() {
	int n;
	int q = 1000000007;
	cin >> n;
	vector<int> fibv(n + 1, 0);
	
	for (int i = 0; i <= n; i++) {
		if (i < 2) { 
			fibv[i] = 1;
		}
		else {
			fibv[i] = (fibv[i - 1] + fibv[i - 2]) % q;
		}
	}

	cout << fibv[n] << endl;

	return 0;
}