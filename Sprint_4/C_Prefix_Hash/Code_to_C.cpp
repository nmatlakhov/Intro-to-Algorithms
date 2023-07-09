//#include<iostream>
//#include<string>
//#include<vector>
//#include<utility>
//using namespace std;
//
//vector<pair<int,int>> hashPrefixSeq(int a, int m, const string& line) {
//	int n = line.size();
//	string temp_line;
//	vector<pair<int,int>> result;
//
//	long long pow_a = 1;
//	long long hash_value = 0;
//
//	int temp_pow = pow_a, temp_hash = hash_value;
//	result.push_back({ temp_pow,temp_hash });
//
//	for (int i = 0; i < n; i++) {
//		hash_value = (hash_value * a + line[i]) % m;
//		pow_a = (pow_a * a) % m;
//
//		temp_pow = pow_a, temp_hash = hash_value;
//		result.push_back({ temp_pow,temp_hash });
//	}
//
//	return result;
//}
//
//int hashCalc(int m, const vector<pair<int, int>>& hash_seq, int left, int right) {
//	long long temp_val = hash_seq[right].second , temp_minus = hash_seq[left - 1].second;
//	temp_val = (temp_val - temp_minus * hash_seq[right - left + 1].first) % m;
//	int result = (m + temp_val) % m;
//
//	return result;
//}
//
//int main() {
//	int a, m, t, left, right, value_print;
//	string line;
//	cin >> a >> m >> line;
//	
//	vector<pair<int, int>> result_vector = hashPrefixSeq(a, m, line);
//	
//
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		cin >> left >> right;
//		value_print = hashCalc(m, result_vector, left, right);
//		cout << value_print << endl;
//	}
//
//	return 0;
//}