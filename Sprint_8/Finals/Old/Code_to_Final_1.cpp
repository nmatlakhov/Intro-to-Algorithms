/*
https://contest.yandex.ru/contest/26133/run-report/84059091/
������� ������:
1) ����������� �������� ������������ ������ � ������/������� ������;
2) ���������� ��� ������ ������ � ������ � ��������� ���;
3) ������� ������ ������� �� �������������� ������� � ���������. ������ ����������� ����� �� ���� �����;
4) ����������� ��������� ��� ������, ���� ���� �� ��������� ����������� ����� ������ => ����� ������� = ����� �� ���� �����, ���� ���� �� ��������� ������ �������� ������;
5) �� ����� �������� ���������� �������������� ������ � �������;

�������������� ������������:
1) ��� ����������, ��� ������� ����� ������������� � ������������������ �������, ��������������, ���� ���� ���������� ����� �������, �� �� ����� ��������, ��� ��� ����� 
������� ������������������ ������, ��� � ��� ����� �������. ��� ���� ����� ����� ����� ������� ����� ��������, ��� ��� ��-�� ������������������� ������� �����;
2) ��������� ������������ ���������, �� ���� ���� ������ ������������ �������� => ������ �� ����� ������� ������� ����� ����������, ���� ���� ����� ������ =>
������ ����� ����� ��������� ��� ���� ��������� ����� �����;

��������� ���������: 
����� ����� n - ����� �����, ����� ������ ����� ���������� �� ����, ��� m, ������������� ��������� 1-�� ������ ����� �������� � ������ ������ O(m), ����� � ���� ����� ����� ���������� �����:
1) ����������� �������� ������������ ����� � ������ ������: ~O(mn);
2) ���������� ������� �� ������ ����� � ������ ������: ~O(nm log(nm));
3) ������������ ��������� ����� � ������ ������: ~O(nm);
�����: ~O(nm log(nm))

���������������� ���������:
����� ����� n - ����� �����, ����� ������ ����� ���������� �� ����, ��� m, ������������� ��������� 1-�� ������ ����� �������� � ������ ������ O(m):
1) ����������� �������� ������������ ����� � ������ ������: ~O(mn), ��������� ���������� ������������ ����������, �� ����� ����� �������������� ���. ������, �� � �������
�� ����� ��������� O(mn), ��������� �������� �� ����� ���������� ������� ����� ���, ��� �������� � ������;
2) �������� ������� �� ������ �����: ~O(nm);
�����: ~O(nm)

*/

#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

string unpack_string(string text, int multiply) {
	char s;
	string result = "", final_result = "";
	int n = text.size(), j = 0, mult_next = 0, count = 0;

	while(j < n) {
		if (isdigit(text[j])) {
			mult_next = text[j] - '0';
			j++;
		}

		if (text[j] == '[') {
			count++;
			j++;

			string temp = "";
			while (count > 0) {
				if (text[j] == '[') { count++; }
				if (text[j] == ']') { count--; }
				if (count == 0) { j++; break; }
				temp += text[j];
				
				j++;
			}

			result += unpack_string(temp, mult_next);
		}

		if (isalpha(text[j])) {
			result += text[j];
			j++;
		}

	}
	
	
	for (int i = 0; i < multiply; i++) {
		final_result += result;
	}


	return final_result;
}

string largest_common_prefix(vector<string>& strs) {
	sort(strs.begin(), strs.end());
	int n = strs.size();

	string first = strs[0], last = strs[n - 1],result = "";
	int min_dist = min(first.size(), last.size());

	int i = 0;
	while ((i < min_dist) && (first[i] == last[i])) {
		result += first[i];
		i++;
	}
	return result;
}

int main() {
	int n;
	cin >> n >> ws;
	string temp;

	vector<string> strs(n, "");

	for (int i = 0; i < n; i++) {
		getline(cin, temp);
		strs[i] = move(unpack_string(temp, 1));
	}

	string result = largest_common_prefix(strs);

	cout << result << endl;

	return 0;
}