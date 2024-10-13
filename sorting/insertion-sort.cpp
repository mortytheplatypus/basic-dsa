#include <iostream>
#include "utils.h"

using namespace std;

/*
    Insertion sort works by repeatedly inserting elements from the unsorted part of the array into the sorted part of the array:

        1. Start from the second element of the list.
        2. Compare the current element with the elements to its left.
        3. If the current element is smaller than the 
            element to its left, shift the element to the right.
        4. Repeat steps 2-3 until the current element is in the right position.
        5. Move to the next element.
        6. Repeat steps 2-5 until the end of the list.

    The list is sorted when all elements are in the right position.

    Time complexity: 
        - Best case: O(n) [already sorted]
        - Worst case: O(n^2) [reverse sorted]
        - Average case: O(n^2)

    Space complexity: O(1) [all cases]

    where, 
        n := number of elements in the input array
*/

void insertion_sort(int ara[], int n) {

    for (int i = 1; i < n; i++) {
        int key = ara[i], j;

        for (j = i-1; j >= 0 && ara[j] > key; j--) {
            ara[j+1] = ara[j]; // shift the element to the right
        }

        ara[j+1] = key;
    }
}

int main() {
    int n; cin >> n;
    int ara[n]; 

    take_array_input(ara, n);

    insertion_sort(ara, n);

    print_array(ara, n);

    return 0;
}
