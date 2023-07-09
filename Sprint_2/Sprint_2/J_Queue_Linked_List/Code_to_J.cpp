#include<iostream>
#include<string>
using namespace std;


struct Node {
	int value;
	Node* next;
	Node(int value, Node* next) : value(value), next(next) {}
};

class ListQueue {
public:
	ListQueue() {
		queue_size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void put(int x) {
		Node *insert_node = new Node(x, nullptr);
		if (head == nullptr) {
			head = insert_node;
			tail = head;
		}
		else {
			tail->next = insert_node;
			tail = tail->next;
		}
		queue_size++;
	}

	void get() {
		if (queue_size > 0) {
			cout << head->value << endl;
			Node* temp = head->next;
			delete head;
			head = temp;
			queue_size--;
		}
		else {
			cout << "error" << endl;
		}
	}

	void size() {
		cout << queue_size << endl;
	}

private:
	size_t queue_size;
	Node* tail;
	Node* head;
};

int main() {
	int number_of_commands, put_number;
	string command;
	cin >> number_of_commands;

	ListQueue list_queue;
	for (int i = 0; i < number_of_commands; i++) {
		cin >> command;
		if (command == "size") {
			list_queue.size();
		}
		else if (command == "put") {
			cin >> put_number;
			list_queue.put(put_number);
		}
		else if (command == "get") {
			list_queue.get();
		}
	}


	return 0;
}