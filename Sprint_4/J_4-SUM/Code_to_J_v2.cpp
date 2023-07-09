#include<algorithm>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;


set<vector<int>> GetFourSum(const vector<int>& data, int target) {
	set<vector<int>> result;
	unordered_map<long, pair<int, int>> sumToPair;

	int num_size = data.size();
	sumToPair.rehash(num_size * num_size);

	if (data.size() < 4) { return result; }

	for (int i = 1; i < data.size(); i++) {
		for (int j = i + 1; j < data.size(); j++) {
			long sum = data[i] + data[j];
			
			auto find_sum = sumToPair.find(target - sum);
			if (find_sum != sumToPair.end()) {
				pair<int, int> p = find_sum->second;
				vector<int> p_vec = { data[i],data[j],p.first,p.second };
				sort(p_vec.begin(), p_vec.end());
				result.insert(p_vec);
			}
		}

		for (int j = 0; j < i; j++) {
			long sum = data[i] + data[j];
			sumToPair[sum] = { data[i],data[j] };
		}

	}
	
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, A, temp_value;

	cin >> n >> A;

	vector<int> numbers;
	
	for (int i = 0; i < n; i++) {
		cin >> temp_value;
		numbers.push_back(temp_value);
	}
	sort(numbers.begin(), numbers.end());
	set<vector<int>> result = GetFourSum(numbers, A);

	cout << result.size() << endl;

	for (auto it = result.begin(); it != result.end(); it++) {
		for (auto it2 = it->begin(); it2 != it->end(); it2++) {
			cout << *it2 << " ";
		}
		cout << "\n";
	}

	return 0;
}