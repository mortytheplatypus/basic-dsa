#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjacency_list;

    Graph get_transpose() {
        Graph graph_T(vertices);

        for (int v = 0; v < vertices; v++) {
            for (int u : adjacency_list[v]) {
                graph_T.add_edge(u, v);
            }
        }

        return graph_T;
    }

    // dfs to fill the stack in order of finishing time
    void dfs_order(int vertex, vector<bool>& visited, stack<int>& order) {
        visited[vertex] = true;

        for (int v : adjacency_list[vertex]) {
            if (!visited[v]) {
                dfs_order(v, visited, order);
            }
        }

        order.push(vertex);
    }

    // dfs to find vertices in a strongly connected component
    void dfs_scc(Graph& graph, int vertex, vector<bool>& visited, vector<int>& scc) {
        visited[vertex] = true;

        scc.push_back(vertex);

        vector<int> adjacent_vertices = graph.get_neighbours_of(vertex);
        for (int v : adjacent_vertices) {
            if (!visited[v]) {
                dfs_scc(graph, v, visited, scc);
            }
        }
    }

public:
    Graph(int vertices) {
        this->vertices = vertices;
        this->adjacency_list.resize(vertices);
    }

    void add_edge(int u, int v) {
        this->adjacency_list[u].push_back(v);
    }

    vector<int> get_neighbours_of(int vertex) {
        return adjacency_list[vertex];
    }

    void print_graph() {
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";

            for (int j : adjacency_list[i]) {
                cout << j << " -> ";
            }

            cout << "_\n";
        }
        cout << "\n";
    }

    vector<vector<int>> find_sccs() {
        stack<int> order;
        vector<bool> visited(vertices, false);
        vector<vector<int>> sccs;

        // Step 1: Find the filling order
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                dfs_order(i, visited, order);
            }
        }

        // Step 2: Transpose graph
        Graph graph_T = this->get_transpose();

        // Mark all vertices as not visited for second DFS
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }

        // Step 3: Find SCCs using the order in the transpose graph
        while (!order.empty()) {
            int vertex = order.top();
            order.pop();

            if (!visited[vertex]) {
                vector<int> scc;
                dfs_scc(graph_T, vertex, visited, scc);
                sccs.push_back(scc);
            }
        }

        return sccs;
    }

    void print_sccs() {
        vector<vector<int>> sccs = find_sccs();

        int count = 1;
        for (vector<int> scc : sccs) {
            cout << "SCC-" << count++ << ": ";

            for (int v : scc) {
                cout << v << " ";
            }

            cout << "\n";
        }
    }
};

int main() {
    freopen("scc.txt", "r", stdin);

    int vertices, edges;
    cin >> vertices >> edges;

    Graph graph(vertices);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v);
    }

    graph.print_graph();

    graph.print_sccs(); 

    return 0;
}