#include <iostream>
#include <vector>
using namespace std;

// Quick Union

int root(vector<int> components, int node) {
    while (components[node] != node) {
        node = components[node];
    }
    return node;
}

bool Find(vector<int> components, int u, int v) {
    if (root(components, u) == root(components, v)) {
        return true;
    } else {
        return false;
    }
}

void Union(vector<int> &components, int u, int v) {
    int root_u = root(components, u);
    int root_v = root(components, v);

    components[root_v] = root_u;
}

// complexity: O(N*M), where N = nodes, M = edges
int main() {
    freopen("input.txt", "r", stdin); // read input from `input.txt`

    int nodes, edges, u, v;
    cin >> nodes >> edges;

    vector<int> components(nodes);
    for (int i = 0; i < nodes; i++) {
        components[i] = i;
    }

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        Union(components, u, v);
    }
    
    for (int i = 0; i < nodes; i++) {
        cout << components[i] << " ";
    }
    cout << "\n";
    
    Union(components, 2, 4);
    
    for (int i = 0; i < nodes; i++) {
        cout << components[i] << " ";
    }

    return 0;
}

