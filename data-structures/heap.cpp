#include <iostream>
#include <vector> 
using namespace std;

// max heap

void print(vector<int> v) {
    for (int n : v) {
        cout << n << " ";
    }
    cout << "\n";
}

void insert(vector<int> &v, int data) {
    v.push_back(data);

    int current_index = v.size() - 1;

    while (current_index > 0) {
        int parent_index = (current_index - 1) / 2;

        if (v[current_index] > v[parent_index]) {
            swap(v[current_index], v[parent_index]);

            current_index = parent_index;
        } else {
            break;
        }
    }
}

int find_max(vector<int> v) {
    if (v.size() == 0) {
        cout << "Heap is empty\n";
        exit(1);
    }

    return v[0];
}

void heapify(vector<int> &v, int index) {
    int n = v.size(), largest_index = index;

    int left = 2*index + 1;
    int right = 2*index + 2;
    
    if (left < n && v[left] > v[largest_index]) {
        largest_index = left;
    }

    if (right < n && v[right] > v[largest_index]) {
        largest_index = right;
    }

    if (index != largest_index) {
        swap(v[index], v[largest_index]);
        heapify(v, largest_index);
    }
}

// fetch the root element
int extract_max(vector<int> &v) {
    int n = v.size();
    if (n == 0) {
        cout << "Heap is empty\n";
        exit(1);
    }

    int max_element = v[0];

    v[0] = v[n-1]; // copy the last element
    v.pop_back();

    heapify(v, 0);

    return max_element;
}

void convert_ara_to_heap(vector<int> &v) {
    for (int i = v.size() / 2; i >= 0; i--) {
        heapify(v, i);
    }
}

int main() {
    vector<int> v1 = {100, 50, 60, 40, 10, 20, 30};

    print(v1);
    insert(v1, 70);
    print(v1);

    cout << extract_max(v1) << "\n";
    print(v1);

    vector<int> v2 = {12, 7, 3, 9, 14, 8, 2, 10, 1, 13, 6, 15, 11, 4, 5};

    print(v2);
    convert_ara_to_heap(v2);
    print(v2);

    return 0;
}



