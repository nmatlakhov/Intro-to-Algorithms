#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string temp;
	vector<string> strs(n, "");

	for (int i = 0; i < n; i++) {
		cin >> temp;
		strs[i] = move(temp);
	}
	
	sort(strs.begin(), strs.end());

	string first = strs[0], last = strs[n - 1]; 
	int min_dist = min(first.size(), last.size());
	
	int i = 0;
	while ((i < min_dist) && (first[i] == last[i])) {
		i++;
	}

	cout << i << endl;

	return 0;
}