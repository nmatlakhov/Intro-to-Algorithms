#include<iostream>
#include<vector>
using namespace std;


pair<int,vector<int>> min_cost(vector<int>& prices, int  num) {
	int result = 10000000;
	vector<vector<int>> dp(num + 1, vector<int>(num + 2, result));
	dp[0][0] = 0;

	for (int i = 1; i <= num; i++) {
		for (int j = 0; j <= num; j++) {
			
			if (prices[i - 1] <= 500) {
				dp[i][j] = min(dp[i - 1][j] + prices[i - 1], dp[i - 1][j + 1]);
			}
			else if(j != 0) {
				dp[i][j] = min(dp[i - 1][j - 1] + prices[i - 1], dp[i - 1][j + 1]);
			}
			else {
				dp[i][j] = dp[i - 1][j + 1];
			}
		}
	}

	int ind_j = 0;
	int ind_i = num;
	for (int j = 0; j <= num; j++) {
		if (result > dp[num][j]) {
			result = dp[num][j];
			ind_j = j;
		}
	}

	vector<int> indices;
	int i = ind_i, j = ind_j;

	for (int r = 0; r < num; r++) {
		if (prices[i - 1] > 500) {
			if (j == 0) {
				indices.push_back(i);
				j++;
				i--;
			}
			else if (dp[i - 1][j - 1] + prices[i-1] < dp[i - 1][j + 1]) {
				i--;
				j--;
			}
			else {
				indices.push_back(i);
				i--;
				j++;
			}
		}
		else {
			if (dp[i - 1][j] + prices[i - 1] < dp[i - 1][j + 1]) {
				i--;
			}
			else {
				indices.push_back(i);
				i--;
				j++;
			}
		}
	}

	return { result, indices };
}

int main() {
	int n, cost;
	cin >> n;

	vector<int> prices(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> cost;
		prices[i] = cost;
	}

	pair<int, vector<int>> result = min_cost(prices, n);

	cout << result.first << " " << result.second.size() << endl;

	for (auto it = result.second.rbegin(); it != result.second.rend(); it++) {
		cout << *it << " ";
	}

	return 0;
}