#include <bits/stdc++.h>
using namespace std;

#define INPUT_FILE "input.txt"

class Graph {
    int vertices, edges;
    vector<vector<int>> adjacency_list;

public:
    Graph();
    Graph(int, int);
    int get_vertices();
    vector<int> get_neighbours_of(int);
    void addEdge(int, int);
    void printGraph();
};

Graph::Graph() {
    // do nothing
}

Graph::Graph(int vertices, int edges) {
    this->vertices = vertices;
    this->edges = edges;
    this->adjacency_list.resize(vertices);
}

int Graph::get_vertices() {
    return this->vertices;
}

vector<int> Graph::get_neighbours_of(int vertex) {
    return this->adjacency_list[vertex];
}

void Graph::addEdge(int source, int destination) {
    adjacency_list[source].push_back(destination);
}

void Graph::printGraph() {
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";

        for (int j : adjacency_list[i]) {
            cout << j << " -> ";
        }

        cout << "NULL\n";
    }
    cout << "\n";
}

Graph create_new_graph(char* filename) {
    FILE* input = freopen(filename, "r", stdin);

    int vertices, edges, source, destination;
    cin >> vertices >> edges;

    Graph graph(vertices, edges);

    for (int i = 0; i < edges; i++) {
        cin >> source >> destination;
        graph.addEdge(source, destination);
    }

    fclose(input);

    return graph;
}


