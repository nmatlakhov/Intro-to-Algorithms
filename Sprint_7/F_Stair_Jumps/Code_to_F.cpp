#include<vector>
#include<iostream>
using namespace std;

int main() {
	int n,k;
	int q = 1000000007;
	cin >> n >> k;
	vector<int> njumps(n, 0);
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= min(k, i); j++) {
			njumps[i] = (njumps[i] + njumps[i - j]) % q;
		}
		if (i <= k) {
			njumps[i] = (njumps[i] + 1) % q;
		}

	}

	cout << njumps[n - 1] << endl;

	return 0;
}