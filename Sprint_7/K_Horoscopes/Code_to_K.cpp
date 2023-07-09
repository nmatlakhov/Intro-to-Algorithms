#include<iostream>
#include<vector>
using namespace std;

struct lcs_res {
	int size;
	vector<int> indices_A, indices_B;
};

lcs_res LCS(vector<int>& A, vector<int>& B, int n, int m) {
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	lcs_res result({ 0, {}, {} });
	result.size = dp[n][m];
	
	int i = n, j = m;
	while (dp[i][j] > 0) {
		if (A[i - 1] == B[j - 1]) {
			result.indices_A.push_back(i);
			result.indices_B.push_back(j);
			i--;
			j--;
		}
		else {
			if (dp[i][j] == dp[i - 1][j]) {
				i--;
			}
			else {
				j--;
			}
		}

	}

	return result;
}

int main() {
	int n, m, temp_val;
	cin >> n;

	vector<int> A(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> temp_val;
		A[i] = temp_val;
	}

	cin >> m;
	vector<int> B(m, 0);
	for (int j = 0; j < m; j++) {
		cin >> temp_val;
		B[j] = temp_val;
	}

	lcs_res result = LCS(A,B,n,m);
	cout << result.size << endl;

	for (auto it = result.indices_A.rbegin(); it != result.indices_A.rend(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	for (auto it = result.indices_B.rbegin(); it != result.indices_B.rend(); it++) {
		cout << *it << " ";
	}

	return 0;
}