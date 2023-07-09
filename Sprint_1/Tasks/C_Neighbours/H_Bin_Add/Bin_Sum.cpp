#include<iostream>
#include<string>

using namespace std;

int main() {
	string a,b;
	int c[20000];
	cin >> a >> b;

	int na = a.size();
	int nb = b.size();

	int cnta = na - 1, cntb = nb - 1, addsum = 0, counter = 0;

	while (cnta >= 0 || cntb >= 0 || addsum == 1) {
		if (cnta >= 0) {
			addsum += a[cnta] - '0';
		}
		if (cntb >= 0) {
			addsum += b[cntb] - '0';
		}

		c[counter] = addsum % 2;
		addsum = addsum / 2;
		cnta--;
		cntb--;
		counter++;
	}

	for (int j = counter-1; j >= 0; --j) {
		cout << c[j];
	}
	cout << '\n';

	return 0;
}