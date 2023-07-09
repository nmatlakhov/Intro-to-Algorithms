#include<iostream>
#include<vector>
using namespace std;

int binarySearch(const vector<int>& arr, int value, int left, int right) {
	if (arr[right] < value) { return -1; }
	if (right == left) { return right + 1; }
	
	int mid = (left + right) / 2;

	if (value <= arr[mid]) {
		return binarySearch(arr, value, left, mid);
	}
	else {
		return binarySearch(arr, value, mid + 1, right);
	}
}


int main() {
	int number_of_days, value, cost_bicycle;
	cin >> number_of_days;
	vector<int> savings(number_of_days);
	for (int i = 0; i < number_of_days; i++) {
		cin >> value;
		savings[i] = value;
	}
	cin >> cost_bicycle;

	cout << binarySearch(savings, cost_bicycle, 0, number_of_days-1 ) << " ";
	cout << binarySearch(savings, 2 * cost_bicycle, 0, number_of_days -1 );

	return 0;
}