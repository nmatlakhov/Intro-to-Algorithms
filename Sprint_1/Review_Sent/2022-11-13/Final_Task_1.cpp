/* ID 74628790 */
#include<iostream>
#include<vector>
using namespace std;

void minDistance(vector<int>& dist) {
	int counter = 0, zero_counter = 0, zero_nums;

	//���������� ������ �� ������� �����.
	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] > 0) {			 
			counter++;
		}
		else { 
			counter = 0; 
			zero_counter++; //�������� ���������� ������ ���� �����.
		}

		if (zero_counter > 0) { //���� �� ����� �� ������� ������� ����� �����, ���������� �� ������.
			dist[i] = counter; 
		}
		
	}

	// ��������� ����� ����� ����� � ���������� ������ �� ������� ������.
	zero_nums = zero_counter;
	for (int j = dist.size() - 1; j >= 0; j--) {

		if ((dist[j] > 0)||(zero_counter == 0)) { //������� ����������, ���� ����� �� ������, ���� ��� ������ ����� �� ��� ������.
			counter++; 
		} else { 
			counter = 0;  
			zero_counter--; //�������� ���������� ������ ���� �����.
		}

		if(zero_counter != zero_nums) { //���� �� ����� �� ������� ������� ����� ������ (���������� �����), ���������� �� ������.
			if (zero_counter > 0) { // ���� �� ����� �� ���������� ������� ����� ������, �� ���������� ������ ���������� ������.
				if(dist[j] > counter) dist[j] = counter; // ���� ���������� ������ ������, �� ������ ����� ����������. ���� ���������� ������ �����, �� ������ �� ������.
			}
			else {
				dist[j] = counter; // ��� ������ ������ ��������� ������ ����� ������, �� ������ ���������� ����������.
			}
		}


	}
}

void print(const vector<int>& result) {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}

int main() {
	int n = 0, temp_num, cnt = 0, zero_num = 0;
	cin >> n;

	vector<int> dist(n);

	for (int i = 0; i < n; i++) {
		cin >> temp_num;
		dist[i] = temp_num;
	}

	minDistance(dist);
	print(dist);
	return 0;
}