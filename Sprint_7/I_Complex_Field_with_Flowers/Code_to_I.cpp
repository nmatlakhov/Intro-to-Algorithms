#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

pair<int, vector<char>> max_flowers(vector<vector<int>>& field, int n, int m) {

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = numeric_limits<int>::min();
	}

	for (int j = 0; j <= m; j++) {
		dp[0][j] = numeric_limits<int>::min();
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((i == 1) & (j == 1)) {
				dp[i][j] = field[0][0];
			}
			else {
				//cout << i << " " << j << " " << dp[i - 1][j] << " " << dp[i][j - 1] << " " << field[i - 1][j - 1] << endl;
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + field[i - 1][j - 1];
			}
		}
	}

	int final_value = dp[n][m];
	vector<char> result;
	int i = n, j = m;
	while ((i > 1) || (j > 1)) {
		if (dp[i - 1][j] > dp[i][j - 1]) {
			result.push_back('U');
			i--;
		}
		else {
			result.push_back('R');
			j--;
		}
	}

	return {final_value, result};
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> field(n, vector<int>(m, 0));

	char c;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '1') { field[i][j] = 1; }
		}
	}

	pair<int, vector<char>> result = max_flowers(field, n, m);
	cout << result.first << endl;
	for (auto it = result.second.rbegin(); it != result.second.rend(); it++) {
		cout << *it;
	}

	return 0;
}