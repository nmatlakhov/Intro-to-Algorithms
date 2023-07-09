#include<iostream>
#include<vector>
using namespace std;

vector<int> mergeSort(const vector<int>& values) {
	int n = values.size();
	if (n == 1) { return values; }
	int mid = (n / 2) + (n % 2);
	int rest = n - mid;

	vector<int> left_temp(mid);
	vector<int> right_temp(rest);
	for (int i = 0; i < mid; i++) {
		left_temp[i] = values[i];
	}
	for (int p = 0; p < rest; p++) {
		right_temp[p] = values[mid + p];
	}

	left_temp = mergeSort(left_temp);
	right_temp = mergeSort(right_temp);

	vector<int> result(n);
	int l = 0, r = 0, k = 0;
	int left_size = left_temp.size(), right_size = right_temp.size();
	while ((l < left_size) && (r < right_size)) {

		if (left_temp[l] < right_temp[r]) {
			result[k] = left_temp[l];
			l += 1;
		}
		else {
			result[k] = right_temp[r];
			r += 1;
		}
		k += 1;
	}

	while (l < left_size) {
		result[k] = left_temp[l];
		l += 1;
		k += 1;
	}

	while (r < right_size) {
		result[k] = right_temp[r];
		r += 1;
		k += 1;
	}

	return result;
}


int main() {
	int n, money;
	cin >> n >> money;
	vector<int> houses(n);
	for (int i = 0; i < n; i++) {
		cin >> houses[i];
	}

	houses = mergeSort(houses);

	int counter = 0;

	while (houses[counter] <= money)  {
		money -= houses[counter];
		counter++;
		if (counter >= n) { break; }
	}

	cout << counter << endl;
	return 0;
}