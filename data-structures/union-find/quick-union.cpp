#include <iostream>
#include <vector>
using namespace std;

// Quick Union

int root(vector<int> parents, int node) {
    while (parents[node] != node) {
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

void Union(vector<int> &parents, int u, int v) {
    int root_u = root(parents, u);
    int root_v = root(parents, v);

    parents[root_v] = root_u;
}

int main() {
    freopen("input.txt", "r", stdin); // read input from `input.txt`

    int nodes, edges, u, v;
    cin >> nodes >> edges;

    vector<int> parents(nodes);
    for (int i = 0; i < nodes; i++) {
        parents[i] = i;
    }

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        Union(parents, u, v);
    }
    
    for (int i = 0; i < nodes; i++) {
        cout << parents[i] << " ";
    }
    cout << "\n";
    
    Union(parents, 2, 4);
    
    for (int i = 0; i < nodes; i++) {
        cout << parents[i] << " ";
    }

    return 0;
}

