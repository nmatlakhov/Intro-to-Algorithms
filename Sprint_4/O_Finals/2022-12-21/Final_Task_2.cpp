/*
https://contest.yandex.ru/contest/24414/run-report/79872693/
������� ������ :
��������������� �� �������� ������.
1) ��������� ����� hashTable ���������� ������ ������ �� ���, ������ ���� = {����, ��������};
2) �������� ����������� � ������� ������ ������� � ���������� STL list;
3) ���������� ������ ������� ���������� � ������� �������� ������� �� ������;
4) ������ ���������� ������� ���, ����� ��������� ��������� ����� ������ � 10^5 � ��� ���� ���� ������� ������: 100'019;
5) ���-�������: hash(i) = i;

�������������� ������������ :
1) ����� ������� (����� ������ ������ �� ���) - ��������� ��������;
2) ���������� ������ ������� ���������� � ������� �������� ������� �� ������, ����� ��������� �� ������ N = 10^5, ����� ������ M = 100'019, N/M ~ 1 => �������� �������/�������� ����� ����������� 
� ������� �� O(N/M) ~ O(1);
3) �������������/��������������� �� ������� �� �����������;
4) ��� ������� �� �����, ������� ����������� ����� �������, ����� � ����� ������� ������ ��������� ���� � ������������� ������ ���� �� ��������� ���� � �����,
���� �� ����� ����� � ������� ������������� �����;
5) �������� - put_value => 
	(1) ���� ������ == ����� �����, �� ������������� ����� ������� � ������ �����; 
	(2) ���� ������ != ����� �����, �� �������� �� ������ ��������������;
6) ���� �������� - get_value => 
	(1) ������������ �������� �� ������, ���� ������ != ����� �����; 
	(2) ���� ������ == ����� �����, �� ������������ -1;
7) ���� �������� - erase_value => 
	(1) ���� ������ != ����� �����, �� ������� ��������� �� ����� � �������� �������� ������������ � ����� ������ �������; 
	(2) ���� ������ == ����� �����, �� ������������ -1;
8) ���� � ��������� get_value, erase_value ���� �������� -1, �� ���������� "None", ����� ��������� �������� ��������;
9) ����� �������� �����/������ ���� �����������, � ����� ������ ������������ "\n" ������ endl. ����� ��������� ������������� ������� �����/������ � ������������� ��
������������ C ��������, ��� ����������� �������� ���������� ���������;

��������� ���������:
����� N = number_of_commands - ����� �������;
1) �������� ������� �� ������: ~O(10^5);
2) ���������� ��������: � ������� O(1), � ������ ������ (����� ��� �������� �������� � ���� � �� �� �������), �������� ��������� ~O(N);
3) ���� N ������: ~O(N);
4) ����� ����������: � ������ ������ (����� ������ ������� ��� ���� get, ���� erase) ~O(N);
3) ����� �� ���� ���������������� �������: O(1);
�����: ��������� ��������� ~O(10^5 + N);

���������������� ��������� :
1) ������ �� ������: ~O(10^5);
2) ���� �������: ~O(N);
3) ����� ����������: � ������ ������ (����� ������ ������� ��� ���� get, ���� erase) ~O(N);
�����: ���������������� ��������� ~O(10^5 + N);

*/
#include<iostream>
#include<string>
#include<cmath>
#include<list>
#include<utility>
using namespace std;
using Iterator = list<pair<int, int>>::iterator;
constexpr int hashSize = 100'019;

class hashTable {
public:

	explicit hashTable() {
		container = new list<pair<int, int>>[hashSize];
	}

	~hashTable() {
		delete[] container;
	}

	void put_value(int key, int value) {
		setListIterators(key);

		if (itListKey == itListEnd) {
			contBucket->push_front({ key, value });
		}
		else {
			itListKey->second = value;
		}


	};

	int get_value(int key) {
		setListIterators(key);

		if (itListKey == itListEnd) { return -1; }

		return itListKey->second;
	};

	int erase(int key) {
		setListIterators(key);

		if (itListKey == itListEnd) { return -1; }
		int result = itListKey->second;

		contBucket->erase(itListKey);

		return result;
	};

	int bucketNumber(int hash_value) const {
		return hash_value % hashSize;
	}

	Iterator searchContainer(Iterator itContainerBegin, Iterator itContainerEnd, int key) {

		auto itCont = itContainerBegin;
		while (itCont != itContainerEnd) {
			if (itCont->first == key) { break; }
			itCont++;
		}
		return itCont;
	}

	void setListIterators(int key) {
		int bucket = bucketNumber(key);
		contBucket = &container[bucket];

		itListBegin = contBucket->begin(), itListEnd = contBucket->end();
		itListKey = searchContainer(itListBegin, itListEnd, key);
	}

private:
	list<pair<int, int>>* container = nullptr;
	Iterator itListBegin, itListEnd, itListKey;
	list<pair<int, int>>* contBucket = nullptr;
};

void print_result(int value) {
	if (value == -1) {
		cout << "None" << "\n";
	}
	else {
		cout << value << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int number_of_commands, key_value, value, result;
	string command;
	
	cin >> number_of_commands;

	hashTable hash_map;

	for (int i = 0; i < number_of_commands; i++) {
		cin >> command;

		try {
			if (command == "get") {
				cin >> key_value;
				result = hash_map.get_value(key_value);
				print_result(result);
			}
			else if (command == "put") {
				cin >> key_value >> value;
				hash_map.put_value(key_value, value);
			}
			else if (command == "delete") {
				cin >> key_value;
				result = hash_map.erase(key_value);
				print_result(result);
			}

		}
		catch (runtime_error& err) {
			cout << err.what() << endl;
		}
	}

	return 0;
};