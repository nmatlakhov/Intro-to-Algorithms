#include<iostream>
#include<vector>
#include<string>
using namespace std;

class StackMax {
public:
	StackMax() {
		last_element_num = 0;
	}

	void push(int x) {
		stack_container.push_back(x);
		if (aux_container.empty()) {
			aux_container.push_back(x);
		}
		else {
			if (aux_container.back() <= x) { aux_container.push_back(x); }
		}
		last_element_num++;
	}

	void pop() {
		if (last_element_num > 0) {
			if (stack_container.back() == aux_container.back()) {
				aux_container.pop_back();
			}
			stack_container.pop_back();
			last_element_num--;
		}
		else {
			cout << "error" << endl;
		}
	}

	void get_max() {
		if (last_element_num > 0) {
			cout << aux_container.back() << endl;
		}
		else {
			cout << "None" << endl;
		}
	}

private:
	size_t last_element_num;
	vector<int> aux_container;
	vector<int> stack_container;
};

int main() {
	int number_of_commands, push_number;
	string command;
	StackMax stack;
	cin >> number_of_commands;
	for (int i = 0; i < number_of_commands; i++) {
		cin >> command;
		if (command == "get_max") {
			stack.get_max();
		}
		else if (command == "push") {
			cin >> push_number;
			stack.push(push_number);
		}
		else if (command == "pop") {
			stack.pop();
		}
	}


	return 0;
}