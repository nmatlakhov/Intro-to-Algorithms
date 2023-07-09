#include<vector>
#include<iostream>
using namespace std;

int calc_num_of_coins(vector<int>& coins, int sum, int num) {
	int result = 0;
	vector<vector<int>> dp(num + 1, vector<int>(sum + 1, 0));

	for (int i = 1; i <= num; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= sum; j++) {
			dp[i][j] = dp[i - 1][j];
			if (coins[i-1] <= j) { 
				dp[i][j] += dp[i][j - coins[i - 1]];
			}
		}
	}

	result = dp[num][sum];

	return result;
}

int main() {
	int m, n, nom;
	cin >> m >> n;

	vector<int> coins(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> nom;
		coins[i] = nom;
	}

	int result = calc_num_of_coins(coins, m, n);
	cout << result << endl;

	return 0;
}