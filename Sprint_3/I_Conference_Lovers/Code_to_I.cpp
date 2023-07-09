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

bool lessVal(const vector<int>& val_1, const vector<int>& val_2) {
	if (val_1[1] < val_2[1]) { return true; }
	else if (val_1[1] == val_2[1]) {
		if (val_1[0] < val_2[0]) { return true; }
		else { return false; }
	}
	return false;
}

void sortByNum(vector<vector<int>>& values) {
	int n = values.size();
	vector<int> temp;
	for (int i = 1; i < n; i++) {
		temp = values[i];
		int j = i;
		while ((j > 0) && lessVal(temp, values[j - 1])) {
			values[j] = values[j - 1];
			j -= 1;
		}
		values[j] = temp;
	}
}



int main() {
	int n, k, counter = -1;
	cin >> n;

	vector<int> students(n);
	for (int i = 0; i < n; i++) {
		cin >> students[i];
	}
	
	cin >> k;

	students = mergeSort(students);

	vector<vector<int>> groupVal;
	for (int i = 0; i < n-1; i++) {
		if (students[i] == students[i+1]) {
			counter--;
		}
		else {
			vector<int> result{ students[i], counter };
			groupVal.push_back(result);
			counter = -1;
		}
	}
	vector<int> result{ students[n-1], counter };
	groupVal.push_back(result);

	sortByNum(groupVal);

	int m = groupVal.size();
	int p;
	m < k ? p = m : p = k;

	for (int j = 0; j < p; j++) {
		cout << groupVal[j][0] << " ";
	}

	return 0;
}