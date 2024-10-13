#include <iostream>
#include "utils.h"

using namespace std;

/*
    Counting sort works by counting the number of occurrences of each element in the input array and then using the counts to populate the sorted array:
    
        1. Find the maximum element in the array.
        2. Find the count of each element.
        3. Populate the sorted array.

    Time complexity: O(n+k) [all cases]

    Space complexity: O(n+k) [all cases]

    where, 
        n := number of elements in the input array
        k := range of the input.
*/


/*
    In the following version, the array is assumed to only contain non-negative integers
*/
void counting_sort(int ara[], int n) {
    // 1. find the maximum and he minimum element
    int i, j, k, max = ara[0];
    for (i = 1; i < n; i++) {
        if (ara[i] > max) {
            max = ara[i];
        }
    }

    // 2. find the count of each element
    int count[max + 1], sorted[n];
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        count[ara[i]]++; 
    }

    // 3. populate the sorted array

    // 3.1. find cumulative sum
    for (i = 1; i <= max; i++) {
        count[i] += count[i-1];
    }
    
    // 3.2. actual population
    for (i = n-1; i >= 0; i--) {
        sorted[count[ara[i]]-1] = ara[i];
        count[ara[i]]--;
    }

    /*
        An alternative way to populate the sorted array:

            for (i = 0, k = 0; i <= max; i++) {
                for (j = 0; j < count[i]; j++) {
                    sorted[k] = i;
                    k++;
                }
            }

        sum(count[i]) = n, although there are nested loops, the time complexity still is O(n)
    */

    // 4. copy into the old array
    for (i = 0; i < n; i++) {
        ara[i] = sorted[i];
    }
}


/*
    A more general version of counting sort that can handle negative integers as well
*/

void counting_sort_generalized(int ara[], int n) {
    // 1. find the maximum and he minimum element
    int i, j, k, max = ara[0], min = ara[0];
    for (i = 1; i < n; i++) {
        if (ara[i] > max) {
            max = ara[i];
        }
        if (ara[i] < min) {
            min = ara[i];
        }
    }

    int range = max - min + 1;

    // 2. find the count of each element
    int count[range], sorted[n];
    for (i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        count[ara[i] - min]++; 
    }

    // 3. populate the sorted array

    // 3.1. find cumulative sum
    for (i = 1; i < range; i++) {
        count[i] += count[i-1];
    }
    
    // 3.2. actual population
    for (i = n-1; i >= 0; i--) {
        sorted[count[ara[i] - min]-1] = ara[i];
        count[ara[i] - min]--;
    }

    // 4. copy into the old array
    for (i = 0; i < n; i++) {
        ara[i] = sorted[i];
    }
}

int main() {
    int n; cin >> n;
    int ara[n]; 

    take_array_input(ara, n);

    counting_sort(ara, n);

    print_array(ara, n);

    return 0;
}