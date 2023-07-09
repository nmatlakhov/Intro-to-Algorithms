#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;


class Graph {
public:
	Graph(int V) {
		num_vertices = V;
	};

	void addEdge(int start, int end) {
		if (start != end) {
			if (start > end) {
				graph[start].insert(end);
			}
			else {
				graph[end].insert(start);
			}
			
		}
	}
	
	bool isComplete() {
		int number_of_edges = num_vertices * (num_vertices - 1) / 2;
		int count = 0;

		for (auto it = graph.begin(); it != graph.end(); it++) {
			count += it->second.size();
		}

		if (count != number_of_edges) { return false; }
		else { return true; }

	}

private:
	unordered_map<int, unordered_set<int>> graph;
	int num_vertices;

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

	if (graph.isComplete()) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}


	return 0;
}