#include<iostream>
#include<string>
using namespace std;

void print_commbinations(string input_line, int i, string prefix) {
	if (i == input_line.size()) {
		cout << prefix << " ";
	}
	else {
		if (input_line[i] == '2') {
			print_commbinations(input_line, i + 1, prefix + 'a');
			print_commbinations(input_line, i + 1, prefix + 'b');
			print_commbinations(input_line, i + 1, prefix + 'c');
		}
		else if (input_line[i] == '3') {
			print_commbinations(input_line, i + 1, prefix + 'd');
			print_commbinations(input_line, i + 1, prefix + 'e');
			print_commbinations(input_line, i + 1, prefix + 'f');
		}
		else if (input_line[i] == '4') {
			print_commbinations(input_line, i + 1, prefix + 'g');
			print_commbinations(input_line, i + 1, prefix + 'h');
			print_commbinations(input_line, i + 1, prefix + 'i');
		}
		else if (input_line[i] == '5') {
			print_commbinations(input_line, i + 1, prefix + 'j');
			print_commbinations(input_line, i + 1, prefix + 'k');
			print_commbinations(input_line, i + 1, prefix + 'l');
		}
		else if (input_line[i] == '6') {
			print_commbinations(input_line, i + 1, prefix + 'm');
			print_commbinations(input_line, i + 1, prefix + 'n');
			print_commbinations(input_line, i + 1, prefix + 'o');
		}
		else if (input_line[i] == '7') {
			print_commbinations(input_line, i + 1, prefix + 'p');
			print_commbinations(input_line, i + 1, prefix + 'q');
			print_commbinations(input_line, i + 1, prefix + 'r');
			print_commbinations(input_line, i + 1, prefix + 's');
		}
		else if (input_line[i] == '8') {
			print_commbinations(input_line, i + 1, prefix + 't');
			print_commbinations(input_line, i + 1, prefix + 'u');
			print_commbinations(input_line, i + 1, prefix + 'v');
		}
		else if (input_line[i] == '9') {
			print_commbinations(input_line, i + 1, prefix + 'w');
			print_commbinations(input_line, i + 1, prefix + 'x');
			print_commbinations(input_line, i + 1, prefix + 'y');
			print_commbinations(input_line, i + 1, prefix + 'z');
		}
	}
}

int main() {
	string input_line;
	cin >> input_line;
	int line_size = input_line.size();
	print_commbinations(input_line, 0, "");
	return 0;
}