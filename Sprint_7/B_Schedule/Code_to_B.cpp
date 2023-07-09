#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<double, double>> optSchedule(vector<pair<double, double>>& schedule) {
	vector<pair<double, double>> result;
	double cur_time = 0;

	for (auto it = schedule.begin(); it != schedule.end(); it++) {
		//cout << it->first << " f " << it->second << endl;
		if ((it->second >= cur_time) & (it->first >= cur_time)) {
			//cout << "cur_time " << cur_time << endl;
			cur_time = it->first;
			result.push_back({ it->second, it->first });
		}
	}

	return result;
}

int main() {
	int n;
	double start, end;
	cin >> n;
	vector<pair<double, double>> schedule;
	vector<pair<double, double>> result;

	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		schedule.push_back({ end,start });
	}

	sort(schedule.begin(), schedule.end());

	result = optSchedule(schedule);

	cout << result.size() << endl;
	for (auto it = result.begin(); it != result.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	return 0;
}