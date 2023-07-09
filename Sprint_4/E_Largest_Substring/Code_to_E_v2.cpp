#include<vector>
#include<string>
#include<iostream>
using namespace std;

int GetMaxUniqueStringLen(string& str){
	int result = 0;
	int prev = 0;
	vector<int> letterToPos(256);

	for (int i = 0; i < str.size(); i++) {
		prev = max(prev, letterToPos[str[i]]);
		letterToPos[str[i]] = i + 1;
		result = max(result, i + 1 - prev);
	}

	return result;
}

int main() {
	string line;
	getline(cin, line);

	int result = GetMaxUniqueStringLen(line);
	cout << result << endl;
	return 0;
}