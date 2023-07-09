#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> prefix_function(string line) {
	vector<int> pi(line.size(), 0);
	int lin_size = line.size(), k = 0;

	for (int i = 1; i < lin_size; i++) {
		k = pi[i - 1];
		while ((k > 0) && (line[k] != line[i])) {
			k = pi[k - 1];
		}

		if (line[k] == line[i]) { k++; }
		pi[i] = k;
	}

	return pi;
}

int main() {
	string line;
	getline(cin, line);
	vector<int> result = prefix_function(line);

	//for (size_t i = 0; i < result.size(); i++) {
	//	cout << result[i] << " ";
	//}
	//cout << endl;

	int n = result.size();
	int m = result[n - 1];
	
	int delta = n - m;
	cout << n / delta << endl;

	return 0;
}