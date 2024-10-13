#include <iostream>
#include "array-utils.h"

using namespace std;

/*
    Bubble sort works by repeatedly swapping adjacent elements if they are in the wrong order, i.e., `bubbling` larger elements up: 

        1. Start from the beginning of the list.
        2. Compare the first two elements.
        3. If the first element is greater than the 
            second element, swap them.  
        4. Move to the next pair of elements.
        5. Repeat steps 2-4 until the end of the list.
        6. Repeat steps 1-5 until the list is sorted.

    The list is sorted when no swaps are made in a pass.

    Time complexity: O(n^2) [all cases]
    Space complexity: O(1) [all cases]

    where, 
        n := number of elements in the input array
*/

void bubble_sort(int ara[], int n) {

    for (int i = 0; i < n-1; i++) {
        bool is_sorted = true;
        for (int j = 0; j < n-1-i; j++) {
            // bubble the `larger` element up
            if (ara[j] > ara[j+1]) {
                swap(ara[j], ara[j+1]);

                is_sorted = false;
            }
        }

        if (is_sorted) {
            break;
        }
    }
}

int main() {
    int n; cin >> n; 
    int ara[n]; 

    take_array_input(ara, n);

    bubble_sort(ara, n);

    print_array(ara, n);

    return 0;
}
