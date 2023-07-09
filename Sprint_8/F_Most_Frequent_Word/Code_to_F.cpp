#include<map>
#include<string>
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string temp;
	map<string, int> result;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		result[temp]++;
	}

	int max_val = 0;
	string freq_w = "";

	for (auto it = result.begin(); it!= result.end(); it++) {
		if (it->second > max_val) {
			freq_w = it->first;
			max_val = it->second;
		}
	}

	cout << freq_w << endl;

	return 0;
}