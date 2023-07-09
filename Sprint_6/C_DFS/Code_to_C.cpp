#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<stack>
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
	};

	void addEdge(int start, int end) {
		graph[start].insert(end);
		graph[end].insert(start);
	}

	void DFS(int start_node) {
		stack<int> Stack;
		Stack.push(start_node);

		while (!Stack.empty()) {
			int v = Stack.top();
			Stack.pop();

			if (graph_colour[v - 1] == Colour::white) {
				graph_colour[v - 1] = Colour::grey;
				Stack.push(v);
				verticesDFS.push_back(v);

				for (auto it = graph[v].rbegin(); it != graph[v].rend(); it++) {
					int w = *it;
					if (graph_colour[w - 1] == Colour::white) { Stack.push(w); }
				}
			
			}
			else if (graph_colour[v - 1] == Colour::grey) {
				graph_colour[v - 1] = Colour::black;
				
			}
		}
	}

	void printDFS() {
		for (size_t i = 0; i < verticesDFS.size(); i++) {
			cout << verticesDFS[i] << " ";
		}
	}

private:
	unordered_map<int, set<int>> graph;
	vector<Colour> graph_colour;
	vector<int> verticesDFS;
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

	int startedVertex;
	cin >> startedVertex;

	graph.DFS(startedVertex);
	graph.printDFS();


	return 0;
}