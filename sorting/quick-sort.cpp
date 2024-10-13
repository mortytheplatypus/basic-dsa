#include <iostream>
#include "array-utils.h"

using namespace std;

/*
    Quick sort is a divide-and-conquer algorithm that divides the input array into two parts, recursively sorts the two parts, and then combines the sorted parts:
    
        1. Choose a `pivot` element from the array.
        2. Partition the array such that all elements less than the `pivot` are on the left side of the `pivot` and all elements greater than the `pivot` are on the right side of the `pivot`.
        3. Recursively sort the left and right parts.
        4. Combine the sorted parts.
    
    The base case of the recursion is when the array has only one element.

    Time complexity: 
        - Best case: O(nlogn) 
        - Worst case: O(n^2) [already sorted]
        - Average case: O(nlogn)

    Space complexity: O(logn) [all cases]
    
    where, 
        n := number of elements in the input array
*/

int partition(int ara[], int low, int high) {
    int pivot = ara[high]; // choose the last element as the pivot
    int p = 0; // index of the smaller element

    for (int i = 0; i < high; i++) {
        if (ara[i] < pivot) {
            swap(ara[i], ara[p]);
            p++;
        }
    }

    swap(ara[p], ara[high]);

    return p;
}

void quick_sort(int ara[], int low, int high) {
    if (low >= high) {
        return;
    }

    int p = partition(ara, low, high);

    quick_sort(ara, low, p-1);
    quick_sort(ara, p+1, high);
}

int main() {
    int n; cin >> n;
    int ara[n]; 

    take_array_input(ara, n);

    quick_sort(ara, 0, n-1);

    print_array(ara, n);

    return 0;
}