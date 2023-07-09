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
		entryTime.resize(V, 0);
		leaveTime.resize(V, 0);
		time = 0;
	};

	void addEdge(int start, int end) {
		graph[start].insert(end);
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
				
				entryTime[v - 1] = time;
				time += 1;

				for (auto it = graph[v].rbegin(); it != graph[v].rend(); it++) {
					int w = *it;
					if (graph_colour[w - 1] == Colour::white) { Stack.push(w); }
				}

			}
			else if (graph_colour[v - 1] == Colour::grey) {
				graph_colour[v - 1] = Colour::black;
				
				leaveTime[v - 1] = time;
				time += 1;
			}
		}
	}

	void printDFS() {
		for (size_t i = 0; i < verticesDFS.size(); i++) {
			cout << verticesDFS[i] << " ";
		}
	}

	void printDFSTime() {
		size_t V = entryTime.size();
		for (size_t i = 0; i < V; i++) {
			cout << entryTime[i] << " " << leaveTime[i] << '\n';
		}
	}

private:
	unordered_map<int, set<int>> graph;
	vector<Colour> graph_colour;
	vector<int> verticesDFS;
	vector<int> entryTime;
	vector<int> leaveTime;
	int time;
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


	graph.DFS(1);
	graph.printDFSTime();


	return 0;
}