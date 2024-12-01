#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const char* INPUT_FILE = "input.txt";

class Graph {
    int vertices;
    vector<vector<int>> adjacency_list;

public:

    Graph(int);
    void add_edge(int, int);
    void print_graph();

    void dfs(int);
};

int main() {
    freopen(INPUT_FILE, "r", stdin);
    
    int vertices, edges;
    cin >> vertices >> edges;

    Graph graph(vertices);

    for (int i = 0; i < edges; i++) {
        int u, v; 
        cin >> u >> v;

        graph.add_edge(u, v);
    }

    graph.print_graph();

    int vertex;
    cin >> vertex;

    graph.dfs(vertex);

    return 0;
}

Graph::Graph(int vertices) {
    this->vertices = vertices;
    this->adjacency_list.resize(vertices);
}

void Graph::add_edge(int u, int v) {
    adjacency_list[u].push_back(v);
}

void Graph::print_graph() {
    for (int i = 0; i < vertices; i++) {
        cout << "(" << i << ") -> ";

        for (int j : adjacency_list[i]) {
            cout << j << " -> ";
        }

        cout << "_\n";
    }
    cout << "\n";
}

void Graph::dfs(int vertex) {

    cout << "dfs(" << vertex << "): ";

    stack<int> s;
    s.push(vertex);

    vector<bool> visited(vertices, false);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = true;
        
            vector<int> neighbours = adjacency_list[current];

            for (int neighbour : neighbours) {
                if (!visited[neighbour]) {
                    s.push(neighbour);
                }
            }
        }
    }
}

