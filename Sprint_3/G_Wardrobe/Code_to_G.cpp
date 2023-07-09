#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, temp, wardrobe[3] = {};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		wardrobe[temp]++;
	}

	for (int j = 0; j < 3; j++) {
		while (wardrobe[j] > 0) {
			cout << j << " ";
			wardrobe[j]--;
		}
	}

	return 0;
}