/*
https://contest.yandex.ru/contest/25597/run-report/83542362/
������� ������:
�������� ������, �� ����� �������� ���� ������ � ������, ���� ��������� �������, ���� �������� ������ �������, ���� ������� ������ ������� �� ������.
�� ���� �������� ��� ������ ������� m � n ��������������.

1) � ������� dp ����� �������� ���������� ����������� (��) ��� �������� ������ i � j � ������ dp[i % 2][j]. 
����� ���������� ������ ������ ����� ������������ �� ���� ���� ���������� ������� �� 2� ����� => ��� ������: 2*(n+1);

2) ���� ������ ������ ������, �� ���������� ����������� ��� ������ ��������� ����� ����� � �����, ��������: line1 = "abc" � line2 = "" => ���������� ����������� = 3, ���������
���������� � ������ ������ �������� ��� ����� ������� => dp[0][j] ����� ���������� ������ �������� = j;

3) � �������� �������� �� �������� ���� �� ����� �� ���� ������. �������� �������� ����� ���� �� ������ (����� ������� �� �������) ���, ����� ���� �������� �������� �� �� ���������� �����:
	�) ��� �������� �� ����� ������ � ������� dp, �� ������������� �������� � ������ dp[i % 2][0] = i, ��������� ��� �� ��� ������ ������ ������ => ����� ����� ������ ������;
	�) ��� �������� �� ����� ���, ��� �� ������������� ��������� ������ i � j, ������� �� ������� ������� �� �� ����� ���� ������� ����� �� i-�� � j-�� ����� (line1[i-1] == line2[j-1]). 
		(1) ���� ������� ������� => �� �� ������������� ������������ �������� ������ i-1 � j-1 (������� ������������ �������) => ������� ������ dp[(i-1) % 2][j-1];
		(2) ���� ������� ������ => �� ������������� �� 1 ������������ �������� ������ i-1 � j-1, ��������� ��������� ������ ������ ������� �� ������ (������) => ������� ������ dp[(i-1) % 2][j-1];
	�) �������, ��� ����� � ������ �������� ������� �� 1-�� ������ => P� ������������� �� 1 ������������ �������� ������ i-1 � j (�������� �������) => ������� ������ dp[(i-1) % 2][j];
	�) �������, ��� ����� � ������ �������� ������� �� 2-�� ������ => P� ������������� �� 1 ������������ �������� ������ i � j-1 (�������� �������) => ������� ������ dp[i % 2][j-1];

4) ����� �������, �� ������ ���� �� �������, ��� ����� �������: �������� ������, �������� ������ � �������� ���, ������� ������ �� 1-�� ��� 2-�� ������;
5) ���������� ����������� ��� ���� ����� ����� ���������� � ������ dp[m % 2][n], ��� �� ��� ���� ����� = ������ ����������;

�������������� ������������:
������� ����� ������, ��������� �� ������ ���� �� ����� �������� ����������� ���������� ����������� ����� ��������� ���� ��������� �������� �� �������� � ����� ��������� �� 2� �������� ������������� 
������� ������� (m+1)*(n+1) => ����� ������ �� �������� ~O(n); �� ������ ���� � ������ dp ����� ���������� �� ���������� �������� => � ������ dp[m % 2][n] 
����� ���������� �� ��� �������� ������������ ����� (�.�. ����� ��������), ����� �� �������� �� ������ 2-� �������� ���. ������� ������� (m+1)*(n+1);

��������� ���������:
1) ������ ����� ����� m � n: ~O(m + n)
2) �������� ���������� �������, ������� 2*(n+1): ~O(n)
3) ����������� �� 0 ������ � �� 0 �������: ~O(m + n)
4) ����������� �� ������� ������� ������ 1 ��� ������� ������� ������ 2: ~O(mn)
�����: ~O(mn)

���������������� ���������:
1) ������ ����� ����� m � n: ~O(m + n)
2) �������� �������, ������� 2*(n+1): ~O(2*(n+1)) ~O(n)
�����: ~O(m + n)

*/


#include<string>
#include<iostream>
#include<vector>
using namespace std;

int min(int x, int y, int z) { return min(min(x, y), z); }

int EditDistDp(string line1, string line2) {
	int m = line1.size();
	int n = line2.size();

	vector<vector<int>> dp(2, vector<int>(n + 1, 0));

	for (int j = 1; j<= n; j++) {
		dp[0][j] = j;
	}

	for (int i = 1; i <= m; i++) {
		dp[i % 2][0] = i;
		for (int j = 1; j <= n; j++) {
			int value = 1;
			if (line1[i - 1] == line2[j - 1]) {
				value = 0;
			}

			dp[i % 2][j] = min(dp[(i - 1) % 2][j] + 1, dp[i % 2][j - 1] + 1, dp[(i - 1) % 2][j - 1] + value);
		}
	}

	return dp[m % 2][n];
}


int main() {
	string line, line2;
	getline(cin, line);
	getline(cin, line2);

	int result = EditDistDp(line, line2);

	cout << result << endl;

	return 0;
}