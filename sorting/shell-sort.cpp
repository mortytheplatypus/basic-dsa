#include <iostream>
#include "array-utils.h"

using namespace std;

/*
    Shell sort is a generalization of insertion sort that allows the exchange of items that are far apart:
    
        1. Start with a large gap between the elements. [typically n/2]
        2. Reduce the gap in each iteration. [n/2, n/4, ..., 1]
        3. Perform insertion sort on the elements with the reduced gap.
        4. Repeat steps 2-3 until the gap is 1.

    The final pass of shell sort is equivalent to insertion sort.

    Time complexity: 
        - Best case: O(nlogn) [depends on the gap sequence]
        - Worst case: O(n^2) [depends on the gap sequence]
        - Average case: O(nlogn) [depends on the gap sequence]

    Space complexity: O(1) [all cases]
*/

void shell_sort(int ara[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int key = ara[i], j;

            for (j = i; j >= gap && ara[j-gap] > key; j -= gap) {
                ara[j] = ara[j-gap];
            }

            ara[j] = key;
        }
    }
}

int main() {
    int n; cin >> n;
    int ara[n]; 

    take_array_input(ara, n);

    shell_sort(ara, n);

    print_array(ara, n);

    return 0;
}
