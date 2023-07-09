#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

bool Checkindex(vector<int>& data, int pos, int k) {
	int left = 0, count = 0;
	for (int i = 1; i < data.size(); i++) {
		while (data[i] - data[left] > pos) {
			left++;
		}
		count += i - left;
		if (count >= k) {
			return true;
		}
	}
	return false;
}

int GetTrashIndex(vector<int>& data, int k) {
	int left = 0;
	int right = data[data.size() - 1] - data[0];

	while (left < right) {
		int middle = (right + left) / 2;

		if (Checkindex(data, middle, k)) {
			right = middle;
			cout << right << " R" << endl;
		}
		else {
			left = middle + 1;
			cout << left << " L" << endl;
		}
	}
	return left;
}

int main() {
	int n, result;
	long int k;
	cin >> n;
	vector<int> islands_sq(n);
	for (int i = 0; i < n; i++) {
		cin >> islands_sq[i];
	}
	cin >> k;
	sort(islands_sq.begin(), islands_sq.end());
	int fourth = GetTrashIndex(islands_sq, k);

	cout << fourth << endl;

	return 0;
}