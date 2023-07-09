#include<iostream>
#include<string>
using namespace std;

bool isSubsequence(const string& str1, const string& str2, int n, int m) {
	if (n == 0) { return true; }
	if (m == 0) { return false; }

	if (str1[n - 1] == str2[m - 1]) { return isSubsequence(str1, str2, n - 1, m - 1); }

	return isSubsequence(str1, str2, n, m - 1);
}

int main() {
	string line1, line2, result;
	getline(cin, line1);
	getline(cin, line2);
	int n = line1.size(), m = line2.size();

	isSubsequence(line1, line2, n,m) ? result = "True" : result = "False";
	cout << result << endl;

	return 0;
}