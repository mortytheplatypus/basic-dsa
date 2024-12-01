#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000007;

struct Node {
    int vertex, weight;

    Node(int v, int w) {
        this->vertex = v;
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
    }

    void dijkstra(int);
};

bool operator<(Node u, Node v) {
    return u.weight > v.weight;
}

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

	graph.dijkstra(source);

	return 0;
}

void Graph::dijkstra(int source) {
    vector<int> costs(vertices, INF);
    vector<bool> visited(vertices, false);

    priority_queue<Node> pq;

    costs[source] = 0;
    pq.push(Node(source, 0));

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        vector<Node> neighbours = adjacency_list[u];
        for (Node node : neighbours) {
            int v = node.vertex;
            int w = node.weight;

            // relaxation
            if (costs[u] + w < costs[v]) {
                costs[v] = costs[u] + w;
                pq.push(node);
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        cout << source << " --> " << i << ": " << costs[i] << "\n";
    }
}