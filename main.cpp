#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main(int argc, char **argv) {
    // reading the input file
    ifstream file(argv[1]);

    // check if file is valid
    if(!file) {
        cout << "unable to open the file" << endl;
        return 1;
    }

    // read first two ints (rows & cols)
    int rows, cols;
    file >> rows >> cols;

    vector<vector<int>> data(rows, vector<int>(cols));

    // empty buffer
    string line;
    getline(file, line);

    // read the rest of the graph
    for (int i = 0; i < rows; ++i) {
        getline(file, line);
        for (int j = 0; j < cols; ++j) {
            data[i][j] = line[j] - '0';
        }
    }

    // Creating the graph from read data
    Graph graph(data);
    cout << graph.getNumberOfIslands() << endl;
    return 0;
}
