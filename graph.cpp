#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int nodes;
    int edges;
    vector<vector<int>> adjacencyList;
    vector<vector<int>> adjacencyMatrix;

public:

    Graph() {
        nodes = 0;
        edges = 0;
    }

    Graph(int nodes, int edges) {
        this->nodes = nodes;
        this->edges = edges;

        adjacencyList.resize(nodes);

        adjacencyMatrix.resize(nodes);
        for (int i = 0; i < nodes; i++) {
            adjacencyMatrix[i].resize(nodes);
        }

        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void add_edge(int u, int v) {
        adjacencyList[u].push_back(v);

        adjacencyMatrix[u][v] = 1;
    }

    void remove_edge(int u, int v) {
        int n = adjacencyList[u].size();
        for (int i = 0; i < n; i++) {
            if (adjacencyList[u][i] == v) {
                adjacencyList[u].erase(adjacencyList[u].begin()+i);
            }
        }

        adjacencyMatrix[u][v] = 0;
    }
};

int main() {
    return 0;
}