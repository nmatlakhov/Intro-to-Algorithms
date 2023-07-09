#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	unordered_map<string, vector<int>> hash_table;
	hash_table.rehash(50);

	string temp_line;
	for (int i = 0; i < n; i++) {
		cin >> temp_line;

		int line_size = temp_line.size();

		sort(temp_line.begin(), temp_line.end());

		auto loc = hash_table.find(temp_line);
		if (loc == hash_table.end()) {
			hash_table[temp_line].push_back(i);
		}
		else {
			loc->second.push_back(i);
		}
	}

	vector<vector<int>> indices;

	for (auto it = hash_table.begin(); it != hash_table.end(); it++) {
		indices.push_back(it->second);
	}

	sort(indices.begin(), indices.end());

	for (auto it = indices.begin(); it != indices.end(); it++) {
		for (auto it2 = it->begin(); it2 != it->end(); it2++) {
			cout << *it2 << " ";
		}
		cout << endl;
	}


	return 0;
}