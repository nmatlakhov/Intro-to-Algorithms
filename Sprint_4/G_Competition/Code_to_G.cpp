#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {
	int n = 0, temp = 0, left_sum = 0;
	cin >> n;
	unordered_map<int, int> hash_table;
	hash_table.insert({ 0,-1 });

	int length = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		temp == 0 ? left_sum -= 1 : left_sum += 1;

		if (hash_table.find(left_sum) == hash_table.end()) {
			hash_table.insert({ left_sum, i });
		}
		else {
			if (length < i - hash_table[left_sum]) { 
				length = i - hash_table[left_sum]; 
			}
		}

	}

	cout << length << endl;

	return 0;
}