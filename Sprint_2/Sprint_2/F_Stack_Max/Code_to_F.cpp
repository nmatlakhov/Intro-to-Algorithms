#include<iostream>
#include<vector>
#include<string>
using namespace std;

class StackMax {
	public:
		StackMax() {
			max_value = 0;
			stack_size = 0;
			last_element_num = 0;
		}

		void push(int x) {
			stack_container.push_back(x);
			last_element_num++;
		}

		void pop() {
			if (last_element_num > 0) {
				stack_container.pop_back();
				last_element_num--;
			}
			else {
				cout << "error" << endl;
			}
		}

		void get_max() {
			if (last_element_num > 0) {
				for (int j = 0; j < last_element_num; j++) {
					if (j == 0) { max_value = stack_container[0]; }
					if (max_value < stack_container[j]) { max_value = stack_container[j]; }
				}

				cout << max_value << endl;
			}
			else {
				cout << "None" << endl;
			}
		}

	private:
		int max_value;
		size_t last_element_num;
		size_t stack_size;
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