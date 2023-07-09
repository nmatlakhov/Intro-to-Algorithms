#include<iostream>
#include<algorithm>
#include<vector>
#include <iomanip>  
using namespace std;


int GetKElement(vector<int>& a, int a_size, vector<int>& b, int b_size, int k) {
	if (a_size > b_size) {
		return GetKElement(b, b_size, a, a_size, k);
	}

	if (a.empty()) {
		return b[k - 1];
	}

	if (k == 1) {
		return min(a[a.size() - a_size], b[b.size() - b_size]);
	}

	int i = min(a_size, k / 2);
	int j = min(b_size, k / 2);

	if (a[i - 1] > b[j - 1]) {
		return GetKElement(a, a_size, b, b_size - j, k - j);
	}
	else {
		return GetKElement(a, a_size - i, b, b_size, k - i);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> north(n), south(m);
	for (int i = 0; i < n; i++) {
		cin >> north[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> south[j];
	}
	
	int med = 

	return 0;
}