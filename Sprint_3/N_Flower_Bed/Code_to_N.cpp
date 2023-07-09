#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

int main() {
	int n, left_v, right_v;
	cin >> n;
	vector<vector<int>> left_bound(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		cin >> left_v >> right_v;
		left_bound[i][0] = left_v;
		left_bound[i][1] = right_v;
	}

	sort(left_bound.begin(), left_bound.end(),[](const vector<int>& s, const vector<int>& p) { return s[0] < p[0]; } );
	deque<vector<int>> result;


	for (int i = 0; i < n; i++) {
		if (i == 0) {
			result.push_front(left_bound[0]);
		}
		else {
			if (result.front()[1] >= left_bound[i][0]) {
				if (result.front()[1] < left_bound[i][1]) {
					result.front()[1] = left_bound[i][1];
				}
			}
			else {
				result.push_front(left_bound[i]);
			}
		}

	}

	while (!result.empty()) {
		cout << result.back()[0] << " " << result.back()[1] << endl;
		result.pop_back();
	}


	return 0;
}