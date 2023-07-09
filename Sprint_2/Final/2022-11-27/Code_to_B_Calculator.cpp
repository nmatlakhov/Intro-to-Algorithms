/*
https://contest.yandex.ru/contest/22781/run-report/76601051/

-- ������� ������ --
������� ������ ��������� ���������� � ������ ���������;
1) �� ������ ������������ ������������� ���������� vector ������� ���� ������ Stack. ����������������� ����� 2 ������: push � pop; 
2) ����� push ��������� ���������� ������� � ����� ������� �������� push_back � ����������� ������ �����: stack_size;
3) ����� pop ���������� ����� �����, ���� ������� ����� ����������� � ������� ��������� �� ������ � ��������� ������������� ��������� INT8_MIN (���� ����� � �� ��������� � ������) �����;
-----------
4) ���������������� ����, ����������� ���������� ��� �������� ������� ��������;
5) ��������� �� ���� �������� ���� ������, �� � �������� � ������� getline. ����� ������� ��������� ����� �� ������ ����������� ������ � ���������� ��������� ���� �� ��������� ���������� line;
6) ��� �������� ����� ��������� line � ������� �������� ������ stringstream � ��������� ��������� �� ���� � ������������� �������� temp_input, � ������ ������ - ��������� ������� � ����, ����� - ��� ������;
7) ���� line �������� �����-���� �� ��������: +, -, *, /, �� �� ��������� ������� (�����) �� ������� ����� � �������� ��� �� ��������� ���������� temp_value;
8) � ������ ������� �� ���� ��������� ������ Zero division error � ��������� ���������� ������;
9) �������� �������� ��������� �� ����� � �� ������� ����� �������� ������ �������;
-----------
10) ��� �������� + ���������� � temp_value �������� ������� �������� � ������� �����;
11) ��� �������� * �������� temp_value �� �������� ������� �������� � ������� �����;
12) ��� �������� - �� �� ������� �������� � ������� ����� �������� ������ �������, ��������� ������ ��� ������ � ���� ����� (LIFO �������);
13) ��� �������� / ������ ������� � ������� ����� ����� �� ������ � ����������� � ������� ����� �������������;
	a) ���������� � ������� -\infty ��������� ��������� �������� dfloor, ��������� C++ ��������� ������������� ������� � ������� ����; 
	b) ��� ������� ���������� ������� �� ������� (a % b != 0), ���� ���� �� ��������� �����������, �� �� ������� ���� ����� ������������� (a*b < 0 => a/b < 0) => ����� ������������� � ������� -\infty;
	c) ���� �� ��������� � ������ b), �� ������� dfloor �������� �� ���������� ������� 1, ����� ��������� ������� � ������� -\infty;
	d) ���� ������� ������� ��� ��� �������� ������������, �� dfloor ���������� a/b ��� ��������������� ���������� (��������� ������� � ��� ����� ��������� � ������� -\infty);
-----------
14) ���������� ��������� �� ��������� � ������� �����, ���������� �������� �� ��� ���, ���� �� ���������� ������ ������� ����� ��������;
15) ����� ��������� �����, ������� ����� �� ������� �����, ��������� ��� � ����� ����� ����������� �������;

-- �������������� ������������ --
��� ������� ������� ����� ����������, ������ ������ ����� ����������� ����� ������� � �������� ������ ����� ����������� �� ������� �����. �������� ����� ���������� ��� 
���������� ����� ���������� �� ����� � ��������� ����� ������� ����������� � ����, ����� ��� ������� ��������, ������� �����������. �������� ���������� �� ���������� �������� ��������.
��������� ���� �������� ����� �������� �� ������� ����� � ����� ������� � output;

-- ��������� ��������� --
1) ���������� � ����: ~ O(1) ���������������� ���������, ��������� �������� push_back ��� ���������������� O(1) (� ������ ������ ��� O(n));
2) ��������� � �������� ������ ����� �� �����: O(1), ��������� ������� �� ����� ������ ������������� ������, ��� ������ ��������� (�����������) �������� back � �������� �������� �������� pop_back;
3) ������ ������� ������: O(n) (�����������);
4) ���������� �������� � �������������� ������: O(1);

�����: ��������� ��������� ~ O(n) �� ����� ������� ������ � ��������� ������� ��������/�������;

-- ���������������� ��������� --
����� ������� ������ ��������: 
 - n1 �������;
 - n2 �������� ��������;
 
��������� ������ input_line ����� ��������� n1 + n2 = n ��������, ������� ������ ������ O(n). 
���������� ��� ������:
(1) ������ �������� ������ ��������: � ������ ������ ����� n1 = n � ���� ������ O(n) ������;
(2) ������ �������� ����������� ��������� � ��������: � ������ ������ n1 - 1 = n2, ��������� ��������� ����� �� 1 ������, ��� �������� � ���� ������ �������� O(2) ������, 
��������� � ��� ����� �������� ��� �������� - ����� ������� � ������ �������;
(3) ������ �������� ������� ��������, ����� �������� ����� �������, ��� ��� �������� ����� ������������: ����� n1 - 1 = n2 � ���� ������ �������� O(n1) ������, �� ���������� ���������� ���������;

��������� �������� ����� ���������� ����������� �������� ������.

�����: ���������������� ��������� ~O(n) �� ����� ������� ������;
*/

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stdexcept>
using namespace std;

int dfloor(int a, int b) {
	if (b == 0) {
		throw runtime_error("Zero division error");
	}
	else {
		int res = a / b;
		int corr = ((a * b < 0) && (a % b != 0));
		return res - corr;
	}
}

class Stack {
public:
	Stack() {
		stack_size = 0;
	}

	void push(int x) {
		stack_container.push_back(x);
		stack_size++;
	}

	int pop() {
		int final_result;
		if (stack_size > 0) {
			final_result = stack_container.back();
			stack_container.pop_back();
			stack_size--;
		}
		else {
			final_result = INT8_MIN;
			cout << "error" << endl;
		}
		return final_result;
	}

private:
	size_t stack_size;
	vector<int> stack_container;
};


int main() {
	Stack stack_values;
	string input_line, line;
	getline(cin, input_line);
	istringstream iss(input_line);
	int temp_value, temp_input;

	while (iss >> line) {
		if (stringstream(line) >> temp_input) {
			stack_values.push(temp_input);
		}
		else {
			temp_value = stack_values.pop();
			if (line == "+") { temp_value += stack_values.pop(); }
			if (line == "-") { temp_value = stack_values.pop() - temp_value; }
			if (line == "*") { temp_value *= stack_values.pop(); }
			if (line == "/") {
				try { 
					temp_value = dfloor(stack_values.pop(), temp_value); 
				}
				catch (runtime_error& err) {
					cout << err.what() << endl;
					return 0;
				}
			}
			stack_values.push(temp_value);
		}
	}
	
	cout << stack_values.pop() << endl;

	return 0;
}