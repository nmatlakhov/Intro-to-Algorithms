#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> transposeMatrix(m, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			transposeMatrix[j][i] = matrix[i][j];
		}
	}
	return transposeMatrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void printTransposeMatrix(const vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	int n, m = 0;
	cin >> n >> m;
	if ((n > 0) & (m > 0)) {
		vector<vector<int>> matrix(n, vector<int>(m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> matrix[i][j];
			}
		}

		printMatrix(transposeMatrix(matrix));
		//printTransposeMatrix(matrix);
	}
	return 0;
}