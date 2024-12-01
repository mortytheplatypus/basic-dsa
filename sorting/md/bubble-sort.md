# Bubble Sort
  
### Algorithm
Bubble sort works by repeatedly swapping adjacent elements if they are in the wrong order, i.e., `bubbling` larger elements up: 

```
1. Start from the beginning of the list.
2. Compare the first two elements.
3. If the first element is greater than the 
     second element, swap them.  
4. Move to the next pair of elements.
5. Repeat steps 2-4 until the end of the list.
6. Repeat steps 1-5 until the list is sorted.

The list is sorted when no swaps are made in a pass.
```
____

### Pseudocode  

```c
    void bubble_sort(int ara[], int n) {
        for (i = 0; i < n-1; i++) {
            int is_sorted = 1;

            for (j = 0; j < n-1-i; j++) {
                // bubble the `larger` element up
                if (ara[j] > ara[j+1]) {
                    swap(ara[i], ara[j]);
                    is_sorted = 0;
                }
            }

            if (is_sorted == 1) {
                break;
            }
        }
    }
```

\newpage

### Space Complexity
Bubble sort is an in-place sorting algorithm. It only requires a constant amount of extra space. Hence, the space complexity of bubble sort is **$O(1)$**.
  
### Time Complexity
The time complexities of bubble sort is as follows:  

- Best Case: $O(n)$
- Average Case: $O(n^2)$
- Worst Case: $O(n^2)$

____
### Example

#### Best Case
- When the array is already sorted. 
- Time complexity: $O(n)$.

```
Input:  {1, 2, 3, 4, 5, 6}

i = 0: 
        {[1, 2], 3, 4, 5, 6}  // No swap
        {1, [2, 3], 4, 5, 6}  // No swap
        {1, 2, [3, 4], 5, 6}  // No swap
        {1, 2, 3, [4, 5], 6}  // No swap
        {1, 2, 3, 4, [5, 6]}  // No swap

Since no swaps are made, the `is_sorted` flag remains 1,
and the loop breaks. 

Output: {1, 2, 3, 4, 5, 6}

            Array length = 6
        Total iterations = 6-1 = 5

            General Case = n-1
```
\newpage
#### Worst Case
- When the array is sorted in reverse order.
- Time complexity: $O(n^2)$.

```
Input:  {6, 5, 4, 3, 2, 1}

i = 0: 
        {[5, 6], 4, 3, 2, 1}  // Swap
        {5, [4, 6], 3, 2, 1}  // Swap
        {5, 4, [3, 6], 2, 1}  // Swap
        {5, 4, 3, [2, 6], 1}  // Swap
        {5, 4, 3, 2, [1, 6]}  // Swap

i = 1: 
        {[4, 5], 3, 2, 1, 6}  // Swap
        {4, [3, 5], 2, 1, 6}  // Swap
        {4, 3, [2, 5], 1, 6}  // Swap
        {4, 3, 2, [1, 5], 6}  // Swap

i = 2: 
        {[3, 4], 2, 1, 5, 6}  // Swap
        {3, [2, 4], 1, 5, 6}  // Swap
        {3, 2, [1, 4], 5, 6}  // Swap

i = 3: 
        {[2, 3], 1, 4, 5, 6}  // Swap
        {2, [1, 3], 4, 5, 6}  // Swap

i = 4: 
        {[1, 2], 3, 4, 5, 6}  // Swap

Since no swaps are made, the `is_sorted` flag remains 1,
and the loop breaks.

Output: {1, 2, 3, 4, 5, 6}

            Array length = 6
        Total iterations = (1/2) * 6 * (6-1) = 15

        General Case = (1/2) * n * (n-1)
```
\newpage

#### Average Case 
- When the array is randomly sorted.
- Time complexity: $O(n^2)$.

```
Input:  {3, 1, 6, 2, 5, 4}

i = 0: 
        {[1, 3], 6, 2, 5, 4}  // Swap
        {1, [3, 6], 2, 5, 4}  // No swap
        {1, 3, [2, 6], 5, 4}  // Swap
        {1, 3, 2, [5, 6], 4}  // No swap
        {1, 3, 2, 5, [4, 6]}  // Swap

i = 1: 
        {[1, 3], 2, 5, 4, 6}  // Swap
        {1, [2, 3], 5, 4, 6}  // No swap
        {1, 2, [3, 5], 4, 6}  // No swap
        {1, 2, 3, [4, 5], 6}  // Swap

i = 2: 
        {[1, 2], 3, 4, 5, 6}  // Swap
        {1, [2, 3], 4, 5, 6}  // No swap
        {1, 2, [3, 4], 5, 6}  // No swap

i = 3: 
        {[1, 2], 3, 4, 5, 6}  // No swap
        {1, [2, 3], 4, 5, 6}  // No swap

since no swaps are made, the `is_sorted' flag remains 1,
and the loop breaks.

Output: {1, 2, 3, 4, 5, 6}

            Array length = 6
        Total iterations = 14 
                         = 6 * (6-1) / 2 - 1

        General Case = (1/2) * n * (n-1) - m
                [where `m' depends on how much sorted the array is]
```