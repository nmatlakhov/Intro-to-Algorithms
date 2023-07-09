#include<iostream>
#include<string>

using namespace std;


int main() {
	char sentence[100000];
	
	int n = 0, start_w = 0 , end_w = 0, length_w = 0,start_max = 0, end_max = 0, max_length =0;
	char letter;
	cin >> n;
	cin.get();
	
	for (int i = 0; i < n;i++) {
		cin >> noskipws>>  letter;
		sentence[i] = letter;
		length_w++;

		if (letter == ' ') {
			end_w = i;
			length_w--;
			if (max_length < length_w) {
				max_length = length_w;
				start_max = start_w;
				end_max = end_w;
			}

			start_w = i + 1;
			length_w = 0;
		}

		if (i == n - 1) {
			end_w = n;
			if (max_length < length_w) {
				max_length = length_w;
				start_max = start_w;
				end_max = end_w;
			}
			length_w = 0;
		}
	}


	for (int j = start_max; j < end_max; ++j) {
		cout << sentence[j];
	}
	cout << endl;

	cout << max_length;

	return 0;
}