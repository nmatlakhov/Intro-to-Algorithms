#include<iostream>
#include<vector>
using namespace std;

int knapsack_problem(vector<int>& weights, int max_weight, int  num) {
	int result = 0;
	vector<vector<int>> dp(num + 1, vector<int>(max_weight + 1, 0));

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= max_weight; j++) {
			if (j - weights[i - 1] < 0) { 
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + weights[i - 1]);
			}
		}
	}

	result = dp[num][max_weight];

	return result;
}

int main() {
	int n, M,w;
	cin >> n >> M;

	vector<int> weights(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> w;
		weights[i] = w;
	}

	int result = knapsack_problem(weights, M, n);
	cout << result << endl;

	return 0;
}