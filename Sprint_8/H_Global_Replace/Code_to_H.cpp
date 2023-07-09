#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> search(string pattern, string text) {
	vector<int> result;
	string line = pattern + '#' + text;

	vector<int> pi(pattern.size(), 0);
	int pi_prev = 0, k = 0;

	for (size_t i = 1; i < line.size(); i++) {
		k = pi_prev;

		while ((k > 0) && (line[k] != line[i])) {
			k = pi[k - 1];
		}

		if (line[k] == line[i]) { k++; }

		if (i < pattern.size()) { pi[i] = k; }

		pi_prev = k;

		if (k == pattern.size()) {
			result.push_back(i - 2 * pattern.size());
		}
	}

	return result;
}


int main() {
	string line, pattern, replace;
	getline(cin, line);
	getline(cin, pattern);
	getline(cin, replace);
	vector<int> result = search(pattern, line);
	
	int n = result.size(), pat_s = pattern.size(), rep_s = replace.size();
	int delta = rep_s - pat_s;

	for (size_t i = 0; i < n; i++) {
		line.replace(result[i] + i*delta, pat_s, replace);
	}

	cout << line << endl;

	return 0;
}