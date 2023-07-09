//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<map>
//using namespace std;
//
//long long GetHash(string& str, int n, long long base, long long mod) {
//	long long hash = 0;
//	for (int i = 0; i < n; i++) {
//		hash = (hash * base % mod + str[i]) % mod;
//	}
//	return hash;
//}
//
//long long GetPower(int n, long long base, long long mod) {
//	long long power = 1;
//	for (int i = 0; i < n - 1; i++) {
//		power = (power * base) % mod;
//	}
//	return power;
//}
//
//vector<int> GetPositions(string str, int n, int k, pair<int,int> bm1, pair<int,int> bm2) {
//	map<pair<int,int>, vector<int>> storage;
//	vector<int> result;
//
//	int line_size = str.size();
//	int mid2 = line_size / n;
//
//	if (mid2 <= 2) {
//		for (int i = 0; i < mid2; i++) {
//			if (str[i] != str[mid2 + i]) {
//				return result;
//			}
//		}
//	}
//
//	long long hash_1 = GetHash(str, n, bm1.first, bm1.second);
//	long long power_1 = GetPower(n, bm1.first, bm1.second);
//
//	long long hash_2 = GetHash(str, n, bm2.first, bm2.second);
//	long long power_2 = GetPower(n, bm2.first, bm2.second);
//
//	storage.insert({ {hash_1, hash_2}, {0} });
//
//
//	for (int i = 1; i + n - 1 < str.size(); i++) {
//		hash_1 = (hash_1 + bm1.second - str[i - 1] * power_1 % bm1.second) % bm1.second;
//		hash_1 = (hash_1 * bm1.first % bm1.second + str[i + n - 1]) % bm1.second;
//
//		hash_2 = (hash_2 + bm2.second - str[i - 1] * power_2 % bm2.second) % bm2.second;
//		hash_2 = (hash_2 * bm2.first % bm2.second + str[i + n - 1]) % bm2.second;
//
//		if (storage.find({ hash_1,hash_2 }) != storage.end()) {
//			storage[{ hash_1, hash_2 }].push_back(i);
//		}
//		else {
//			storage.insert({ { hash_1,hash_2 }, {i} });
//		}
//	}
//
//	for (auto it = storage.begin(); it != storage.end(); it++) {
//		if (it->second.size() >= k) {
//			result.push_back(it->second[0]);
//		}
//	}
//
//	return result;
//}
//
//int main() {
//	int n, k, value_res1, value_res2;
//	pair<int, int> bm1 = { 257, 1000000123 };
//	pair<int, int> bm2 = { 271,1000000011 };
//	string line;
//	cin >> n >> k >> line;
//
//	vector<int> positions = GetPositions(line, n, k, bm1, bm2);
//
//	for (auto it = positions.begin(); it != positions.end(); it++) {
//		cout << *it << " ";
//	}
//
//	return 0;
//}