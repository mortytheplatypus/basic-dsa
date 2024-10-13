#include <iostream>
#include "utils.h"

using namespace std;

/*
    Merge sort is a divide-and-conquer algorithm that divides the input array into two halves, recursively sorts the two halves, and then merges the sorted halves:

        1. Divide the array into two halves.
        2. Recursively sort the two halves.
        3. Merge the sorted halves.

    The base case of the recursion is when the array has only one element.

    Time complexity: O(nlogn) [all cases]
    Space complexity: O(n) [all cases]

    where, 
        n := number of elements in the input array
*/

void merge(int ara[], int low, int mid, int high) {
    int n = high-low+1; 
    int newAra[n]; 

    int i, j, k;
    i = low; // for left subarray
    j = mid+1; // for right subarray
    k = 0; // for new array

    // merge the two halves
    while (i <= mid && j <= high) {
        if (ara[i] < ara[j]) {
            newAra[k++] = ara[i++];
        } else {
            newAra[k++] = ara[j++];
        }
    }
    
    // copy the remaining elements of the left subarray, if any
    while (i <= mid) {
        newAra[k++] = ara[i++];
    }

    // copy the remaining elements of the right subarray, if any
    while (j <= high) {
        newAra[k++] = ara[j++];
    }

    // copy the merged array back to the original array
    for (k = 0; k < n; k++) {
        ara[low+k] = newAra[k]; 
    }
}

void mergeSort(int ara[], int low, int high) {
    if (low == high) {
        return;
    }

    int mid = (low + high) / 2;

    mergeSort(ara, low, mid);
    mergeSort(ara, mid+1, high);

    merge(ara, low, mid, high);
}

int main() {
    int n; cin >> n;
    int ara[n];
    
    take_array_input(ara, n);

    mergeSort(ara, 0, n-1);

    print_array(ara, n);

    return 0;
}