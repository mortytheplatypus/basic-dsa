#include <iostream>
#include <cstdlib>
#include <vector>
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

    return 0;
}