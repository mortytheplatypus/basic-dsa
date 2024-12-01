#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

    void find_mst_kruskal();

    void print_mst(vector<Edge> mst) {
        int costs = 0;

        cout << "Edges in MST by Kruskal's algorithm: ";

        for (Edge edge : mst) {
            costs += edge.weight;

            cout << "(" << edge.source << ", " << edge.destination << ") ";
        }
        cout << "\nTotal cost: " << costs << "\n";
    }
};

int get_parent(int v, vector<int>& parents) {
    if (v == parents[v]) {
        return v;
    } 

    parents[v] = get_parent(parents[v], parents);

    return parents[v];
}

void Union(int u, int v, vector<int> &parents) {
    int parent_u = get_parent(u, parents);
    int parent_v = get_parent(v, parents);

    parents[parent_v] = parent_u;
}

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

	graph.find_mst_kruskal();

	return 0;
}

void Graph::find_mst_kruskal() {
    vector<int> parents(vertices);
    vector<Edge> mst;

    for (int i = 0; i < vertices; i++) {
        parents[i] = i;
    }

    sort(edge_list.begin(), edge_list.end());

    int edges = edge_list.size();

    for (int i = 0; i < edges; i++) {
        int u = edge_list[i].source;
        int v = edge_list[i].destination;

        if (get_parent(u, parents) == get_parent(v, parents)) {
            continue;
        }

        mst.push_back(edge_list[i]);
        Union(u, v, parents);
    }

    print_mst(mst);
}