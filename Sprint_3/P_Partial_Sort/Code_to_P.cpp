#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> count_val;

	int ar_sum, temp_val, curr_sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp_val;
		curr_sum += temp_val;
		ar_sum = (i * (i+1)) / 2;
		if (curr_sum == ar_sum) {
			count_val.push(ar_sum);
		}
	}
	cout << count_val.size() << endl;

	return 0;
}