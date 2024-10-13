#include <iostream>
#include "utils.h"

using namespace std;

/*
    Shell sort is a generalization of insertion sort that allows the exchange of items that are far apart:
    
        1. Start with a large interval between the elements. [typically n/2]
        2. Reduce the interval in each iteration. [n/2, n/4, ..., 1]
        3. Perform insertion sort on the elements with the reduced interval.
        4. Repeat steps 2-3 until the interval is 1.

    The final pass of shell sort is equivalent to insertion sort.

    Time complexity: 
        - Best case: O(nlogn) [depends on the interval sequence]
        - Worst case: O(n^2) [depends on the interval sequence]
        - Average case: O(nlogn) [depends on the interval sequence]

    Space complexity: O(1) [all cases]
*/

void shell_sort(int ara[], int n) {
    for (int interval = n/2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i++) {
            int key = ara[i], j;

            for (j = i; j >= interval && ara[j-interval] > key; j -= interval) {
                ara[j] = ara[j-interval];
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
