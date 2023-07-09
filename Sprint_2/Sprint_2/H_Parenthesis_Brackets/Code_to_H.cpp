#include<iostream>
#include<vector>
#include<string>
using namespace std;

class StackChar {
public:
	StackChar() {
		stack_size = 0;
	}

	void push(char x) {
		stack_container.push_back(x);
		stack_size++;
	}

	void pop() {
		if (stack_size > 0) {
			stack_container.pop_back();
			stack_size--;
		}
	}

	char peek() {
		return stack_container.back();
	}

	size_t size() {
		return stack_container.size();
	}

private:
	size_t stack_size;
	vector<char> stack_container;
};

void is_correct_bracket_seq(const string& input_str) {
	StackChar stack;
	int str_size = input_str.size();
	int insert_size = 0;
	if (str_size == 0) { cout << "True" << endl;  return; }
	
	for (int i = 0; i < str_size; i++) {
		char par = input_str[i];
		if ((par == '[') || (par == '(') || (par == '{')) {
			insert_size++;
			stack.push(par);
		}
		else {
			if(insert_size == 0){ cout << "False" << endl;  return; }

			if ((par == ']') && (stack.peek() == '[')) { stack.pop();  }
			if ((par == ')') && (stack.peek() == '(')) { stack.pop();  }
			if ((par == '}') && (stack.peek() == '{')) { stack.pop(); }
			insert_size--;
		}
	}
	
	if ((insert_size == 0) && (stack.size() == 0))  { cout << "True" << endl;} else { cout << "False" << endl; }

}

int main() {
	string command;
	getline(cin, command);
	is_correct_bracket_seq(command);
	return 0;
}