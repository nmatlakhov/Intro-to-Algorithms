#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

bool checkStrings(const string& s1, const string& s2) {
	int size_line = s1.size(), size_line_2 = s2.size();
	if (size_line != size_line_2) { return false; }


	unordered_map<char, char> hash_table, hash_table_2;
	hash_table.rehash(33),hash_table_2.rehash(33);

	for (int i = 0; i < size_line; i++) {
		auto it = hash_table.find(s1[i]);
		auto it2 = hash_table_2.find(s2[i]);

		if ( it == hash_table.end()) {
			hash_table[s1[i]] = s2[i];
		}
		else {
			if (s2[i]!= it->second) {
				return false;
			}
		}

		if (it2 == hash_table_2.end()) {
			hash_table_2[s2[i]] = s1[i];
		}
		else {
			if (s1[i] != it2->second) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	string line1, line2;
	getline(cin, line1);
	getline(cin, line2);
	
	bool check = checkStrings(line1, line2);

	if (check) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}