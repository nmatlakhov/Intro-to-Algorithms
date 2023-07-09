#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

long long GetHash(string str, long long base, long long mod) {
	long long hash = 0;
	for (int i = 0; i < str.size(); i++) {
		hash = (hash * base % mod + str[i]) % mod;
	}
	return hash;
}

long long GetPower(int n, long long base, long long mod) {
	long long power = 1;
	for (int i = 0; i < n - 1; i++) {
		power = (power * base) % mod;
	}
	return power;
}

vector<int> GetPositions(string str, int n, int k, long long base, long long mod) {
	unordered_map<long long, int> counter;
	unordered_map<long long, int> hashToPos;
	vector<int> result;

	int line_size = str.size();
	int mid2 = line_size / n;

	if (mid2 <= 2) {
		for (int i = 0; i < mid2; i++) {
			if (str[i] != str[mid2 + i]) {
				return result;
			}
		}
	}

	long long hash = GetHash(str.substr(0, n), base, mod);
	long long power = GetPower(n, base, mod);

	int& val = counter[hash];
	val++;
	int& pos = hashToPos[hash];
	pos = 0;
	if (val == k) {
		result.push_back(pos);
	}


	for (int i = 1; i + n - 1 < str.size(); i++) {
		hash = (hash + mod - str[i - 1] * power % mod) % mod;
		hash = (hash * base % mod + str[i + n - 1]) % mod;

		int& val = counter[hash];
		val++;
		int& pos = hashToPos[hash];

		if (val == 1) {
			pos = i;
		}

		if (val == k) {
			result.push_back(pos);
		}
	}

	return result;
}

int main() {
	int n, k, value_res1, value_res2;
	int a = 345;
	long long m1 = 5608713984039443;
	string line;
	cin >> n >> k >> line;

	vector<int> positions = GetPositions(line, n, k, a, m1);

	for (auto it = positions.begin(); it != positions.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}