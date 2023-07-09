#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int poly_hash(int a, int m, const string& line) {
	int line_size = line.size();
	long long hash_value = 0;

	for (int i = 0; i < line_size; i++) {
		hash_value = (hash_value * a + line[i]) % m;
	}
	return hash_value;
}

int main() {
	int a, m;
	string line;
	cin >> a >> m >> line;

	int hash_value = poly_hash(a, m, line);

	cout << hash_value << endl;
	return 0;
}