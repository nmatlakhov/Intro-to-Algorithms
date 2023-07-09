#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int matrix[1000][1000] = { 0 };



int main(){
    int n, m = 0;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int x, y = 0;
    cin >> x >> y;
    int up = x -1, down = x + 1, left = y - 1, right =  y + 1;

    vector<int> result;

    if ((up >= 0) && (up < n)) {
        result.push_back(matrix[up][y]);
    }


    if ((down >= 0) && (down < n)) {
        result.push_back(matrix[down][y]);
    }


    if ((left >= 0) && (left < m)) {
        result.push_back(matrix[x][left]);
    }


    if ((right >= 0) && (right < m)) {
        result.push_back(matrix[x][right]);
    }

    sort(result.begin(), result.end());

    for (auto it = result.begin(); it != result.end(); ++it)
        cout <<  *it  << " ";

    cout << "\n";

}