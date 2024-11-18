#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class AVL {
    Node* root;

    bool search_element_util(Node* node, int data) {
        if (root == nullptr) {
            return false;
        }

        cout << "Currently visiting " << node->data << "\n";

        if (data < node->data) {
            return search_element_util(node->left, data);
        } else if (data > node->data) {
            return search_element_util(node->right, data);
        } else {
            return true;
        }
    }

    Node* insert_element_util(Node* node, int data) {
        if (node == nullptr) {
            cout << "Adding " << data << "\n";
            node = new Node(data);
            return node;
        }

        cout << "Currently visiting " << node->data << "\n";

        if (data < node->data) {
            node->left = insert_element_util(node->left, data);
        } else {
            node->right = insert_element_util(node->right, data);
        }

        int left_height = get_height(node->left);
        int right_height = get_height(node->right);

        root->height = 1 + max(left_height, right_height);

        balance_tree();

        return root;
    }

    int get_height(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        return root->height;
    }

    int get_balance_factor(Node* node) {
        int left_height = get_height(node->left);
        int right_height = get_height(node->right);

        return get_height(node->left) - get_height(node->right);
    }

    void balance_tree() {
        int balance_factor = get_balance_factor(root);

        if (-1 <= balance_factor && balance_factor <= 1) {
            return;
        }

        if (balance_factor > 0) {
            // L
            Node* node = root->left;
            
            int left_height = get_height(node->left);
            int right_height = get_height(node->right);

            if (left_height > right_height) {
                // LL
                node = rotate_ll(node);
            } else {
                // LR
                node = rotate_lr(node);
            }
        } else {
            // R
            Node* node = root->right;

            int left_height = get_height(node->left);
            int right_height = get_height(node->right);

            if (right_height > left_height) {
                // RR
                node = rotate_rr(node);
            } else {
                // RL
                node = rotate_rl(node);
            }
        }
    }

    Node* rotate_ll(Node* node) {
        Node* prev_root = node;
        Node* prev_left = node->left;
        Node* dangling_node = prev_left->right;

        prev_left->right = prev_root;
        prev_root->left = dangling_node;

        node = prev_left;

        return node;
    }

    Node* rotate_lr(Node* node) {
        Node* prev_left = node->left;
        Node* prev_left_right = prev_left->right;
        Node* dangling_node = prev_left_right->left;

        // step-1
        root->left = prev_left_right;

        // step-2
        prev_left->right = dangling_node;

        // step-3
        prev_left_right->left = prev_left;

        return rotate_ll(node);
    }

    Node* rotate_rr(Node* node) {
        Node* prev_root = node;
        Node* prev_right = node->right;
        Node* dangling_node = root->right->left;

        prev_right->left = prev_root;
        prev_root->right = dangling_node;

        node = prev_right;

        return node;
    }

    Node* rotate_rl(Node* node) {
        Node* prev_right = node->right;
        Node* prev_right_left = prev_right->left;
        Node* dangling_node = prev_right_left->right;

        // step-1
        root->right = prev_right_left;

        // step-2
        prev_right->left = dangling_node;

        // step-3
        prev_right_left->right = prev_right;

        return rotate_rr(node);
    }
public:

    AVL() {
        root = nullptr;
    }

    bool search_element(int data) {
        return search_element_util(root, data);
        cout << "\n";
    }

    void insert_element(int data) {
        root = insert_element_util(root, data);
        cout << "\n";
    }

};


int main() {

    AVL avl;

    avl.insert_element(24);
    avl.insert_element(10);
    avl.insert_element(40);
    avl.insert_element(5);
    avl.insert_element(20);
    avl.insert_element(30);
    avl.insert_element(50);

    return 0;
}

