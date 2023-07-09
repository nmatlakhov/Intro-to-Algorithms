#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

bool checkNames(string line1, string line2) {

	int n = line1.size(), m = line2.size();
	
	if (abs(n - m) > 1) { return false; }
	if (n > m) { swap(line1, line2); }

	int end = min(n, m);


	int j = 0,counter = 0;
	bool check = true;
	for (int i = 0; i < end; i++) {
		if (line1[i] != line2[j]) {
			counter++;
			if ((check) && (n != m)) {
				j++;
				check = false;
			}
		}

		if (counter > 1) {
			return false;
		}
		j++;
	}


	return true;
}


//bool checkNames(string line1, string line2) {
//	bool result = true;
//	int counter = 0, n = line1.size(), m = line2.size(), end = 0;
//	if (abs(n - m) > 1) { return false; }
//
//	end = min(m, n);
//
//	int i = 0, j = 0,sh_i = 0, sh_j = 0;
//	while ((i < end) && (counter < 2)) {
//
//		if (line1[i + sh_i] != line2[j + sh_j]) {
//			counter++;
//			if (sh_i + sh_j == 0) {
//				if (m > n) { sh_j++; }
//				if (n > m) { sh_i++; }
//			}
//		}
//		i++;
//		j++;
//	}
//	
//	if (counter >= 2) { result = false; }
//	return result;
//}

int main() {
	string name1, name2;
	getline(cin, name1);
	getline(cin, name2);

	bool check = checkNames(name1, name2);
	if (check) {
		cout << "OK" << endl;
	}
	else {
		cout << "FAIL" << endl;
	}

	return 0;
}