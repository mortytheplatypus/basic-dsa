#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// create a new node
Node* create_new_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    if (new_node == nullptr) {
        cout << "Memory allocation failed!\n";
        return nullptr;
    }

    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;

    return new_node;
}

// implement the inorder, preorder, and postorder traversal

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void add_left_child(Node* root, int parent_data, int data) {
    Node* new_node = create_new_node(data);

    if (new_node == nullptr) {
        return;
    }

    Node* node = root;

    while (node) {
        if (node->data == parent_data) {
            node->left = new_node;
            return;
        }

        if (node->left) {
            node = node->left;
        } else if (node->right) {
            node = node->right;
        } else {
            return;
        }
    }
}

void add_left_child_rec(Node* root, int parent_data, int data) {

    if (root == nullptr) {
        return;
    }
    
    if (root->data == parent_data) {
        root->left = create_new_node(data);
        return;
    }

    add_left_child_rec(root->left, parent_data, data);
    add_left_child_rec(root->right, parent_data, data);
}

void add_right_child(Node* root, int parent_data, int data) {
    Node* new_node = create_new_node(data);

    if (new_node == nullptr) {
        return;
    }

    Node* node = root;

    while (node) {
        if (node->data == parent_data) {
            node->right = new_node;
            return;
        }

        if (node->left) {
            node = node->left;
        } else if (node->right) {
            node = node->right;
        } else {
            return;
        }
    }
}

void add_right_child_rec(Node* root, int parent_data, int data) {

    if (root == nullptr) {
        return;
    }
    
    if (root->data == parent_data) {
        root->right = create_new_node(data);
        return;
    }

    add_right_child_rec(root->left, parent_data, data);
    add_right_child_rec(root->right, parent_data, data);
}

bool check_if_exists(Node* root, int data) {

    if (root == nullptr) {
        return false;
    }

    if (root->data == data) {
        return true;
    }

    bool isOnLeft = check_if_exists(root->left, data);
    bool isOnRight = check_if_exists(root->right, data);

    return isOnLeft || isOnRight;
}

int main() {
    Node* root = create_new_node(1);

    add_left_child(root, 1, 2);
    add_right_child(root, 1, 3);
    add_left_child(root, 2, 4);
    add_right_child(root, 2, 5);
    add_left_child(root, 3, 6);
    add_right_child(root, 3, 7);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}