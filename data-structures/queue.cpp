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

void enqueue(Node* front, int data) {
    // 1. create a new node
    Node* new_node = create_new_node(data);

    if (new_node == nullptr) {
        return;
    }

    // 2. traverse to the last node and append the new node
    Node* node = front;
    
    while (node->next) {
        node = node->next;
    }

    node->next = new_node;

    cout << data << " is enqueued to the queue\n";

    return;
}

void dequeue(Node** pointer_to_front) {
    // if the queue is empty, return
    if (*pointer_to_front == nullptr) {
        cout << "The queue is empty\n";
        return;
    }

    Node* del_node = *pointer_to_front;

    *pointer_to_front = (*pointer_to_front)->next;

    cout << del_node->data << " is dequeued from the queue\n";

    free(del_node);
    del_node = nullptr;

    return;
}

int get_front(Node* front) {
    // if the queue is empty, return
    if (front == nullptr) {
        cout << "The queue is empty\n";
        exit(1);
    }

    return front->data;
}

int main() {
    Node* front = create_new_node(1);

    enqueue(front, 2);
    enqueue(front, 3);
    enqueue(front, 4);

    cout << "Front of the queue: " << get_front(front) << endl;

    dequeue(&front);
    dequeue(&front);
    dequeue(&front);
    dequeue(&front);
    dequeue(&front);

    return 0;
}