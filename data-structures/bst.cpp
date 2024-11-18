#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    string data;
    int size;

    Node(string data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        size = 1;
    }
};

class BST {
    Node* root;

    Node* insert_element_util(Node* node, string data) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert_element_util(node->left, data);
        } else {
            node->right = insert_element_util(node->right, data);
        }

        node->size = 1 + size(node->left) + size(node->right);

        return node;
    }

    /*
        if equal := return
        if less := go left
    */
    Node* floor_util(Node* node, string data) {
        if (node == nullptr) {
            return nullptr;
        }

        if (data == node->data) {
            return node;
        } else if (data < node->data) {
            return floor_util(node->left, data);
        } else {
            Node* original_node = node;
            Node* right_node = floor_util(node->right, data);

            if (right_node == nullptr) {
                return original_node;
            } else {
                return right_node;
            }
        }
    }

    Node* ceiling_util(Node* node, string data) {
        if (node == nullptr) {
            return nullptr;
        }

        if (data == node->data) {
            return node;
        } else if (data > node->data) {
            return ceiling_util(node->right, data);
        } else {
            Node* original_node = node;
            Node* left_node = ceiling_util(node->left, data);

            if (left_node == nullptr) {
                return original_node;
            } else {
                return left_node;
            }
        }
    }

    Node* select_util(Node* node, int count) {
        if (node == nullptr) {
            return nullptr;
        }

        int root_left_size = size(node->left) + 1;

        if (count < root_left_size) {
            select_util(node->left, count);
        } else if (count > root_left_size) {
            select_util(node->right, count - root_left_size);
        } else {
            return node;
        }

    }

    int rank_util(Node* node, string data) {
        if (node == nullptr) {
            return 0;
        }

        if (data < node->data) {
            return rank_util(node->left, data);
        } else if (data > node->data) {
            return size(node->left) + 1 + rank_util(node->right, data);
        } else {
            return size(node->left) + 1;
        }

        return 0;
    }

    void keys_util(Node* node, string low, string high, vector<string>& result) {
        if (node == nullptr) {
            return;
        }

        if (node->data < low || node->data > high) {
            return;
        }

        keys_util(node->left, low, high, result);
        result.push_back(node->data);
        keys_util(node->right, low, high, result);
    }
        
    int size_util(Node* node, string low, string high) {
        if (node == nullptr) {
            return 0;
        }

        if (node->data < low || node->data > high) {
            return 0;
        }

        return 1 + size_util(node->left, low, high) + size_util(node->right, low, high);
    }

public:
    BST() {
        root = nullptr;
    }

    void set_root(Node* new_root) {
        this->root = new_root;
    }

    Node* get_root() {
        return root;
    }

    int size(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->size;
    }

    Node* insert_element(string data) {
        root = insert_element_util(root, data);
    }

    // floor(data): largest node that is equal to or smaller than data
    string floor(string data) {
        Node* node = floor_util(root, data);

        if (node == nullptr) {
            return "";
        } else {
            return node->data;
        }
    }

    // ceiling(data): smallest node that is equal to or larger than data
    string ceiling(string data) {
        Node* node = ceiling_util(root, data);

        if (node == nullptr) {
            return "";
        } else {
            return node->data;
        }
    }

    // select(count): the count-th ascending node
    string select(int count) {
        Node* node = select_util(root, count);

        if (node == nullptr) {
            return "";
        } else {
            return node->data;
        }
    }

    // rank(data): postion in ascending order
    int rank(string data) {
        return rank_util(root, data);
    }

    vector<string> keys(string low, string high) {
        vector<string> result;
        keys_util(root, low, high, result);
        return result;
    }

    int size(string low, string high) {
        return size_util(root, low, high);
    }

    vector<string> keys_nonrec(string low, string high) {
        vector<string> result;
        stack<Node*> s;

        Node* node = root;

        while (node || !s.empty()) {
            while (node && low <= node->data && node->data <= high) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();

            result.push_back(node->data);

            node = node->right;
        }

        return result;
    }

};


int main() {
    BST bst;

    bst.insert_element("E");
    bst.insert_element("D");
    bst.insert_element("Q");
    bst.insert_element("A");
    bst.insert_element("J");
    bst.insert_element("T");
    bst.insert_element("G");
    bst.insert_element("M");
    bst.insert_element("S");

    cout << "floor(Q): " << bst.floor("Q") << endl;
    cout << "floor(F): " << bst.floor("F") << endl;
    cout << "floor(S): " << bst.floor("S") << endl;
    cout << endl;
    cout << "select(5): " << bst.select(5) << endl;
    cout << "select(3): " << bst.select(3) << endl;
    cout << "select(7): " << bst.select(7) << endl;
    cout << "select(10): " << bst.select(10) << endl;
    cout << endl;
    cout << "rank(E): " << bst.rank("E") << endl;
    cout << "rank(J): " << bst.rank("J") << endl;
    cout << "rank(M): " << bst.rank("M") << endl;
    cout << "rank(C): " << bst.rank("C") << endl;
    cout << "rank(Z): " << bst.rank("Z") << endl;
    cout << endl;
    vector<string> keys_result = bst.keys("D", "T");
    for (string key : keys_result) {
        cout << key << " ";
    }
    cout << endl;
    vector<string> keys_result_nonrec = bst.keys_nonrec("D", "T");
    for (string key : keys_result_nonrec) {
        cout << key << " ";
    }
    cout << endl;
    cout << bst.size("D", "T");

    return 0;
}

/*
    lg(N!) ~ Nlg(N)

    lg(N!) = lg(1 * 2 * 3 * ... * N)
           = lg(1) + lg(2) + lg(3) + ... + lg(N)
           < lg(N) + lg(N) + lg(N) + ... + lg(N)
           = Nlg(N)

    lg(N!) ~ Nlg(N)

    ABC
    ACB
    BAC
    BCA
    CAB
    CBA


                *
               /  \
              *    *
             / \ / \
            *  * *  *

                      *
                     /
                    *
                   /
                  *
                 /
                *
               /
              *
*/