#include <iostream>
#include <cstdlib> 
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

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

Node* insert_element(Node* root, int data) {
    if (root == nullptr) {
        root = create_new_node(data);
        return root;
    }

    if (data < root->data) {
        root->left = insert_element(root->left, data);
    } else {
        root->right = insert_element(root->right, data);
    }
}

bool search_element(Node* root, int data) {
    if (root == nullptr) {
        return false;
    }

    if (data < root->data) {
        search_element(root->left, data);
    } else if (data > root->data) {
        search_element(root->right, data);
    } else {
        return true;
    } 
}

Node* get_min_value_node(Node* root) {
    if (root == nullptr) {
        return root;
    }

    if (root->left == nullptr) {
        return root;
    }

    return get_min_value_node(root->left);
}

Node* delete_element(Node* root, int data) {
    if (root == nullptr) {
        return nullptr;
    }

    if (data < root->data) {
        root->left = delete_element(root->left, data);
    } else if (data > root->data) {
        root->right = delete_element(root->right, data);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            cout << "Deleting leaf(" << data << ")\n";
            free(root);
            return nullptr;
        } else if (root->left == nullptr) {
            Node* del_node = root;
            root = root->right;

            cout << "Deleting node(" << data << ") with one child\n";
            free(del_node);

            return root;
        } else if (root->right == nullptr) {
            Node* del_node = root;
            root = root->left;

            cout << "Deleting node(" << data << ") with one child\n";
            free(del_node);

            return root;
        } else {
            Node* min_value_node = get_min_value_node(root->right);

            // to avoid circular dependency
            root->data = min_value_node->data;
            
            // now delete the node with min_value_node->data
            root->right = delete_element(root->right, min_value_node->data);

            return root;
        }
    }
}

int main() {
    Node* root = nullptr;

    search_element(root, 23);

    root = insert_element(root, 23);
    root = insert_element(root, 11);
    root = insert_element(root, 7);
    root = insert_element(root, 34);
    root = insert_element(root, 16);
    root = insert_element(root, 38);
    root = insert_element(root, 47);
    root = insert_element(root, 30);
    root = insert_element(root, 31);
    root = insert_element(root, 32);
    root = insert_element(root, 25);

    preorder(root); cout << "\n";
    inorder(root); cout << "\n";
    postorder(root); cout << "\n";

    root = delete_element(root, 7);
    root = delete_element(root, 11);
    root = delete_element(root, 23);
    
    root = delete_element(root, 100);

    cout << root->data << "\n";

    return 0;
}

