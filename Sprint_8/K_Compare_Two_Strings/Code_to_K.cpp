#include<string>
#include<iostream>
using namespace std;

int main() {
	string temp1, temp2, line1 = "", line2 = "";
	getline(cin, temp1);
	getline(cin, temp2);

	for (size_t i = 0; i < temp1.size(); i++) {
		int t = temp1[i] - 'a' + 1;
		if (t % 2 == 0) {
			line1 += temp1[i];
		}
	}

	for (size_t i = 0; i < temp2.size(); i++) {
		int t = temp2[i] - 'a' + 1;
		if (t % 2 == 0) {
			line2 += temp2[i];
		}
	}

	if (line1 < line2) {
		cout << -1 << endl;
	}
	else if (line1 == line2) {
		cout << 0 << endl;
	}
	else {
		cout << 1 << endl;
	}

	return 0;
}