/*
https://contest.yandex.ru/contest/26133/run-report/84110566/
������� ������:
1) ����������� �������� ������������ ������ � ������/������� ������;
2) ������� ����������� � ������������ ������;
3) ����������� ��������� ��� ������, ���� ���� �� ��������� ����������� ����� ������ => ����� ������� = ����� �� ���� �����, ���� ���� �� ��������� ������ �������� ������;
4) �� ����� �������� ���������� �������������� ������ � �������;

�������������� ������������:
1) ��� ������ ������������ � ����������� �����, ������ ����� ����������� � ������������������ �������, ��������������, ���� ���� ���������� ����� �������, �� �� ����� ��������, ��� ��� ����� 
������� ������, ��� � ��� ����� �������. ��� ���� ����� ����� ����� ������� ����� ��������, ��� ��� ��-�� ������������������� �������;
2) ��������� ������������ ���������, �� ���� ���� ������ ������������ �������� => ������ �� ����� ������� ������� ����� ����������, ���� ���� ����� ������ =>
������ ����� ����� ��������� ��� ���� ��������� ����� �����;

��������� ���������: 
����� ����� n - ����� �����, ����� ������ ����� ���������� �� ����, ��� m, ������������� ���������� 1-�� ������ ����� �������� � ������ ������ O(m), ����� � ���� ����� ����� ���������� �����:
1) ����������� �������� ������������ ����� � ������ ������: ~O(nm);
2) ������������ ��������� ����� ��� ������ ���������� � ���������� ������: � ������ ������ ~O(nm)
3) ������������ ��������� ���� ����� � ������ ������: ~O(m);
�����: ~O(nm)

���������������� ���������:
����� ����� n - ����� �����, ����� ������ ����� ���������� �� ����, ��� m, ������������� ��������� 1-�� ������ ����� �������� � ������ ������ O(m):
1) ����������� �������� ������������ ����� � ������ ������: ~O(nm), ��������� ���������� ������������ ����������, �� ����� ����� �������������� ���. ������, �� � �������
�� ����� ��������� O(nm), ��������� �������� �� ����� ���������� ������� ����� ���, ��� �������� � ������;
2) �������� ����������� � ������������ ������: � ������ ������ ~O(m)
�����: ~O(nm)

*/

#include<string>
#include<iostream>
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

string largest_common_prefix(string max_string, string min_string) {
	string result = "";
	int min_dist = min_string.size();

	int i = 0;
	while ((i < min_dist) && (min_string[i] == max_string[i])) {
		result += min_string[i];
		i++;
	}
	return result;
}

int main() {
	int n;
	cin >> n >> ws;
	string temp,line,  min_string = "", max_string;

	for (int i = 0; i < n; i++) {
		getline(cin, line);
		temp = move(unpack_string(line, 1));
		if (i == 0) { 
			min_string = temp;
			max_string = temp;
		}
		if (min_string > temp) {
			min_string = temp;
		}
		if (max_string < temp) {
			max_string = temp;
		}
	}

	string result = largest_common_prefix(max_string,min_string);

	cout << result << endl;

	return 0;
}