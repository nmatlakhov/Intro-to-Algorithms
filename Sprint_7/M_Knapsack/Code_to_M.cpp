#include<iostream>
#include<vector>
using namespace std;

using item_val = pair<int, vector<int>>;

vector<int> knapsack_problem(vector<pair<int, int>>& items, int max_weight, int  num) {
	vector<vector<item_val>> dp(num + 1, vector<item_val>(max_weight + 1, { 0,{} }));

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= max_weight; j++) {
			if (j - items[i - 1].first < 0) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				if (dp[i - 1][j - items[i - 1].first].first + items[i - 1].second > dp[i - 1][j].first) {
					dp[i][j].first = dp[i - 1][j - items[i - 1].first].first + items[i - 1].second;
					dp[i][j].second = dp[i - 1][j - items[i - 1].first].second;
					dp[i][j].second.push_back(i);
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}

			}
		}
	}

	vector<int> result = dp[num][max_weight].second;

	return result;
}

int main() {
	int n, M, cost, weight;
	cin >> n >> M;

	vector<pair<int, int>> weights(n, { 0, 0 });
	for (int i = 0; i < n; i++) {
		cin >> weight >> cost;
		weights[i] = { weight, cost };
	}

	vector<int> result = knapsack_problem(weights, M, n);
	cout << result.size() << endl;

	for (auto it = result.begin(); it != result.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}