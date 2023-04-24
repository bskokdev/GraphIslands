#include <iostream>
#include "Graph.h"

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> data(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++) {
            data[i][j] = row[j] - '0';
        }
    }

    Graph graph(data);
    cout << graph.getNumberOfIslands() << endl;
    return 0;
}
