//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef unsigned long long ull;
//
//vector<pair<long long, long long>> hashSeq(int a, int m, const vector<int>& vec) {
//	int n = vec.size();
//	vector<pair<long long, long long>> result(n + 1, { 0,0 });
//
//	result[0] = { 0, 1 };
//	result[1] = { vec[0] % m, a % m };
//
//	for (int i = 2; i < n + 1; i++) {
//		result[i] = { (result[i - 1].first * a + vec[i - 1]) % m, (result[i - 1].second * a) % m };
//	}
//
//	return result;
//}
//
//struct RollingHash {
//	static const int mod = (int)1e9 + 7; // prime mod of polynomial hashing
//	static vector<ull> pow2;        // powers of base modulo 2^64
//	static int base;                     // base (point of hashing)
//
//	// --------- Static functons --------
//	static inline int diff(int a, int b) {
//		// Diff between `a` and `b` modulo mod (0 <= a < mod, 0 <= b < mod)
//		return (a -= b) < 0 ? a + mod : a;
//	}
//
//	vector<ull> pref2; // Hash on prefix modulo 2^64
//
//	RollingHash(const vector<int>& s)
//		: pref2(s.size() + 1u, 0)
//	{
//
//		const int n = s.size(); 
//		while ((int)pow2.size() <= n) {
//
//			pow2.push_back(pow2.back() * base);
//		}
//		for (int i = 0; i < n; ++i) { 
//			pref2[i + 1] = pref2[i] + s[i] * pow2[i];
//		}
//	}
//
//	ull operator()(const int pos, const int len, const int mxPow = 0) const {
//
//		ull hash2 = pref2[pos + len] - pref2[pos];
//		if (mxPow != 0) {
//
//			hash2 *= pow2[mxPow - (pos + len - 1)];
//		}
//		return hash2;
//	}
//};
//
//int RollingHash::base((int)257);
//vector<ull> RollingHash::pow2{ 1 };
//
//
//int main() {
//	int n, m, max_length = 0, temp_val, value_print;
//	int m1 = 1000000007;
//
//	cin >> n;
//	vector<int> v1(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> v1[i];
//	}
//
//	cin >> m;
//	vector<int> v2(m, 0);
//	for (int j = 0; j < m; j++) {
//		cin >> v2[j];
//	}
//
//	const int mxPow = max(v1.size(), v2.size());
//
//	// Create hashing objects from strings:
//	RollingHash hash_a(v1), hash_b(v2);
//
//	// Binary search by length of same subsequence:
//	int pos = -1, low = 0, high = min(v1.size(), v2.size()) + 1;
//	while (high - low > 1) {
//		int mid = (low + high) / 2;
//		vector<ull> hashes;
//		for (int i = 0; i + mid <= n; ++i) {
//			hashes.push_back(hash_a(i, mid, mxPow));
//		}
//		sort(hashes.begin(), hashes.end());
//		int p = -1;
//		for (int j = 0; j + mid <= m; ++j) {
//			if (binary_search(hashes.begin(), hashes.end(), hash_b(j, mid, mxPow))) {
//				p = j;
//				break;
//			}
//		}
//		if (p >= 0) {
//			low = mid;
//			pos = p;
//		}
//		else {
//			high = mid;
//		}
//	}
//
//	cout << low << endl;
//
//	return 0;
//}