#include<iostream>

using namespace std;

int temp_list[100002];

int main() {
	int n,temp_value, counter = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> temp_value;
		temp_list[i + 1] = temp_value;
	}

	if (n == 1) {
		counter++;
	}


	for (int j = 0; j < n; ++j) {
		if ((j == 0) && (temp_list[j + 1] > temp_list[j+2])) {
			counter++;
		}
		else if ((temp_list[j + 1] > temp_list[j + 2]) && (temp_list[j + 1] > temp_list[j]) && (j != (n-1)) ) {
			counter++;
		}else if ( (temp_list[j + 1] > temp_list[j]) && (j == (n - 1) ) ) {
				counter++;
		}
	}
	
	cout << counter << '\n';

}