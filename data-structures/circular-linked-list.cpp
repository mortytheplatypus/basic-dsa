#include <iostream>
#include <cstdlib>

using namespace std;

// implementation of a circular linked list

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
    if (root == nullptr) {
        cout << "The linked list is empty\n";
        return;
    }

    Node* node = root;

    do {
        cout << node->data << " ";
        node = node->next;
    } while (node != root);

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
        (*pointer_to_root)->next = *pointer_to_root;
        (*pointer_to_root)->prev = *pointer_to_root;

        cout << data << " is the root of the linked list\n";

        return;
    }

    // 3. else, just prepend the new node

    Node* last_node = (*pointer_to_root)->prev;

    new_node->next = *pointer_to_root;
    new_node->prev = last_node;

    last_node->next = new_node;
    (*pointer_to_root)->prev = new_node;

    cout << data << " is appended to the linked list\n";

    return;
}

void prepend(Node** pointer_to_root, int data) {
    // same as append

    append(pointer_to_root, data);

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
    do {
        if (node->data == data) {
            break;
        }

        node = node->next;
    } while (node != *pointer_to_root);

    // 4. if the node is not found
    if (node == *pointer_to_root) {
        cout << data << " is not found in the linked list\n";
        return;
    }

    // 5. insert the new node after the node
    new_node->next = node->next;
    new_node->prev = node;
    node->next->prev = new_node;
    node->next = new_node;

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

        if (node->next == node) {
            *pointer_to_root = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            *pointer_to_root = node->next;
        }

        free(del_node);
        del_node = nullptr;

        cout << "Deleted root(" << data << ") from the linked list\n";

        return;
    }

    // 3. else, traverse to the node to be deleted
    
    do {
        if (node->data == data) {
            break;
        }

        node = node->next;
    } while (node != *pointer_to_root);

    // 4. if the node is not found
    if (node == *pointer_to_root) {
        cout << data << " is not found in the linked list\n";
        return;
    }

    // 5. delete the node
    Node* del_node = node;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    free(del_node);
    del_node = nullptr;

    cout << "Deleted " << data << " from the linked list\n";

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
    prepend(&root, -2);

    print_linked_list(root);

    insert_after(&root, 3, 33);
    insert_after(&root, 5, 55);
    insert_after(&root, 0, 11);

    print_linked_list(root);

    delete_node(&root, 11);
    delete_node(&root, 33);
    delete_node(&root, 55);

    print_linked_list(root);

    delete_node(&root, -2);
    delete_node(&root, 5);
    delete_node(&root, 4);
    delete_node(&root, 3);
    delete_node(&root, 2);
    delete_node(&root, 1);
    delete_node(&root, 0);
    delete_node(&root, -1);

    print_linked_list(root);

    return 0;
}