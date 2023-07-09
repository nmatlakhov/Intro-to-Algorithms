#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

bool isWithinDistance(int dx, int dy) {
	if (dx + dy <= 20) {
		return true;
	}
	else if (dx * dx + dy * dy <= 400) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	int n, m, temp_ind;
	cin >> n;
	int x, y;

	vector<pair<int, int>> metro_stations;
	vector<int> counter(n);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		metro_stations.push_back({ x,y });
		counter[i] = 0;
	}


	cin >> m;
	int x_bucket, y_bucket, step_size = 20, max_coord = 1'000'000'000;
	int min_bucket_num = 0, max_bucket_num = (2 * max_coord) / step_size;
	unordered_map<int, unordered_map<int, vector<pair<int, int>> >> bus_stops;
	bus_stops.rehash(100);

	for (int j = 0; j < m; j++) {
		cin >> x >> y;
		x_bucket = (x + max_coord) / step_size;
		y_bucket = (y + max_coord) / step_size;
		auto it = bus_stops.find(x_bucket);
		if (it == bus_stops.end()) {

			bus_stops[x_bucket].rehash(100);
		}

		bus_stops[x_bucket][y_bucket].push_back({ x,y });
	}

	for (int i = 0; i < n; i++) {
		x = metro_stations[i].first, y = metro_stations[i].second;
		x_bucket = (x + max_coord) / step_size;
		y_bucket = (y + max_coord) / step_size;

		for (int p = x_bucket - 1; p <= x_bucket + 1; p++) {
			auto itx = bus_stops.find(p);
			if (itx == bus_stops.end()) { continue; }

			for (int s = y_bucket - 1; s <= y_bucket + 1; s++) {
				auto ity = itx->second.find(s);
				if (ity == itx->second.end()) { continue; }

				for (auto it = ity->second.begin(); it != ity->second.end(); it++) {
					if (isWithinDistance(abs(x - it->first), abs(y - it->second))) {
						counter[i]++;
					}
				}
			}
		}
	}

	int max_ind = 1, max_value = 0;
	for (int i = 0; i < n; i++) {
		if (counter[i] > max_value) {
			max_ind = i + 1;
			max_value = counter[i];
		}
	}

	cout << max_ind << endl;


	return 0;
}