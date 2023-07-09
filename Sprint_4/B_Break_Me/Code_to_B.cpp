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
	int a = 1000, m = 123987123;
	string line = "abcezhgeljkablzwnvuwqvp";
	string line2 = "abcgbpdcvkumyfxillgnqrv";

	int hash_value = poly_hash(a, m, line);
	int hash_value2 = poly_hash(a, m, line2);

	cout << hash_value << " " << hash_value2 << endl;

	return 0;
}