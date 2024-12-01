#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

void bfs(Graph, int);

int main() {
    char filename[] = "input.txt";
    
    Graph graph = create_new_graph(filename);
    graph.print_graph();

    int vertices = graph.get_vertices();

    for (int vertex = 0; vertex < vertices; vertex++) {
        vector<bool> visited(vertices, false);
        cout << "bfs(" << vertex << "): ";
        bfs(graph, vertex);

        cout << "\n\n";
    }

    return 0;
}

void bfs(Graph graph, int vertex) {
    queue<int> q;
    q.push(vertex);

    vector<bool> visited(graph.get_vertices(), false);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = true;
        
            vector<int> neighbours = graph.get_neighbours_of(current);

            for (int neighbour : neighbours) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                }
            }
        }
    }
}


