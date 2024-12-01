#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

void dfs(Graph, int);

int main() {
    char filename[] = "input.txt";
    Graph graph = create_new_graph(filename);
    graph.print_graph();

    int vertices = graph.get_vertices();

    for (int vertex = 0; vertex < vertices; vertex++) {
        
        cout << "dfs(" << vertex << "): ";
        dfs(graph, vertex);

        cout << "\n\n";
    }

    return 0;
}

void dfs(Graph graph, int vertex) {
    stack<int> s;
    s.push(vertex);

    vector<bool> visited(graph.get_vertices(), false);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = true;
        
            vector<int> neighbours = graph.get_neighbours_of(current);

            for (int neighbour : neighbours) {
                if (!visited[neighbour]) {
                    s.push(neighbour);
                }
            }
        }
    }
}

