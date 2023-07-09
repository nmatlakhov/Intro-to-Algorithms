//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include <iomanip>  
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> north(n), south(m);
//	for (int i = 0; i < n; i++) {
//		cin >> north[i];
//	}
//	for (int j = 0; j < m; j++) {
//		cin >> south[j];
//	}
//	int full_size = m + n;
//	vector<int> result(full_size);
//	merge(north.begin(), north.end(), south.begin(), south.end(), result.begin());
//
//
//	int mid = full_size / 2;
//	if (full_size % 2 == 0) {
//		if ((result[mid-1] + result[mid ]) % 2 == 0) {
//			int med = (result[mid-1] + result[mid]) / 2;
//			cout << med << endl;
//		}
//		else {
//			double med = (static_cast<double>(result[mid-1]) + static_cast<double>(result[mid])) / 2;
//			cout << fixed<< setprecision(1) << med << endl;
//		}
//		
//	}
//	else {
//		int med;
//		med = result[mid];
//		cout << med << endl;
//	}
//	
//
//	return 0;
//}