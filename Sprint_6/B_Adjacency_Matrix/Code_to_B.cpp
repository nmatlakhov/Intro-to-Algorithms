#include<iostream>
#include<vector>
#include<list>
using namespace std;

class AdjacencyMatrix {
public:
	AdjacencyMatrix(int V) : matrix(V, vector<int>(V)) {};

	void addEdge(int start, int end) {
		matrix[start - 1][end - 1] = 1;
	}

	void printMatrix() {
		for (size_t i = 0; i < matrix.size(); i++) {
			for (size_t j = 0; j < matrix[i].size(); j++) {
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}

private:
	vector<vector<int>> matrix;
};

int main() {
	int V, E;
	cin >> V >> E;
	AdjacencyMatrix adjMatrix(V);

	int startVert, endVert;
	for (int i = 0; i < E; i++) {
		cin >> startVert >> endVert;
		adjMatrix.addEdge(startVert, endVert);
	}

	adjMatrix.printMatrix();

	return 0;
}