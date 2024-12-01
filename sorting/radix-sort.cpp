#include <iostream>
#include <vector>
#include <queue>
#include "array-utils.h"

using namespace std;

/*
    Radix sort is a non-comparative sorting algorithm that sorts the elements by first grouping the individual digits of the same place value and sorting the elements according to their increasing/decreasing order:
    
        1. Find the maximum element in the array.
        2. Call counting sort for each digit place value.
        3. Populate the sorted array.

    Time complexity: O(dn) [all cases]
    Space complexity: O(n) [all cases]
    
    where, 
        n := number of elements in the input array
        d := digit count of the maximum element
*/

int get_max(int ara[], int n) {
    int max_element = ara[0];

    for (int i = 1; i < n; i++) {
        if (ara[i] > max_element) {
            max_element = ara[i];
        }
    }
    
    return max_element;
}

/*
    Radix sort using buckets (queues) and default radix 10
*/
void radix_sort(int ara[], int n) {
    int radix = 10;
    vector<queue<int>> buckets(radix);

    int max_element = get_max(ara, n);

    for (int r = 1; r < max_element; r *= 10) {
        // populate the buckets
        for (int j = 0; j < n; j++) {
            int digit = (ara[j] / r) % radix;
            buckets[digit].push(ara[j]);
        }

        // iterate over the buckets to reconstruct the array
        for (int j = 0, k = 0; j < radix; j++) {
            // pop the elements from the bucket until it is empty
            while (!buckets[j].empty()) {
                ara[k++] = buckets[j].front();
                buckets[j].pop();
            }
        }
    }
}

/*
    Radix sort using counting sort
*/
void counting_sort(int ara[], int n, int place) {
    
    // find the count of each element
    int max = 9, i;
    int count[max+1], sorted[n];
    for (i = 0; i < 10; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        count[(ara[i]/place) % 10]++; 
    }

    // 3. populate the sorted array: alternative
    // 3.1. find cumulative sum
    for (i = 1; i <= max; i++) {
        count[i] += count[i-1];
    }
    
    // 3.2. actual population
    for (i = n-1; i >= 0; i--) {
        int digit = (ara[i]/place) % 10;

        sorted[count[digit]-1] = ara[i];
        count[digit]--;
    }

    // 4. copy into the old array
    for (i = 0; i < n; i++) {
        ara[i] = sorted[i];
    }
}

void radix_sort(int ara[], int n) {
    // find the maximum and he minimum element
    int max = get_max(ara, n);

    // call counting sort for each radix
    int place = 1;
    while (max / place > 0) {
        counting_sort(ara, n, place);

        place = place * 10;
    }
}

int main() {
    int n; cin >> n;
    int ara[n]; 

    take_array_input(ara, n);

    radix_sort(ara, n);

    print_array(ara, n);

    return 0;
}