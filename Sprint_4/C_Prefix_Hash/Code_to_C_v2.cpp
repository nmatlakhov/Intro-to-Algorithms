#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

using int64 = unsigned long long;

vector<int64> GetHashes(vector<int>& data, int64 base, int64 mod) {
	vector<int64> prefixHashes(data.size() + 1, 0);

	for (size_t i = 1; i <= data.size(); i++) {
		prefixHashes[i] = (prefixHashes[i - 1] * base % mod + data[i - 1]) % mod;
	}

	return prefixHashes;
}

vector<int64> GetPowers(vector<int>& data, int64 base, int64 mod) {
	vector<int64> powers(data.size() + 1, 0);
	powers[0] = 1;

	for (size_t i = 1; i <= data.size(); i++) {
		powers[i] = (powers[i - 1] * base) % mod;
	}

	return powers;
}

int64 GetHash(vector<int64>& prefixHashes, vector<int64>& powers, int start, int end, int64 mod) {
	int64 result = (prefixHashes[end] + mod - (prefixHashes[start] * powers[end - start]) % mod) % mod;
	//cout << result << " start: " << start << " end: " << end << endl;
	//cout << "pr_end:" << prefixHashes[end] << " pr_start: " << prefixHashes[start] << " power: " << powers[end - start] << endl;
	return result;
}

int main() {
	int a, m, t, left, right, value_print;
	vector<int> line;
	int n, p;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		line.push_back(p);
	}

	cin >> a >> m;

	vector<int64> prHashes = GetHashes(line, a, m);
	vector<int64> powers = GetPowers(line, a, m);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> left >> right;
		value_print = GetHash(prHashes, powers, left - 1, right, m);
		cout << value_print << endl;
	}

	return 0;
}