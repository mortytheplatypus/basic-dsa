#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* create_new_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    if (new_node == nullptr) {
        cout << "Memory allocation failed!\n";
        return nullptr;
    }

    new_node->data = data;
    new_node->prev = nullptr;
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
    new_node->prev = node;

    cout << data << " is appended to the linked list\n";

    return;
}

void prepend(Node** pointer_to_root, int data) {
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

    // 3. else, prepend the new node

    Node* node = *pointer_to_root;

    new_node->next = node;
    node->prev = new_node;

    *pointer_to_root = new_node;

    cout << data << " is prepended to the linked list\n";

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

    // 3. traverse to the node to insert after
    while (node) {
        if (node->data == data) {
            break;
        }

        node = node->next;
    }

    // 4. if the node is not found
    if (node == nullptr) {
        cout << data << " is not found in the linked list\n";
        return;
    }

    // 5. insert the new node after the node
    new_node->next = node->next;
    new_node->prev = node;
    node->next = new_node;

    if (new_node->next) {
        new_node->next->prev = new_node;
    }

    cout << new_data << " is inserted after " << data << " in the linked list\n";

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

        if (node->next) {
            node->next->prev = nullptr;
        }

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