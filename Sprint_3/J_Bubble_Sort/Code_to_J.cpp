#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& values) {
	int n = values.size();
	for (int p = 0; p < n; p++) {
		cout << values[p] << " ";
	}
	cout << endl;
}

bool bubbleSort(vector<int>& values, int j) {
	bool f = true;
	int n = values.size();
	for (int m = 0; m < n - j - 1; m++) {
		if (values[m] > values[m + 1]) {
			swap(values[m], values[m + 1]);
			f = false;
		}
	}

	return f;
}



int main() {
	int n;
	cin >> n;
	vector<int> array(n);
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	
	bool check, first_time = true;;
	for (int j = 0; j < n -1 ; j++) {
		check = bubbleSort(array,j);
		if (first_time) { 
			first_time = false; 
			printVector(array);
		}
		else {
			if (check) { break; }
			printVector(array);
		}
	
	}



	return 0;
}