#include <iostream>
#include <vector>
using namespace std;

// Quick Union

class UnionFind {
    vector<int> parents;
    int nodes, edges;
public:
    UnionFind() {
        nodes = 0;
        edges = 0;
    }

    UnionFind(int nodes, int edges) {
        this->nodes = nodes;
        this->edges = edges;

        parents.resize(nodes);
        for (int i = 0; i < nodes; i++) {
            parents[i] = i;
        }
    }

    void Union(int u, int v) {
        int root_u = root(u);
        int root_v = root(v);

        parents[root_v] = root_u;
    }

    int root(int node) {
        while (parents[node] != node) {
            node = parents[node];
        }
        return node;
    }

    bool Find(int u, int v) {
        if (root(u) == root(v)) {
            return true;
        } else {
            return false;
        }
    }

    void printParents() {
        for (int i = 0; i < nodes; i++) {
            cout << parents[i] << " ";
        }
        cout << "\n";
    }
};

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

    UnionFind unionFind(nodes, edges);

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        Union(parents, u, v);
        unionFind.Union(u, v);
    }
    
    for (int i = 0; i < nodes; i++) {
        cout << parents[i] << " ";
    }
    cout << "\n";

    unionFind.printParents();
    
    Union(parents, 2, 4);
    unionFind.Union(2, 4);
    
    for (int i = 0; i < nodes; i++) {
        cout << parents[i] << " ";
    }
    cout << "\n";
    unionFind.printParents();

    return 0;
}

