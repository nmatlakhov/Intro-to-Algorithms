#include<string>
#include<vector>
#include <sstream> 
#include<iostream>
using namespace std;

int main() {
	string line, temp;
	vector<string> result;
	getline(cin, line);

	istringstream iss(line);
	while (iss >> temp) {
		result.push_back(temp);
	}

	for (auto it = result.rbegin(); it != result.rend(); it++) {
		cout << *it << " ";
	}

	return 0;
}