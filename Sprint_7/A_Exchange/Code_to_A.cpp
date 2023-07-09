#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
	int max_profit = 0;
	for (size_t i = 1; i < prices.size(); i++) {
		if (prices[i] > prices[i - 1]) {
			max_profit += prices[i] - prices[i - 1];
		}
	}
	return max_profit;
}

int main() {
	int n, price;
	cin >> n;
	vector<int> prices(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> price;
		prices[i] = price;
	}

	int result = maxProfit(prices);
	cout << result << endl;

	return 0;
}