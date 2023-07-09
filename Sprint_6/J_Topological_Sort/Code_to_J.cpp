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
	Graph(size_t V) {
		nVertices = V;
		graph_colour.resize(V, Colour::white);
	};

	void addEdge(int start, int end) {
		graph[start].insert(end);
	}

	void TopSort(int v) {
		graph_colour[v - 1] = Colour::grey;
		for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
			int w = *it;
			if (graph_colour[w - 1] == Colour::white) { TopSort(w); }
		}
		graph_colour[v - 1] = Colour::black;
		order.push(v);
	}

	void MainTopSort() {
		for (int i = nVertices - 1; i >= 0; i--) {
			if (graph_colour[i] == Colour::white) {
				TopSort(i + 1);
			}
		}
	}

	void PrintResult() {
		while (!order.empty()) {
			cout << order.top() << " ";
			order.pop();
		}
	}

private:
	size_t nVertices;
	unordered_map<int, set<int>> graph;
	vector<Colour> graph_colour;
	stack<int> order;
};

int main() {
	size_t V, E;
	cin >> V >> E;
	Graph graph(V);

	int startVert, endVert;
	for (size_t i = 0; i < E; i++) {
		cin >> startVert >> endVert;
		graph.addEdge(startVert, endVert);
	}

	graph.MainTopSort();
	graph.PrintResult();


	return 0;
}