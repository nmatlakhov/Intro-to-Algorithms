#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

enum class Colour {
	white,
	grey,
	black
};

class Graph {
public:
	Graph(int V) {
		graph_colour.resize(V, Colour::white);
		previous.resize(V, 0);
		distance.resize(V, -1);
	};

	void addEdge(int start, int end) {
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	void BFS(int start_node) {
		queue<int> planned;
		planned.push(start_node);
		distance[start_node - 1] = 0;
		graph_colour[start_node - 1] = Colour::grey;

		while (!planned.empty()) {
			int u = planned.front();
			planned.pop();

			for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
				int v = *it;

				if (graph_colour[v - 1] == Colour::white) {
					distance[v - 1] = distance[u - 1] + 1;
					previous[v - 1] = u;
					graph_colour[v - 1] = Colour::grey;
					planned.push(v);
				}
			}

			graph_colour[u - 1] = Colour::black;
		}
	}


	void printShortestPathLength(int endVertex) {
		int path_length = distance[endVertex -1];

		cout << path_length << endl;
	}

private:
	unordered_map<int, list<int>> graph;
	vector<Colour> graph_colour;
	vector<int> previous;
	vector<int> distance;

};

int main() {
	int V, E;
	cin >> V >> E;
	Graph graph(V);

	int startVert, endVert;
	for (int i = 0; i < E; i++) {
		cin >> startVert >> endVert;
		graph.addEdge(startVert, endVert);
	}

	int startVertex, endVertex;
	cin >> startVertex >> endVertex;

	graph.BFS(startVertex);
	graph.printShortestPathLength(endVertex);


	return 0;
}