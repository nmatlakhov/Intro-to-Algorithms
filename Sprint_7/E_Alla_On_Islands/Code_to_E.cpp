#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int num_of_banknotes(vector<int>& notes, int wanted_sum) {
	int n = notes.size();

	vector<int> result(wanted_sum + 1, 0);
	result[0] = 0;
	for (int i = 1; i <= wanted_sum; i++) {
		result[i] = 100000;
	}

	for (int i = 1; i <= wanted_sum; i++) {
		for (int j = 0; j < n; j++) {
			if (notes[j] <= i) {
				int add_res = result[i - notes[j]];
				if ((add_res != 100000) &(add_res + 1 < result[i])){
					result[i] = add_res + 1;
				}
			}
		}
	}

	if (result[wanted_sum] == 100000) {
		return -1;
	}

	return result[wanted_sum];
}

int main() {
	int x,k;
	int value;
	cin >> x >> k;
	vector<int> banknote(k, 0);

	for (int i = 0; i < k; i++) {
		cin >> value;
		banknote[i] = value;
	}

	int result = num_of_banknotes(banknote, x);
	cout << result << endl;

	return 0;
}