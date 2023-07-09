//#include<algorithm>
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<set>
//using namespace std;
//
//set<vector<int>> fourthInt(const vector<int>& numbers, int target_value) {
//	unordered_map<long, vector<pair<int, int>>> history;
//	set<vector<int>> result;
//
//	int num_size = numbers.size();
//
//	history.rehash(num_size * num_size);
//
//	for (int i = 0; i < num_size - 1; i++) {
//		for (int j = i + 1; j < num_size; j++) {
//			long temp_val = numbers[i] + numbers[j];
//			history[temp_val].push_back({ i,j });
//		}
//	}
//
//	for (int i = 0; i < num_size - 1; i++) {
//		for (int j = i + 1; j < num_size; j++) {
//			long targ_sum = numbers[i] + numbers[j];
//
//			auto it = history.find(target_value - targ_sum);
//			if (it != history.end()) {
//				for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
//					pair<int, int> pair_val = *it2;
//					if ((pair_val.first != i) && (pair_val.first != j) && (pair_val.second != i) && (pair_val.second != j)) {
//						vector<int> temp_res = { numbers[i], numbers[j], numbers[pair_val.first], numbers[pair_val.second] };
//						sort(temp_res.begin(), temp_res.end());
//
//						result.insert(temp_res);
//					}
//				}
//
//
//			}
//
//		}
//	}
//	return result;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n, A, temp_value;
//	cin >> n >> A;
//
//	vector<int> numbers;
//	for (int i = 0; i < n; i++) {
//		cin >> temp_value;
//		numbers.push_back(temp_value);
//	}
//
//	set<vector<int>> result_vec = fourthInt(numbers, A);
//	cout << result_vec.size() << endl;
//
//	for (auto it = result_vec.begin(); it != result_vec.end(); it++) {
//		for (auto it2 = it->begin(); it2 != it->end(); it2++) {
//			cout << *it2 << " ";
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}