#include <iostream>
#include "array-utils.h"

using namespace std;

/*
    Selection sort works by repeatedly selecting the smallest element from the `unsorted` portion of the list swapping it with the first element of the `unsorted` portion:

        1. Start from the beginning of the list.
        2. Find the smallest element in the list.
        3. Swap the smallest element with the first element.
        4. Move to the next element.
        5. Repeat steps 2-4 until the end of the list.

    The list is sorted when the `unsorted` portion is empty.

    Time complexity: O(n^2) [all cases]
    Space complexity: O(1) [all cases]

    where, 
        n := number of elements in the input array
*/

void selection_sort(int ara[], int n) {

    for (int i = 0; i < n; i++) {
        int min_index = i; // assume the current index holds the smallest element
        for (int j = i+1; j < n; j++) {
            if (ara[j] < ara[min_index]) {
                min_index = j; // update the index of the smallest element
            }
        }

        // swap the smallest element with the current element
        if (min_index != i) {
            swap(ara[i], ara[min_index]);
        }
    }
}

int main() {
    int n; cin >> n;
    int ara[n]; 

    take_array_input(ara, n);

    selection_sort(ara, n);

    print_array(ara, n);

    return 0;
}
