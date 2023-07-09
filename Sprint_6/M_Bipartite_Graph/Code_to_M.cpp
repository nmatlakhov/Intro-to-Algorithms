#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

enum class Colour {
	white,
	red,
	blue
};

class Graph {
public:
	Graph(int V) {
		graph_colour.resize(V, Colour::white);
	};

	void addEdge(int start, int end) {
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	bool isBipartiteFromNode(int start_node) {
		queue<int> planned;
		planned.push(start_node);

		graph_colour[start_node - 1] = Colour::red;

		while (!planned.empty()) {
			int u = planned.front();
			planned.pop();

			for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
				int v = *it;
				if (graph_colour[v - 1] == Colour::white) {
					if (graph_colour[u - 1] == Colour::red) {
						graph_colour[v - 1] = Colour::blue;
					}
					else {
						graph_colour[v - 1] = Colour::red;
					}
					
					planned.push(v);
				}
				else if (graph_colour[v - 1] == graph_colour[u - 1]) {
					return false;
				}
			}

		}
		return true;
	}

	bool isBipartite() {
		bool check;
		for (size_t i = 0; i < graph_colour.size(); i++) {
			if (graph_colour[i] == Colour::white) {
				check = isBipartiteFromNode(i + 1);
				if (!check) { return false; }
			}
		}
		return true;
	}
	

private:
	unordered_map<int, list<int>> graph;
	vector<Colour> graph_colour;
};

int main() {
	int V, E;
	cin >> V >> E;
	Graph graph(V);

	int start_vertex, end_vertex;
	for (int i = 0; i < E; i++) {
		cin >> start_vertex >> end_vertex;
		graph.addEdge(start_vertex, end_vertex);
	}

	bool check_bipartite = graph.isBipartite();
	
	if (check_bipartite) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}