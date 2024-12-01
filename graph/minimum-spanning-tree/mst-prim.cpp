#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000007;

struct Node {
    int destination, weight;

    Node(int d, int w) {
        this->destination = d;
        this->weight = w;
    }
};

struct Edge {
    int source, destination, weight;

    Edge(int s, int d, int w) {
        this->source = s;
        this->destination = d;
        this->weight = w;
    }
};

class Graph {
    int vertices;
    vector<vector<Node>> adjacency_list;

public:
    Graph(int vertices) {
        this->vertices = vertices;
        this->adjacency_list.resize(vertices);
    }

    void add_edge(int u, int v, int weight) {
        this->adjacency_list[u].push_back(Node(v, weight));
        this->adjacency_list[v].push_back(Node(u, weight));
    }

    void find_mst_prim();

    void print_mst(vector<int> edge_costs, vector<int> neighbours) {
        int costs = 0;

        cout << "Edges in MST by Prim's algorithm: ";

        for (int i = 1; i < vertices; i++) {
            costs += edge_costs[i];
            cout << "(" << i << ", " << neighbours[i] << ") ";
        }
        cout << "\nTotal cost: " << costs << "\n";
    }
};

int main() {
	freopen("mst.txt", "r", stdin);

	int vertices, edges;
	cin >> vertices >> edges;

	Graph graph(vertices);

	for (int i = 0; i < edges; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph.add_edge(u, v, w);
	}

	graph.find_mst_prim();

	return 0;
}

// O(Elg(V))
void Graph::find_mst_prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> edge_costs(vertices, INF); // O(V)
    vector<int> neighbours(vertices, -1); // O(V)
    vector<bool> visited(vertices, false); // if visited := O(V)

    edge_costs[0] = 0; // O(1)
    pq.push({0, 0}); // (weight, destination) := O(1)

    while (!pq.empty()) {
        int vertex = pq.top().second;
        pq.pop(); // O(lg(V) for heapify

        if (visited[vertex]) {
            continue;
        }
        visited[vertex] = true;

        // O(Elg(V))
        for (Node neighbour : adjacency_list[vertex]) {
            int v = neighbour.destination;
            int w = neighbour.weight;

            if (visited[v]) {
                continue;
            }

            // O(lgV)
            if (w < edge_costs[v]) {
                edge_costs[v] = w;
                neighbours[v] = vertex;
                pq.push({w, v}); // O(lgV) for heapify
            }
        }
    }

    print_mst(edge_costs, neighbours);
}