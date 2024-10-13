#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node_t {
    int data;
    struct node_t* next;
} Node;

Node* create_new_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    if (new_node == nullptr) {
        cout << "Memory allocation failed!\n";
        return nullptr;
    }

    new_node->data = data;
    new_node->next = nullptr;

    return new_node;
}

void print_linked_list(Node* root) {
    Node* node = root;

    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }

    cout << endl;
}

void append(Node** pointer_to_root, int data) {
    // 1. create a new node
    Node* new_node = create_new_node(data);

    if (new_node == nullptr) {
        return;
    }

    // 2. if the linked list is empty, make the new node the root
    if (*pointer_to_root == nullptr) {
        *pointer_to_root = new_node;

        cout << data << " is the root of the linked list\n";

        return;
    }

    // 3. else, traverse to the last node and append the new node

    Node* node = *pointer_to_root;

    while (node->next) {
        node = node->next;
    }

    node->next = new_node;

    cout << "Appended " << data << " to the linked list\n";

    return;

}

void prepend(Node** pointer_to_root, int data) {
    // 1. create a new node
    Node* new_node = create_new_node(data);

    if (new_node == nullptr) {
        return;
    }

    // 2. Point the next of the new root to the current root
    new_node->next = *pointer_to_root;

    // 3. Make the new node the root
    *pointer_to_root = new_node;

    cout << data << " is the new root of the linked list\n";

    return;
}

void insert_after(Node** pointer_to_root, int data, int new_data) {
    // 1. create a new node
    Node* new_node = create_new_node(new_data);

    if (new_node == nullptr) {
        return;
    }

    // 2. if the linked list is empty, return
    if (*pointer_to_root == nullptr) {
        cout << "The linked list is empty\n";
        return;
    }

    Node* node = *pointer_to_root;

    // 3. traverse to the node after which the new node is to be inserted
    while (node) {
        if (node->data == data) {
            new_node->next = node->next;
            node->next = new_node;

            cout << "Inserted " << new_data << " after " << data << " in the linked list\n";

            return;
        }

        node = node->next;
    }

    // 4. if the node is not found
    cout << data << " is not found in the linked list\n";

    return;
}

void delete_node(Node** pointer_to_root, int data) {
    // 1. if the linked list is empty, return
    if (*pointer_to_root == nullptr) {
        cout << "The linked list is empty\n";
        return;
    }

    Node* node = *pointer_to_root;

    // 2. if the root is the node to be deleted
    if (node->data == data) {
        Node* del_node = node;
        *pointer_to_root = node->next;

        free(del_node);
        del_node = nullptr;

        cout << "Deleted root(" << data << ") from the linked list\n";

        return;
    }

    // 3. else, traverse to the node to be deleted
    
    while (node->next) {
        if (node->next->data == data) {
            Node* del_node = node->next;

            if (node->next) {
                node->next = node->next->next;
            } else {
                node->next = nullptr;
            }

            free(del_node);
            del_node = nullptr;

            cout << "Deleted " << data << " from the linked list\n";

            return;
        }

        node = node->next;
    }

    // 4. if the node is not found
    cout << data << " is not found in the linked list\n";

    return;
}

int main() {
    Node* root = nullptr;

    append(&root, 1);
    append(&root, 2);
    append(&root, 3);
    append(&root, 4);
    append(&root, 5);

    print_linked_list(root);

    prepend(&root, 0);
    prepend(&root, -1);

    print_linked_list(root);

    delete_node(&root, 0);
    delete_node(&root, 5);
    delete_node(&root, 10);

    print_linked_list(root);

    insert_after(&root, 3, 6);
    insert_after(&root, 10, 6);

    print_linked_list(root);

    return 0;
}