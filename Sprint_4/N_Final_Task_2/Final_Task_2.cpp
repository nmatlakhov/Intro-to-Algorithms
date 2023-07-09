/*
 https://contest.yandex.ru/contest/24414/run-report/79980076/
������� ������ :
��������������� �� �������� ������.
1) ��������� ����� hashTable ���������� ������ ������ �� ���, ������ ���� = {����, ��������};
2) �������� ����������� � ������� ������ ������� � ���������� STL list;
3) ���������� ������ ������� ���������� � ������� �������� ������� �� ������;
4) ������ ���������� ������� � 10 ��� ������, ��� ����� ����������� �������� �� �������������� ������ ������� �����;
5) ���-�������: hash(i) = i;

�������������� ������������ :
1) ����� ������� (����� ������ ������ �� ���) - ��������� ��������;
2) ���������� ������ ������� ���������� � ������� �������� ������� �� ������, ����� �������� �� ������ n = 10^6, ��������� ����� ������ ��� ���� �� ������ ������������ N = 10^5, �����������, ��� 
����� ������ � 10 ��� ������, ��� ����� ��������: n ~ 10*N, ����� ����� ������ ������� ������ M = p_k �� �������������� ������������� ������ ������� ����� (������� �� STL ����������) ���, 
�����: M = p_k > n/10 ~ N, �� p_{k-1} <= n/10 ~ N, �� ���� ������ ������� ����� ������������� ����� �������� / 10. ����� ����� ����� ������� 15, ����� ��������� ������� ����� ���� ������ 10^5.
����� N/M < 1 => �������� �������/�������� ����� ����������� � ������� �� O(1 + N/M) ~ O(1);
3) ������������� �� ������� �� �����������;
4) ��� ������� �� �����, ������� ����������� ��� (hash(i) = i), ����� ����� �������. ����� ���� � ����� ������� ������ ��������� ���� � ������������� ������ ���� �� ��������� ���� � �����,
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
����� N = number_of_commands - ����� �������, M = ��������� ������� ����� ��� ������� ������� �� ������;
0) ����� �������� ����� ��� �������� ������� �� ������: ~O(1) - ����������� ������������ ������ �� 15 ���������;
1) �������� ������� �� ������: ~O(M);
2) ���������� ��������: � ������� O(1), � ������ ������ (����� ��� �������� �������� � ���� � �� �� �������), �������� ��������� ~O(N);
3) ���� N ������: ~O(N);
4) ����� ����������: � ������ ������ (����� ������ ������� ��� ���� get, ���� erase) ~O(N);
3) ����� �� ���� ���������������� �������: O(1);
�����: ��������� ��������� ~O(M + N);

���������������� ��������� :
0) ������ �� ������� �����: ~O(1);
1) ������ �� ������: ~O(M);
2) ���� �������: ~O(N);
3) ����� ����������: � ������ ������ (����� ������ ������� ��� ���� get, ���� erase) ~O(N);
�����: ���������������� ��������� ~O(M + N);

*/

#include<iostream>
#include<string>
#include<cmath>
#include<list>
#include<utility>
using namespace std;
using Iterator = list<pair<int, int>>::iterator;
constexpr uint32_t num_distinct_sizes = 15;
static const uint32_t g_a_sizes[num_distinct_sizes] =
{
	/* 0     */              5ul,
	/* 1     */              11ul,
	/* 2     */              23ul,
	/* 3     */              47ul,
	/* 4     */              97ul,
	/* 5     */              199ul,
	/* 6     */              409ul,
	/* 7     */              823ul,
	/* 8     */              1741ul,
	/* 9     */              3469ul,
	/* 10    */              6949ul,
	/* 11    */              14033ul,
	/* 12    */              28411ul,
	/* 13    */              57557ul,
	/* 14    */              116731ul,
};

class hashTable {
public:

	explicit hashTable(size_t query_size) {
		setHashSize(query_size);
		container = new list<pair<int, int>>[bucketSize];
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

	int bucketNumber(int hash_value)  {
		return hash_value % bucketSize;
	}

	int hashValue(int key)  {
		return key;
	}

	void setHashSize(size_t query_size) {
		size_t check_value = query_size / 10;
		for (size_t i = 0; i < num_distinct_sizes; i++) {
			if (check_value < g_a_sizes[i]) {
				bucketSize = g_a_sizes[i];
				break;
			}
		}

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
		int bucket = bucketNumber(hashValue(key));
		contBucket = &container[bucket];

		itListBegin = contBucket->begin(), itListEnd = contBucket->end();
		itListKey = searchContainer(itListBegin, itListEnd, key);
	}

private:
	list<pair<int, int>>* container = nullptr;
	Iterator itListBegin, itListEnd, itListKey;
	list<pair<int, int>>* contBucket = nullptr;
	size_t bucketSize;
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

	size_t number_of_commands;
	int key_value, value, result;
	string command;

	cin >> number_of_commands;

	hashTable hash_map(number_of_commands);

	for (size_t i = 0; i < number_of_commands; i++) {
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