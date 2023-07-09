#include<iostream>
using namespace std;
//static const int CatalanNumbers[21] =
//{
//	1, 1, 2, 5, 14,42,132,429,1430,4862,16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 656412042
//};

long long calcDPNumbers(int n) {
	int max_val = n + 1;
	if (max_val >= 21) { max_val = 21; }
	long long* G = new long long [max_val] {0};
	long long temp;

	G[0] = G[1] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			temp = G[j - 1] * G[i - j];
			G[i] = G[i] + temp;
			
		}
	}

	return G[n];
}

int main() {
	int n;
	cin >> n;

	cout << calcDPNumbers(n) << endl;
	/*cout << CatalanNumbers[n] << endl;*/

	return 0;
}