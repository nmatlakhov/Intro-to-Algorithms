#include<iostream>
using namespace std;

int main() {
	char letter;
	char sentence[20000];
	int counter = 0;
	cin >> noskipws;
	while (cin >> letter && letter != '\n') {
		letter = tolower(letter);
		if ((letter >= 'a' && letter <= 'z' ) || (letter >= '0' && letter <= '9')) {
			sentence[counter] = letter;
			++counter;
		}
	}
	int sentence_length = counter;
	int middle = 0;

	if (sentence_length % 2 == 0) {
		middle = sentence_length / 2;
	}
	else {
		middle = (sentence_length - 1) / 2 + 1;
	}


	for (int j = 0; j < middle; ++j) {
		if (sentence[j] != sentence[sentence_length - j - 1]) {
			cout << "False";
			return 0;
		}
	}
	cout << "True";

	return 0;
}