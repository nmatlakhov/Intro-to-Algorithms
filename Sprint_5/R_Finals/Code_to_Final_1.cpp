/* https://contest.yandex.ru/contest/24810/run-report/81721555/  */
/*
������� ������:
�� ������ ���� ����� ���� �� ��������� ����� ��� ����������. ������������ ��������� ��������� (participant), � �� ��� �������� �������� �������, ��������������� ���������� � ������. 
����� ���� ���� ����������� ������� heapAdd, popMax, heapSort � ������������ � ��������� � ������ "������������ �������. ������� � ��������"
https://practicum.yandex.ru/learn/algorithms/courses/7f101a83-9539-4599-b6e8-8645c3f31fad/sprints/88123/topics/e7dbf42a-fd5a-434b-990d-9cfe0e3a10c8/lessons/116802f2-0842-4195-9d12-13e7bf0efad1/

���������� ����������� � ��������� �������. ����� ���� ��������� ����� ���������� �� ����� ������� �������� printSortVector.


�������������� ������������:

1) ��������� ����� ��������: participant, �� ������� ������������� �������� ���������: <;

2) �������� a < ��������� b, ���� ����� ���� �� ��������� �������:
	�) # �������� ����� a < # �������� ����� b;
	�) (# �������� ����� a == # �������� ����� b) � (����� a > ����� b);
	�) (# �������� ����� a == # �������� ����� b) � (����� a == ����� b) � (��� a > ��� b � ������������������ ������, �� ���� ��� b ��� ������, ��� a);
���������� ��������� ����� � C++ ������������ ������� true ��� string a < string b, ���� a ����������������� ������, ��� b;

3) ����� ��������� ������ ��������� � ���������� �������� ��������� � ������� ������� siftUp, siftDown, heapAdd, popMax, heapSort. ������ ��� ������������ ����������� ������������ ������� �����
���������� � �������� �������� ��������������. heapAdd ��������� ������� � �������, popMax ������� ������� �� �������. (������� ����� ��� ������ �� ������� � ������ ����������). ���������� �� siftUp,
siftDown, heapAdd, popMax, heapSort ���� �� ����;

4) ����������� ������ ���������� � ������ students, ����� ������ �������� � ������� heapSort, ����� ���� �������� ������������� (�� ��������) ������ ���������;

5) �������� printSortVector ��������� �� ������� ��������� � ������� ��� ���;

��������� ���������:
1) �����������, ��� � ��� n ����������, ����� �� ���� ����� ���������� n �������, ������ �� ������� �������� �� 20 �������� ������ � ����� 2 ����� � ��� => ��������� ������ �� ������� �� ����������
����� ����� �������� 22 �� ���������� ������ � ���� ������ => ��������� ������ n ���������� O(22n);

2) �������� ������������� ���������� � ������ ������ �������� �� ��������, ��� O(n log(n)). ���������� i-�� �������� � ���� �������� O(log i) ��������� ���������.
������� ���������� m ��������� (������ � �����) ������:
O(log 1) + O(log 2) + ... + O(log n) <= O(log n) + O(log n) + ... + O(log n) = O(n log (n))

3) ���������� m ��������� �� �������� ���� ����� ������ � ������ ������ �� ������, ��� O(n log(n))
�����: ��������� ��������� � ������ ������ �� ������, ��� O(n log(n))

���������������� ���������:
1) ������ ��������� ��������� ����� ��������� �� ������ 22 (20 �� ����� � 2 �� ������ � ����� �������� �����). ����� ����� �������� � ������� ����� ����� n => ���������������� ���������
����� ������� O(22n), ����� ����� ������ �������������� ������ ��� ���� � ������ ��� ����������. ������ ��� ���� ������ ������� O(22n). ����� �������� ���� ����� ���������� � ����� ������, � ���� ����
����� ����������� (�� ���� pop_back ��������);

2) ���������� ������������� ���������� ����� �������� � ����� ������, ������� ����� ����� ������������� 4 ������� ������� ������� O(22n); 

3) ���� ������ �������� ����� ����� ����� 20 => ������ ������ ����� ��� ������� 20 ����, + ��� 8 ���� �� ��� ����� �������� => ��� n = 100,000 �� ������� �� ����� 2,800,000 ���� ������� ������ =>
=> 2,800,000/(1024^2) =~ 2,67 ��, �.�. � ������ ������ ����� ������ �� ������ 3 �� �� ���� ������;

4) �����: ���������������� ��������� ����� ������� ~ O(bn) � ������ ������, ��� b <= 24;

�������: ���������������� ��������� ~O(n). �������������� ������ ������������ ��� �������� ���� (������� O(n)) � ������� ��� ������ ����������.

*/

#include<vector>
#include<iostream>
#include<string>
#include<utility>
using namespace std;

struct participant {
	string part_name;
	int nsolved;
	int penalty;
	participant() : part_name(""), nsolved(0), penalty(0) {}
	participant(string name_, int nsol, int penalt) : part_name(name_), nsolved(nsol), penalty(penalt) {}
};

using Iterator = vector<participant>::iterator;

