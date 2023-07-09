#include<iostream>
#include<string>
using namespace std;

int main() {
	int sc[26] = {};
	string s, t;
	
	int nt = 0, ids, idt;

	cin >> s >> t;

	for (int i = 0; i < s.size(); i++) {
		ids = s[i] - 'a';
		idt = t[i] - 'a';
		
		sc[ids]--;
		sc[idt]++;
	}
	idt = t[t.size() - 1] - 'a';

	sc[idt]++;

	for (int i = 0; i < 26; i++) {
		if (sc[i] > 0) {
			char letter = 'a' + i;
			cout << letter;
		}
	}

	return 0;
}