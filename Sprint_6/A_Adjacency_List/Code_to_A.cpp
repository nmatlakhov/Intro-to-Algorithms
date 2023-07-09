#include<iostream>
#include<vector>
#include<list>
using namespace std;

//struct AdjacentMatrix {
//	vector<vector<int>> matrix;
//	AdjacentMatrix(int V) : matrix(V, vector<int>(V)) {};
//};

//struct Edge {
//	int from, to, weight;
//	Edge(int from_, int to_, int weight_) : from(from_), to(to_), weight(weight_) {};
//	Edge() : from(0), to(0), weight(0) {};
//};

class AdjacencyList {
public:
	AdjacencyList(int V) { adjacencyList.resize(V + 1); }

	void addEdge(int start, int end) {
		adjacencyList[start].push_back(end);
	}

	void printGraph() {
		for (int i = 1; i < adjacencyList.size(); i++) {
			size_t edges = adjacencyList[i].size();
			
			cout << edges << " ";
			if (edges != 0){ 
				for (auto it = adjacencyList[i].begin(); it != adjacencyList[i].end(); it++) {
					cout << *it << " ";
				}
			}
			cout << endl;
		}
	}

private:
	vector<list<int>> adjacencyList;
};

int main() {
	int V, E;
	cin >> V >> E;
	AdjacencyList adjList(V);
	
	int startVert, endVert;
	for (int i = 0; i < E; i++) {
		cin >> startVert >> endVert;
		adjList.addEdge(startVert, endVert);
	}
	
	adjList.printGraph();

	return 0;
}