bool operator<(const participant& lhs, const participant& rhs) {
	if (lhs.nsolved < rhs.nsolved) {
		return true;
	}
	else if (lhs.nsolved == rhs.nsolved) {
		if (lhs.penalty > rhs.penalty) {
			return true;
		}
		else if (lhs.penalty == rhs.penalty) {
			if (lhs.part_name > rhs.part_name) {
				return true;
			}
		}
	}
	return false;
}

int siftDown(vector<participant>& heap, int idx) {
	/*����������� ���� ������� heap ��� �������� �������� �� ������� idx*/

	//������ ���� ������������ ���������� �� 1, ����� ���� ������� ����������� � ��������� � ���������� 1-�� ������� 
	int hsize = heap.size() - 1;

	//��������� �������� ������ � ������� �������� ���� (����) � �������� idx
	int left = 2 * idx;
	int right = 2 * idx + 1;

	//��������� ���������� ��� �������� ������� ���� (����) ������� � ������������ ���������
	int idx_largest;

	//���� ������ ���� ������ ������� ������ �������, �� � �������� ���� �� ��� � ������� ������ ������ �������� ��������
	if (hsize < left) { return idx; }

	//���� ������ ���� ������ ������� ������� �������, �� �� ��������� �������� ���� � ���� ���� �������
	//������� ������ ������� � ���������� ���������
	if (right <= hsize) {
		if (heap[left] < heap[right]) {
			idx_largest = right;
		}
		else {
			idx_largest = left;
		}
	}
	else {
		idx_largest = left;
	}
	//��������� ���������� ��� ������ ������ ������� ����� ����������� ����
	int return_idx = idx;

	//���� �������� � ���� ������, ��� �������� � ��� �������, �� �� �������� ������� � �������� �������
	if (heap[idx] < heap[idx_largest]) {

		//������ ������� �������� � �������
		swap(heap[idx], heap[idx_largest]);
		
		//�������� ����������� ������, ���� �������� ������� �� �������� ������ �������� �������� (����� ���������� �������������� ��������)
		return_idx = siftDown(heap, idx_largest);
	}

	return return_idx;
}

/*����������� ����� ������� heap ��� ���������� �������� �� ������� idx*/
int siftUp(vector<participant>& heap, int idx) {
	
	//���� ������� ��� ������ - ��������� ������
	if (idx <= 1) { return idx; }

	//��������� ������ �������� (������� ������������� => �� ���������� ��������� ��� ����������)
	int parent_idx = idx / 2;

	//��������� ���������� ��� ������ ������ ������� ����� ����������� �����
	int return_idx = idx;

	//���� �������� �������� �� �������� ������, ��� �������, �� ������ �� �������
	if (heap[parent_idx] < heap[idx]) {

		//��������� ����
		swap(heap[idx], heap[parent_idx]);

		//���������� �������� ������� �� ��� ������������ ���� ����� ������
		return_idx = siftUp(heap, parent_idx);
	}

	//����������� ������� ����, ����� ��� �����������
	return return_idx;
}

/*���������� �������� � ������������ �������*/
void heapAdd(vector<participant>& heap, participant& item) {
	
	//��������� ������� ������ �������, ��������� ������ �� ����� � ���� �������� ����� �������� ����� �������
	int idx = heap.size();

	//���������� ������ ��������
	heap.push_back(item);

	//����������� ������������ �������� �����
	siftUp(heap, idx);
}

/*�������� ������ ������������� �������� �� ������� � ������� ����� �������� ��������*/
participant popMax(vector<participant>& heap) {

	//��������� ������ ������������� ��������, ������ ��� �� ��������� ����������
	participant result = heap[1];

	//������ ������ ������������� �������� ����� ��������� ��������� � ������� (����� ����������� �������� ��������������� �������� ����)
	int idx = heap.size() - 1;
	heap[1] = heap[idx];

	//�������� ���������� �������� �� �������� ���� � ����������� ��� ����
	heap.pop_back();
	siftDown(heap, 1);

	//����������� �������� ������ ������������� �������� �� ������ � �����������
	return result;
}

/*������������� ����������*/
vector<participant> heapSort(Iterator begin, Iterator end) {

	//������� ��� �������: ������ - �������� ����, ���� ����������� 1 ������ ������� (��� ������ � ���������) � ������ � ������� ����� ������������ ������������� ��������
	vector<participant> heap(1), sortedVector;

	//��������� � �������� ���� (end - begin) ���������
	for (auto it = begin; it != end; it++) {
		heapAdd(heap, *it);
	}

	//�� ��� ��� ���� ���� �� ������ (�� �������� ������ ������ �������) ����� ����������� �� �� �������� ������������ ��������
	while (heap.size() > 1) {
		sortedVector.push_back(move(popMax(heap)));
	}
	return sortedVector;
}


void printSortVector(const vector<participant>& result) {
	int n = result.size();
	for (int i = 0; i < n; i++) {
		cout << result[i].part_name << endl;
	}
}

int main() {
	int n;
	cin >> n;
	vector<participant> students(n);

	string temp_string;
	int temp_sol, temp_penalty;
	for (int i = 0; i < n; i++) {
		cin >> temp_string >> temp_sol >> temp_penalty;
		participant temp_p(temp_string, temp_sol, temp_penalty);
		students[i] = move(temp_p);
	}
	students = move(heapSort(students.begin(), students.end()));

	printSortVector(students);
	return 0;
}