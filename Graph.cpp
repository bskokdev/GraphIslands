#include "Graph.h"

Graph::Graph(vector<vector<int>> &data) {
    this->data = data;
}

bool Graph::inBounds(int row, int col, int H, int W) {
    return row >= 0 && row < H && col >= 0 && col < W;
}

int Graph::getNumberOfIslands() {
    if(this->data.empty() || this->data[0].empty())
        return 0;

    int H = this->data.size();
    int W = this->data[0].size();
    int count = 0;

    vector<vector<bool>> visited(H, vector<bool>(W));
    vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for(int row = 0; row < H; row++) {
        for(int col = 0; col < W; col++) {
            if(!visited[row][col] && this->data[row][col] == 1) {
                count++;
                queue<pair<int, int>> q;
                q.push({row, col});
                visited[row][col] = true;
                while(!q.empty()) {
                    auto &curr = q.front();
                    q.pop();
                    for(auto &dir : directions) {
                        int nextRow = curr.first + dir.first;
                        int nextCol = curr.second + dir.second;
                        if(inBounds(nextRow, nextCol, H, W) && !visited[nextRow][nextCol] && this->data[nextRow][nextCol] == 1) {
                            q.push({nextRow, nextCol});
                            visited[nextRow][nextCol] = true;
                        }
                    }
                }
            }
        }
    }
    return count;
}

