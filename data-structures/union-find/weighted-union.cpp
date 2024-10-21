#include <iostream>
#include <vector>
using namespace std;

// Weighted Union

int root(vector<int> parents, int node) {
    while (parents[node] != node) {
        parents[node] = parents[parents[node]]; // path compression
        node = parents[node];
    }
    return node;
}

bool Find(vector<int> parents, int u, int v) {
    if (root(parents, u) == root(parents, v)) {
        return true;
    } else {
        return false;
    }
}

void Union(vector<int> &parents, vector<int> &sizes, int u, int v) {
    int root_u = root(parents, u);
    int root_v = root(parents, v);

    // if both nodes are already in the same set
    if (root_u == root_v) {
        return;
    } 

    // make smaller tree a subtree of the larger tree
    if (sizes[root_u] < sizes[root_v]) {
        parents[root_u] = root_v;
        sizes[root_v] += sizes[root_u];
    } else {
        parents[root_v] = root_u;
        sizes[root_u] += sizes[root_v];
    }
}

int main() {
    freopen("input.txt", "r", stdin); // read input from `input.txt`

    int nodes, edges, u, v;
    cin >> nodes >> edges;

    vector<int> parents(nodes);
    vector<int> sizes(nodes, 1);
    for (int i = 0; i < nodes; i++) {
        parents[i] = i;
    }

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        Union(parents, sizes, u, v);
    }
    
    for (int i = 0; i < nodes; i++) {
        cout << parents[i] << " ";
    }
    cout << "\n";
    
    Union(parents, sizes, 2, 4);
    
    for (int i = 0; i < nodes; i++) {
        cout << parents[i] << " ";
    }

    return 0;
}

