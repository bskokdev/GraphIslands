#include "Graph.h"

Graph::Graph(vector<vector<int>> &data) {
    this->data = data;
}

bool Graph::inBounds(int row, int col, int H, int W) {
    // check if the row and col is within the valid grid range
    // this will ensure no overflows happen
    return row >= 0 && row < H && col >= 0 && col < W;
}

int Graph::getNumberOfIslands() {
    if(this->data.empty() || this->data[0].empty())
        return 0;

    // height and width of the grid
    int H = this->data.size();
    int W = this->data[0].size();

    // count of islands
    int count = 0;

    // If we mark node as visited it will be stored here
    vector<vector<bool>> visited(H, vector<bool>(W));

    // This allows us to move to 4 directions (right, top, left, bottom)
    // because we do BFS only with the coordinates (row, col)
    vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // For each value in the grid we run a BFS which will run until it explores all connected 1s
    for(int row = 0; row < H; row++) {
        for(int col = 0; col < W; col++) {
            // If the new node hasn't been seen yet and is 1 -> we found a new island
            if(!visited[row][col] && this->data[row][col] == 1) {
                count++;
                // Iterative BFS (we only use pair<row, col> (these are the coordinates of the current position in the grid)
                queue<pair<int, int>> q;
                // we first push current coordinates and mark them as seen to start the BFS
                q.push({row, col});
                visited[row][col] = true;
                while(!q.empty()) {
                    auto &curr = q.front();
                    q.pop();
                    for(auto &dir : directions) {
                        // we calculate new position which will be traversed
                        int nextRow = curr.first + dir.first;
                        int nextCol = curr.second + dir.second;
                        // and we have to check if it is a valid index as well as the position hasn't been seen yet and value is 1
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

