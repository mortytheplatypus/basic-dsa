#include <iostream>
#include <cstdlib>  

typedef struct node_t {
    int data;
    struct node_t* next;
} Node;

Node* create_new_node(int data) {
    Node* new_node = (Node*)std::malloc(sizeof(Node));
    
    if (new_node == nullptr) {
        std::cout << "Memory allocation failed!\n";
        return nullptr;
    }

    new_node->data = data;
    new_node->next = nullptr;

    return new_node;
}

void print_linked_list(Node* root) {
    Node* node = root;

    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }

    std::cout << std::endl;
}

void print_linked_list_circular(Node* root) {
    Node* node = root;

    do {
        std::cout << node->data << " ";
        node = node->next;
    } while (node != root);

    std::cout << std::endl;
}