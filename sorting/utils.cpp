#include "utils.h"

void take_array_input(int arr[], int size) {
    for(int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

void print_array(const int arr[], int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

