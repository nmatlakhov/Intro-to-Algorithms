#include<iostream>
#include<vector>
using namespace std;

vector<int> GCS(vector<int>& items, int numbers) {
	vector<vector<int>> dp(numbers + 1, vector<int>(numbers + 1, 0));

	for (int i = 1; i <= numbers; i++) {
		int max_val = 0;
		for (int j = 1; j <= numbers; j++) {
			dp[i][j] = dp[i - 1][j];
			if (items[i - 1] == items[j - 1]) {
				dp[i][j] = max(dp[i][j], max_val + 1);
			}

			if (items[j - 1] < items[i - 1]) {
				max_val = max(max_val, dp[i - 1][j]);
			}

		}
	}

	vector<int> result;
	int max_value = 0, id = 0;
	for (int i = numbers; i >= 1; i--) {

		if (dp[numbers][i] >= max_value){
			id = i;
			max_value = dp[numbers][i];
		}
	}

	while (id > 0) {
		if (dp[numbers][id] - max_value == 0) {
			result.push_back(id);
			max_value--;
		}
		id--;
	}

	return result;
}

int main() {
	int n, temp_val;
	cin >> n;

	vector<int> ranks(n, 0);
	
	for (int i = 0; i < n; i++) {
		cin >> temp_val;
		ranks[i] = temp_val;
	}

	vector<int> result = GCS(ranks, n);

	cout << result.size() << endl;
	for (auto it = result.rbegin(); it != result.rend(); it++) {
		cout << *it << " ";
	}

	return 0;
}