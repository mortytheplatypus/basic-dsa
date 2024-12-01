#include <iostream>
#include <vector>
#include <stack>
#include "graph.h"
using namespace std;

Graph get_transpose(Graph graph) {
	int vertices = graph.get_vertices();

	Graph graph_T(vertices, 0);

	for (int v = 0; v < vertices; v++) {
		vector<int> neighbours = graph.get_neighbours_of(v);

		for (int u : neighbours) {
			graph_T.add_edge(u, v);
		}
	}

	return graph_T;
}

void dfs_fill(Graph graph, int vertex, vector<bool>& visited, stack<int>& order) {
	visited[vertex] = true;

	vector<int> neighbours = graph.get_neighbours_of(vertex);

	for (int v : neighbours) {
		if (!visited[v]) {
			dfs_fill(graph, v, visited, order);
		}
	}

	order.push(vertex);
}

void dfs_util(Graph graph, int vertex, vector<bool>& visited, vector<int>& scc) {
	visited[vertex] = true;

	scc.push_back(vertex);

	vector<int> neighbours = graph.get_neighbours_of(vertex);

	for (int v : neighbours) {
		if (!visited[v]) {
			dfs_util(graph, v, visited, scc);
		}
	}
}

vector<vector<int>> find_sccs(Graph graph) {
	
	int vertices = graph.get_vertices();

	stack<int> order;
	vector<bool> visited(vertices, false);
	vector<vector<int>> sccs;

	// Step 1: Find the filling order
	for (int i = 0; i < vertices; i++) {
		if (!visited[i]) {
			dfs_fill(graph, i, visited, order);
		}
	}

	// Step 2: Transpose graph
	Graph graph_T = get_transpose(graph);

	for (int i = 0; i < vertices; i++) {
		visited[i] = false;
	}

	// Step 3: Find SCCs using the order in the transpose graph
	while (!order.empty()) {
		int vertex = order.top();
		order.pop();

		if (!visited[vertex]) {
			vector<int> scc;
			dfs_util(graph_T, vertex, visited, scc);
			sccs.push_back(scc);
		}
	}
	
	return sccs;
}

void print_sccs(Graph graph) {
	vector<vector<int>> sccs = find_sccs(graph);

	int count = 1;
	for (vector<int> scc : sccs) {
		cout << "SCC-" << count++ << ": ";

		for (int v : scc) {
			cout << v << " ";
		}

		cout << "\n";
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int vertices, edges;
	cin >> vertices >> edges;

	Graph graph(vertices, edges);

	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;
		graph.add_edge(u, v);
	}

	print_sccs(graph);

	return 0;
}