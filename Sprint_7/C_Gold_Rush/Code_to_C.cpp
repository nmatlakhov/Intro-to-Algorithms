#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using int64 = long long;

int64 maxValue(vector<pair<int64, int64>>& piles, int64 max_weight) {
	int64 rem_weight = max_weight;
	int64 value = 0;
	for (auto it = piles.begin(); it != piles.end(); it++) {
		//cout << it->first << " " << it->second << endl;
		if (rem_weight > it->second) {
			rem_weight -= it->second;
			value += it->first * it->second;
		}
		else {
			value += rem_weight * it->first;
			rem_weight = 0;
			break;
		}

	}

	return value;
}

int main() {
	int64 M, n, cost, mass;
	cin >> M >> n;
	vector<pair<int64, int64>> gold_piles;
	for (int i = 0; i < n; i++) {
		cin >> cost >> mass;
		gold_piles.push_back({ cost, mass });
	}

	sort(gold_piles.rbegin(), gold_piles.rend());

	int64 result = maxValue(gold_piles, M);
	cout << result << endl;

	return 0;
}