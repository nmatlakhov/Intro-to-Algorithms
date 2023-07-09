#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using point = pair<int, int>;


class Maze {
public:

	Maze(int n, int m){
		N = n;
		M = m;
		field.resize(n, vector<bool>(m, 0));
		prev.resize(n, vector<point>(m, {-1, -1}));
		Inf_v = n * m + 10;

		movements = { {0,1}, {0,-1}, {1,0}, {-1,0} };
		dist.resize(n, vector<int>(m, Inf_v));
	}

	void readField() {
		char r;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> r;
				if (r == '1') {
					field[i][j] = true;
				}
				else if (r == '*') {
					start_point.first = i, start_point.second = j;
				}
			}
		}
	}
	
	bool is_free(point p) {
		int x = p.first, y = p.second;
		bool result = (x >= 0) & (y >= 0) & (x < N) & (y < M) & (field[x][y] == false);
		return result;
	}

	bool is_exit(point p) {
		int x = p.first, y = p.second;
		bool free = is_free(p);
		bool result = free & ((x == N - 1) | (x == 0) | (y == N - 1) | (y == 0));
		return result;
	}

	point add(point p1, point p2) {
		return { p1.first + p2.first, p1.second + p2.second };
	}

	pair<int, point> escape_from_maze() {
		queue<point> q;

		q.push(start_point);
		while (q.size() > 0) {
			point current_point = q.front();
			q.pop();
			for (size_t i = 0; i < movements.size(); i++) {
				point new_point = add(current_point, movements[i]);

				if (is_free(new_point) & (dist[new_point.first][new_point.second] == Inf_v)) {
					q.push(new_point);
					prev[new_point.first][new_point.second] = current_point;
					dist[new_point.first][new_point.second] = dist[current_point.first][current_point.second] + 1;
					if (is_exit(new_point)) {
						return { dist[new_point.first][new_point.second] , new_point };
					}
				}
			}
		}

		return { Inf_v, {-1,-1} };
	}

	vector<point> find_escape() {
		pair<int, point> escape_final = escape_from_maze();
		vector<point> result;
		point current_point = escape_final.second;

		while (current_point != start_point) {
			result.push_back(current_point);
			current_point = prev[current_point.first][current_point.second];
		}

		result.push_back(current_point);

		return result;
	}

private:
	int N, M, Inf_v;
	pair<int, int> start_point;
	vector<vector<bool>> field;
	vector<point> movements;
	vector<vector<point>> prev;
	vector<vector<int>> dist;
};


int main() {
	int n, m, x_start, y_start;
	cin >> n >> m;

	Maze maze(n, m);
	maze.readField();

	vector<point> result = maze.find_escape();

	for (auto it = result.rbegin(); it != result.rend(); it++) {
		cout << it->first + 1 << " " << it->second + 1 << endl;
	}


	return 0;
}