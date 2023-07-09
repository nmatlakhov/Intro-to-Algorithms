#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<stack>
using namespace std;


class Graph {
public:
	Graph(int V) {
		n_vertices = V;
		colour.resize(V, -1);
		component_count = 1;
	};

	void addEdge(int start, int end) {
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	void DFS(int start_node) {
		stack<int> Stack;
		Stack.push(start_node);

		while (!Stack.empty()) {
			int v = Stack.top();
			Stack.pop();

			if (colour[v - 1] == -1) {
				colour[v - 1] = component_count;
				Stack.push(v);

				for (auto it = graph[v].rbegin(); it != graph[v].rend(); it++) {
					int w = *it;
					if (colour[w - 1] == -1) { Stack.push(w); }
				}

			}

		}
	}

	void MainDFSComponent() {
		for (int i = 0; i < n_vertices; i++) {
			if (colour[i] == -1) {
				DFS(i + 1);
				component_count++;
			}
		}
	}

	void PrintColours() {
		cout << component_count - 1 << endl;
		for (int i = 1; i < component_count; i++) {
			for (int j = 0; j < n_vertices; j++) {
				if (colour[j] == i) {
					cout << j + 1 << " ";
				}
			}
			cout << "\n";
		}
	}


private:
	unordered_map<int, list<int>> graph;

	int component_count, n_vertices;
	vector<int> colour;
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

	graph.MainDFSComponent();
	graph.PrintColours();


	return 0;
}