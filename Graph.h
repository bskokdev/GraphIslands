#ifndef GRAPHISLANDS_GRAPH_H
#define GRAPHISLANDS_GRAPH_H

#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    vector<vector<int>> data;
    bool inBounds(int row, int col, int H, int W);
public:
    Graph() = default;
    explicit Graph(vector<vector<int>> &data);
    int getNumberOfIslands();
};


#endif //GRAPHISLANDS_GRAPH_H
