#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;


class Graph {
public:
	Graph(int V) {
		visited.resize(V, false);
		previous.resize(V, 0);
		distance.resize(V, numeric_limits<int>::max());
		vertices_num = V;

		matrix_distances.resize(V, vector<int>(V));
	};

	void addWeightedEdge(int start, int end, int weight) {
		if (start != end) {
			if (graph[start][end] == 0) {
				graph[start][end] = weight;
				graph[end][start] = weight;
			}
			else if (graph[start][end] > weight) {
				graph[start][end] = weight;
				graph[end][start] = weight;
			}
		}
	}

	void relax(int u, int v) {
		if (distance[v - 1] > distance[u - 1] + graph[u][v]) {
			distance[v - 1] = distance[u - 1] + graph[u][v];
			previous[v - 1] = u;
		}
	}

	int getMinimumDistanceNotVisited() {
		int current_minimum = numeric_limits<int>::max();
		int current_min_vertex = 0;

		for (int v = 1; v <= vertices_num; v++) {
			if ((!visited[v-1]) & (distance[v - 1] < current_minimum)) {
				current_minimum = distance[v - 1];
				current_min_vertex = v;
			}
		}
		return current_min_vertex;
	}

	void Dijkstra(int start) {
		for (int v = 1; v <= vertices_num; v++) {
			distance[v - 1] = numeric_limits<int>::max();
			previous[v - 1] = 0;
			visited[v - 1] = false;
		}

		distance[start - 1] = 0;
		int u = getMinimumDistanceNotVisited();

		while (u != 0) {

			visited[u - 1] = true;

			for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
				relax(u, it->first);
			}

			u = getMinimumDistanceNotVisited();
		}
	}

	void CalcDistances() {
		for (int i = 1; i <= vertices_num; i++) {
			Dijkstra(i);
			for (int j = i + 1; j <= vertices_num; j++) {
				if (distance[j - 1] < numeric_limits<int>::max()) {
					matrix_distances[i - 1][j - 1] = distance[j - 1];
					matrix_distances[j - 1][i - 1] = distance[j - 1];
				}
				else {
					matrix_distances[i - 1][j - 1] = -1;
					matrix_distances[j - 1][i - 1] = -1;
				}
			}
		}
	}

	void PrintMatrix() {
		for (int i = 0; i < vertices_num; i++) {
			for (int j = 0; j < vertices_num; j++) {
				cout << matrix_distances[i][j] << " ";
			}
			cout << "\n";
		}
	}

private:
	unordered_map<int, unordered_map<int,int>> graph;
	int vertices_num;

	vector<bool> visited;
	vector<int> previous;
	vector<int> distance;
	vector<vector<int>> matrix_distances;
};

int main() {
	int V, E;
	cin >> V >> E;
	Graph graph(V);

	int start_vert, end_vert, weight;
	for (int i = 0; i < E; i++) {
		cin >> start_vert >> end_vert >> weight;
		graph.addWeightedEdge(start_vert, end_vert, weight);
	}

	graph.CalcDistances();
	graph.PrintMatrix();
	

	return 0;
}