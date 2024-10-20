#include <iostream>
#include <vector>
using namespace std;

bool Find(vector<int> components, int u, int v) {
    if (components[u] == components[v]) {
        return true;
    } else {
        return false;
    }
}

void Union(vector<int>& components, int u, int v) {

    int cu = components[u], cv = components[v];

    if (cu == cv) {
        return;
    }

    // traversing the whole array every time
    for (int i = 0; i < components.size(); i++) {
        if (components[i] == cv) {
            components[i] = cu;
        }
    }
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

