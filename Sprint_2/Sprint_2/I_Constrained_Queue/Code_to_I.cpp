#include<iostream>
#include<vector>
#include<string>
using namespace std;

class MyQueueSized {
public:
	MyQueueSized() {}

	MyQueueSized(size_t vector_size_inp) {
		max_size = vector_size_inp;
		queue_size = 0;
		tail = 0;
		head = 0;
		queue_container.resize(vector_size_inp);
	}

	void push(int x) {
		if (queue_size == max_size) {
			cout << "error" << endl;
		}
		else {
			queue_container[tail] = x;
			tail = (tail + 1) % max_size;
			queue_size++;
		}
	}

	void peek() {
		if (queue_size > 0) {
			cout << queue_container[head] << endl;
		}
		else {
			cout << "None" << endl;
		}
	}

	void pop() {
		if (queue_size > 0) {
			cout << queue_container[head] << endl;
			head = (head + 1) % max_size;
			queue_size--;
		}
		else {
			cout << "None" << endl;
		}
	}

	void size() {
		cout << queue_size << endl;
	}

private:
	size_t tail;
	size_t head;
	size_t queue_size;
	size_t max_size;
	vector<int> queue_container;
};

int main() {
	int number_of_commands, queue_size, push_number;
	string command;
	cin >> number_of_commands;
	cin >> queue_size;

	MyQueueSized queue(queue_size);
	for (int i = 0; i < number_of_commands; i++) {
		cin >> command;
		if (command == "size") {
			queue.size();
		}
		else if (command == "peek") {
			queue.peek();
		}
		else if (command == "push") {
			cin >> push_number;
			queue.push(push_number);
		}
		else if (command == "pop") {
			queue.pop();
		}
	}


	return 0;
}