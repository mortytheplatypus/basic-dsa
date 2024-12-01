# Selection Sort

### Algorithm
Selection sort works by repeatedly selecting the smallest element from the `unsorted` portion of the list swapping it with the first element of the `unsorted` portion:

```
1. Start from the beginning of the list.
2. Find the smallest element in the list.
3. Swap the smallest element with the first element.
4. Move to the next element.
5. Repeat steps 2-4 until the end of the list.

The list is sorted when the `unsorted` portion is empty.
```
____

### Pseudocode  

```c
    void selection_sort(int ara[], int n) {
        int i, min_index;

        for (i = 0; i < n; i++) {
            min_index = i;

            for (j = i+1; j < n; j++) {
                // find the smallest element
                if (ara[j] < ara[min_index]) {
                    min_index = j;
                }
            }

            // swap the smallest element with the first element
            swap(ara[i], ara[min_index]);
        }
    }
```

\newpage

### Space Complexity
Selection sort is an in-place sorting algorithm. It only requires a constant amount of extra space. Hence, the space complexity of selection sort is **$O(1)$**.
  
### Time Complexity
Selection sort shows consistent time complexities across all cases, and that is $O(n^2)$.

____

### Example
Performs the same across all cases with a time complexity of $O(n^2)$.

```
Input:  {3, 1, 6, 2, 5, 4}

i = 0: min_index = 0
    {[3], 1, 6, 2, 5, 4}
    j = 1: ara[1] = 1 min_index = 1 // smallest element
    j = 2, ara[2] = 6 min_index = 1
    j = 3, ara[3] = 2 min_index = 1
    j = 4, ara[4] = 5 min_index = 1
    j = 5, ara[5] = 4 min_index = 1
    swap(3, 1) => {[1], 3, 6, 2, 5, 4}

i = 1: min_index = 1
    {1, [3], 6, 2, 5, 4}
    j = 2, ara[2] = 6 min_index = 1
    j = 3, ara[3] = 2 min_index = 3 // smallest element
    j = 4, ara[4] = 5 min_index = 3
    j = 5, ara[5] = 4 min_index = 5
    swap(3, 2) => {1, [2], 6, 3, 5, 4}

i = 2: min_index = 2
    {1, 2, [6], 3, 5, 4}
    j = 3, ara[3] = 3 min_index = 3 // smallest element
    j = 4, ara[4] = 5 min_index = 3
    j = 5, ara[5] = 4 min_index = 5
    swap(6, 3) => {1, 2, [3], 6, 5, 4}

i = 3: min_index = 3
    {1, 2, 3, [6], 5, 4}
    j = 4, ara[4] = 5 min_index = 4 
    j = 5, ara[5] = 4 min_index = 5 // smallest element
    swap(6, 4) => {1, 2, 3, [4], 5, 6}

i = 4: min_index = 4
    {1, 2, 3, 4, [5], 6}
    j = 5, ara[5] = 6 min_index = 5 // smallest element
    swap(5, 5) => {1, 2, 3, 4, [5], 6}

since `j = i + 1', it becomes 6 for `i = 5', which is equal to `n'. 
	so the loop breaks.

Output: {1, 2, 3, 4, 5, 6}

            Array length = 6
        Total iterations = 15
                         = (1/2) * 6 * (6-1)

            General Case = (1/2) * n * (n-1)
```