//#include<algorithm>
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//int main() {
//	int n, result;
//	long int k;
//	cin >> n;
//	vector<int> islands_sq(n);
//	for (int i = 0; i < n; i++) {
//		cin >> islands_sq[i];
//	}
//	cin >> k;
//
//	sort(islands_sq.begin(), islands_sq.end());
//	
//	int left_v = 0, right_v = islands_sq[n - 1] - islands_sq[0];
//	long int cnt = 0;
//
//	while (left_v < right_v) {
//		int mid = (left_v + right_v) / 2;
//		int j = 0;
//		for (int i = 0; i < n; i++) {
//			while ((j < n) && (islands_sq[j] <= islands_sq[i] + mid)) { j++; }
//			cnt += j - i - 1;
//		}
//
//		if (cnt < k) {
//			left_v = mid + 1;
//		}
//		else {
//			right_v = mid;
//		}
//	}
//
//	cout << left_v << endl;
//	return 0;
//}