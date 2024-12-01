#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;

struct Edge {
    int source, destination, weight;

    Edge(int s, int d, int w) {
        this->source = s;
        this->destination = d;
        this->weight = w;
    }

    bool operator<(Edge const& edge) {
        return this->weight < edge.weight;
    }
};

class Graph {
    int vertices;
    vector<Edge> edge_list;
public:
    Graph(int vertices) {
        this->vertices = vertices;
    }

    void add_edge(int u, int v, int w) {
        edge_list.push_back(Edge(u, v, w));
    }

    void bellman_ford(int);
};


int main() {
	freopen("sssp.txt", "r", stdin);

	int vertices, edges;
	cin >> vertices >> edges;

	Graph graph(vertices);

	for (int i = 0; i < edges; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph.add_edge(u, v, w);
	}

    int source = 0;

	graph.bellman_ford(source);

	return 0;
}

void Graph::bellman_ford(int source) {
    vector<int> costs(vertices, INF);
    vector<bool> visited(vertices, false);

    costs[source] = 0;
    int edges = edge_list.size();

    for (int i = 0; i < edges; i++) {
        if (edge_list[i].source == source) {
            swap(edge_list[0], edge_list[i]);
            break;
        }
    }

    for (int j = 1; j < vertices; j++) {
        for (Edge edge : edge_list) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            if (costs[u] + w < costs[v]) {
                costs[v] = costs[u] + w;
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        cout << source << " --> " << i << ": " << costs[i] << "\n";
    }
}