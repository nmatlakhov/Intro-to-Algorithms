/*
https://contest.yandex.ru/contest/22781/run-report/76632051/

-- ������� ������ --
1) �� ������ ������������ ���������� vector ��������� ����� Deque, � ������� �� ������� ������ ������������� ����� (����� �������� ��������� �����) m; 
2) ����� ������� �������� ��� ������������� ������ ����;
3) ����� ����� ��������� ����� �� ���������� ����� �������������� ������ ���� � ��������� ����� �������� � ������, ���� ������ ���� �� ��������� ������������� �������;
4) ��� ������� ���� push_front � push_back ���������� ������� head � tail ��� ���������� ���������, ��������� ������ ������������� ����� � ����� ��������� �������� �� ���� ��������;
5) �� ���������� ������������� ������� ���� ��� ������� �������� �������, �� �������� ���������� ���������� � ������� ������ error, ����� ��� � main � ������� ��� ���������;
6) ��� �������� ��������� �� ���� (������ ���� > 0), ��������� ��������� ������� � ������ ���� ����������� � �� ����� ����� ���������� ����� ������� �� �������������� �����;
7) ���� ������ ���� ��� 0, �� ��� �������� ��������� �������� ���������� ���������� � ������� ������ error, ����� ��� � main � ������� ��� ���������;

��������� head - ������ ������� ������� ����, tail - ������ �������� ����� ����, ����� ������ ����� ��������� ��������� ��������:
a) push_front: ��� ���������� �������� � ������� ����, �� ������ �������� head �� ���� ������� ����� (������ ������� �������): head => (head -1 + max_size) % max_size;
b) pop_front: ��� �������� �������� �� ������� ����, �� ������ �������� head �� ���� ������� ������ (�� ������� �������): head => (head + 1) % max_size;
c) push_back: ��� ���������� �������� � ����� ����, �� ������ �������� tail �� ���� ������� ������ (�� ������� �������): tail => (tail + 1) % max_size; 
d) pop_back: ��� �������� �������� �� ����� ����, �� ������ �������� tail �� ���� ������� ����� (������ ������� �������): tail => (tail - 1 + max_size) % max_size;

��� ������� �������� ����� max_size �����������, ����� �������� ������ ��������������� �������� �������.

������ push_front � push_back ������������, ����� ��� pop_front � pop_back ���������� �������� �� ������ � ����� ���� ��������������, ��� ���� ��������� �� ���������� ������, �� ����
�� ���� ��� �������� ������ �� ����� ����������� � ����. 

� ������, ���� ��� ������ ��� �����������, �� ����� ���������� ���������� ���������� � ������� pop_front, pop_back � push_front, push_back ��������������.

-- �������������� ������������ --
��� ������� ������� ���� �������� ��������� ����� �������� ��������� �� ������.
��� ������� ���� ������� ������������� ���������� ��������� ����� �������� ��������� �� ������.

���������� ��������� � ������� ���� ����� �������� ������ ������� �����, �������� ��������� � ������� ���� ����� �������� ������ ������� ������ �� ������������������: 0, 1, 2, ..., m-1, 
��� m - ������������ ������ ����. ��������� ����� ������ ���������� ��� ������� �� ������� �� ����.������ m, �� ���������� �������� ����� � ���������: (0, ..., m-1) => �� ����� ������� �����
�������� ������� � ������� ������� m, �� ������ �������� �������� ���. 

����������, ���������� ��������� � ����� ���� ����� �������� ������ ������� ������, �������� ��������� � ����� ���� ����� �������� ������ ������� ����� �� ������������������: 0, 1, 2, ..., m-1, 
��� m - ������������ ������ ����. ��������� ����� ������ ���������� ��� ������� �� ������� �� ����.������ m, �� ���������� �������� ����� � ���������: (0, ..., m-1) => �� ����� ������� �����
�������� ������� � ������� ������� m, �� ������ �������� �������� ���. 

��� �������� ���� ���������/������������� ����, ������� �������� � ����� �����. �� ��� ������ ���������� �������� ������� ����� �� ������ ������ (� ��� �� ������� ���������� ����).
��������� ������� ������� ���������� �����, � ������� ������ ������ ��� ���������� ��������� � ��� �� ������� ���� ����� ��������� (��������� ��������� �� ������), �� ��� �� ����� ������������.

-- ��������� ��������� --
1) ������������� ������� ����� m: O(m), ��������� ��������� �������� resize ������� ��� O(m);
2) ���������� �������� � ��� �� �������/� �����: O(1), ��������� ������ ������� ����������, � �������� �� ���������� ������� head ��� tail ����������� �� ����������� �����;
3) ������ ������� ��������� ����� n: O(n);
� ����������� �� ���������� ������, ���� m >= n, ���� m < n, ������������� �������� ��������� ����� �������� �� ��������� �� m � n;

�����: O(max(m,n));

-- ���������������� ��������� --
1) ��� ���� ��������� ������ ������������� ����� m, ������������� O(m) ������ ����� ������;
2) ��������� ���������� ��������� ����������� ����������� ������;
����� ������� �������� n ����� ����������� �� ��������� ������ ������� m, ������� ������������ ������ ������������ ������ ����� O(m);

�����: O(m);
*/


#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
using namespace std;

class Deque {
public:
	Deque(size_t max_size_) {
		max_size = max_size_;
		deque_size = 0;
		head = 0;
		tail = 0;
		ring_buffer.resize(max_size, 0);
	}

	void push_front(int value) {
		if (deque_size < max_size) {
			if (deque_size > 0) {
				head = (head + max_size - 1) % max_size;
			}

			if (deque_size < max_size) {
				deque_size++;
			}
			ring_buffer[head] = value;
		}
		else {
			throw runtime_error("error");
		}
		
	}

	void push_back(int value) {
		if (deque_size < max_size) {
			if (deque_size > 0) {
				tail = (tail + 1) % max_size;
			}

			if (deque_size < max_size) {
				deque_size++;
			}

			ring_buffer[tail] = value;
		}
		else {
			throw runtime_error("error");
		}
	
	}

	int pop_back() {
		if (deque_size > 0) {
			int ret_value = ring_buffer[tail];
			if(deque_size > 1){ tail = (tail - 1 + max_size) % max_size; }
			deque_size--;
			return ret_value;
		}
		else {
			throw runtime_error("error");
		}
	}
	
	int pop_front() {
		if (deque_size > 0) {
			int ret_value = ring_buffer[head];
			if(deque_size > 1){ head = (head + 1) % max_size; }
			deque_size--;
			return ret_value;
		}
		else {
			throw runtime_error("error");
		}
	}


private:
	size_t deque_size, max_size, head, tail;
	vector<int> ring_buffer;	
};

int main() {
	int number_of_commands,  value, result;
	size_t deque_max_size;
	string command;
	cin >> number_of_commands >> deque_max_size;

	Deque deque_task(deque_max_size);
	for (int i = 0; i < number_of_commands; i++) {
		cin >> command;
		try {
			if (command == "push_back") {
				cin >> value;
				deque_task.push_back(value);
			}
			else if (command == "push_front") {
				cin >> value;
				deque_task.push_front(value);
			}
			else if (command == "pop_front") {
				result = deque_task.pop_front();
				cout << result << endl;
			}
			else if (command == "pop_back") {
				result = deque_task.pop_back();
				cout << result << endl;
			}
		}
		catch (runtime_error& err) {
			cout << err.what() << endl;
		}

	}


	return 0;
}