#include<vector>
#include<iostream>
using namespace std;

int find_pos(vector<int>& cont, vector<int>& pattern, int start = 0) {
	int n = cont.size(), pat_size = pattern.size();
	if (n < pat_size) { return -1; }

	for (int pos = start; pos <= n - pat_size; pos++) {
		bool match = true;

		int diff_num = 0;
		for (int offset = 0; offset < pat_size; offset++) {

			if (cont[pos + offset] != pattern[offset] + diff_num) {
				if (offset == 0) {
					diff_num = cont[pos + offset] - pattern[0];
				}
				else {
					match = false;
					break;
				}
			}
		}

		if (match) {
			return pos;
		}

	}

	return -1;
}

vector<int> find_all(vector<int>& cont, vector<int>& pattern) {
	vector<int> result;
	int start = 0; 
	int res = find_pos(cont, pattern, start);

	while (res != -1) {
		result.push_back(res + 1);
		start = res + 1;
		res = find_pos(cont, pattern, start);
	}

	return result;
}

int main() {
	int n, m, temp;
	cin >> n;
	vector<int> fill(n, 0);
	
	for (int i = 0; i < n; i++) {
		cin >> temp;
		fill[i] = temp;
	}

	cin >> m;
	vector<int> pattern(m, 0);
	for (int j = 0; j < m; j++) {
		cin >> temp;
		pattern[j] = temp;
	}

	vector<int> result = find_all(fill, pattern);

	for (auto it = result.begin(); it != result.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}