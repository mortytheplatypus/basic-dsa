#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node *next;
};

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

void push(Node** pointer_to_top, int data) {
    // 1. create a new node
    Node* new_node = create_new_node(data);

    if (new_node == nullptr) {
        return;
    }

    // 2. Point the next of the new node to the current root
    new_node->next = *pointer_to_top;

    // 3. Make the new node the root
    *pointer_to_top = new_node;

    cout << data << " is pushed to the stack\n";

    return;
}

void pop(Node** pointer_to_top) {
    // 1. if the stack is empty, return
    if (*pointer_to_top == nullptr) {
        cout << "The stack is empty\n";
        return;
    }

    Node* del_node = *pointer_to_top;

    *pointer_to_top = (*pointer_to_top)->next;

    cout << del_node->data << " is popped from the stack\n";

    free(del_node);
    del_node = nullptr;

    return;
}

int get_top(Node* top) {
    // if the stack is empty, return
    if (top == nullptr) {
        cout << "The stack is empty\n";
        exit(1);
    }

    return top->data;
}

int main() {
    Node* top = nullptr;

    push(&top, 1);
    push(&top, 2);
    push(&top, 3);

    cout << "Top of the stack: " << get_top(top) << endl;

    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);

    return 0;
}