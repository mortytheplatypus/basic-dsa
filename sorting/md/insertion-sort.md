# Insertion Sort
  
### Algorithm
Insertion sort works by repeatedly inserting elements from the unsorted part of the array into the sorted part ($left$) of the array:

```
1. Start from the second element of the list.
2. Compare the current element with the elements to its left.
3. If the current element is smaller than the 
     element to its left, shift the element to the right.
4. Repeat steps 2-3 until the current element is in the right position.
5. Move to the next element.
6. Repeat steps 2-5 until the end of the list.

The list is sorted when all elements are in the right position.
```

____

### Pseudocode  

```c
    void insertion_sort(int ara[], int n) {
        for (i = 1; i < n; i++) {
            key = ara[i];

            for (j = i-1; j >= 0 && ara[j] > key; j--) {
                // shift the `larger` element to the right
                ara[j+1] = ara[j]; 
            }

            // insert the key in the right position
            ara[j+1] = key;
        }
    }
```

\newpage

### Space Complexity
Insertion sort is an in-place sorting algorithm. It only requires a constant amount of extra space. Hence, the space complexity of Insertion sort is **$O(1)$**.
  
### Time Complexity
The time complexities of Insertion sort is as follows:  

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

i = 1: key = 2
    {[1, 2], 3, 4, 5, 6}
    j = 0: ara[j] < key := 1 < 2 
            does not enter inner loop

i = 2: key = 3
    {[1, 2, 3], 4, 5, 6}
    j = 1: ara[j] < key := 2 < 3 
            does not enter inner loop

i = 3: key = 4
    {[1, 2, 3, 4], 5, 6}
    j = 2: ara[j] < key := 3 < 4 
            does not enter inner loop

i = 4: key = 5
    {[1, 2, 3, 4, 5], 6}
    j = 3: ara[j] < key := 4 < 5 
            does not enter inner loop

i = 5: key = 6
    {[1, 2, 3, 4, 5, 6]}
    j = 4: ara[j] < key := 5 < 6 
            does not enter inner loop

No more elements to iterate.

Output: {1, 2, 3, 4, 5, 6}

            Array length = 6
        Total iterations = 6-1 = 5

            General Case = n-1

```
____  

#### Worst Case
- When the array is sorted in reverse order.
- Time complexity: $O(n^2)$.

```
Input:  {6, 5, 4, 3, 2, 1}

i = 1: key = 5
    {[5, 6], 4, 3, 2, 1}    
    j = 0: ara[j] < key := 6 > 5 
            ara[j+1] = ara[j] := {6, 6, 4, 3, 2, 1}

    j = -1: exit inner loop
            ara[j+1] = key := {5, 6, 4, 3, 2, 1}

i = 2: key = 4
    {[5, 6, 4], 3, 2, 1}
    j = 1: ara[j] < key := 6 > 4 
            ara[j+1] = ara[j] := {5, 6, 6, 3, 2, 1}
    j = 0: ara[j] < key := 5 > 4
            ara[j+1] = ara[j] := {5, 5, 6, 3, 2, 1}

    j = -1: exit inner loop
            ara[j+1] = key := {4, 5, 6, 3, 2, 1}

i = 3: key = 3
    {[4, 5, 6, 3], 2, 1}
    j = 2: ara[j] < key := 6 > 3 
            ara[j+1] = ara[j] := {4, 5, 6, 6, 2, 1}
    j = 1: ara[j] < key := 5 > 3
            ara[j+1] = ara[j] := {4, 5, 5, 6, 2, 1}
    j = 0: ara[j] < key := 4 > 3
            ara[j+1] = ara[j] := {4, 4, 5, 6, 2, 1}

    j = -1: exit inner loop
            ara[j+1] = key := {3, 4, 5, 6, 2, 1}

i = 4: key = 2
    {[3, 4, 5, 6, 2], 1}
    j = 3: ara[j] < key := 6 > 2 
            ara[j+1] = ara[j] := {3, 4, 5, 6, 6, 1}
    j = 2: ara[j] < key := 5 > 2
            ara[j+1] = ara[j] := {3, 4, 5, 5, 6, 1}
    j = 1: ara[j] < key := 4 > 2
            ara[j+1] = ara[j] := {3, 4, 4, 5, 6, 1}
    j = 0: ara[j] < key := 3 > 2
            ara[j+1] = ara[j] := {3, 3, 4, 5, 6, 1}

    j = -1: exit inner loop
            ara[j+1] = key := {2, 3, 4, 5, 6, 1}

i = 5: key = 1
    {[2, 3, 4, 5, 6, 1]}
    j = 4: ara[j] < key := 6 > 1 
            ara[j+1] = ara[j] := {2, 3, 4, 5, 6, 6}
    j = 3: ara[j] < key := 5 > 1
            ara[j+1] = ara[j] := {2, 3, 4, 5, 5, 6}
    j = 2: ara[j] < key := 4 > 1
            ara[j+1] = ara[j] := {2, 3, 4, 4, 5, 6}
    j = 1: ara[j] < key := 3 > 1
            ara[j+1] = ara[j] := {2, 3, 3, 4, 5, 6}
    j = 0: ara[j] < key := 2 > 1
            ara[j+1] = ara[j] := {2, 2, 3, 4, 5, 6}

    j = -1: exit inner loop
            ara[j+1] = key := {1, 2, 3, 4, 5, 6}

No more elements to iterate.

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

i = 1: key = 1
    {[1, 3], 6, 2, 5, 4}
    j = 0: ara[j] < key := 3 > 1 
            ara[j+1] = ara[j] := {1, 3, 3, 2, 5, 4}

    j = -1: exit inner loop
            ara[j+1] = key := {1, 3, 6, 2, 5, 4}

i = 2: key = 6
    {[1, 3, 6], 2, 5, 4}
    j = 2: ara[j] < key := 6 = 6 
            does not enter inner loop

i = 3: key = 2
    {[1, 3, 6, 2], 5, 4}
    j = 2: ara[j] < key := 6 > 2 
            ara[j+1] = ara[j] := {1, 3, 6, 6, 5, 4}
    j = 1: ara[j] < key := 3 > 2
            ara[j+1] = ara[j] := {1, 3, 3, 6, 5, 4}
    j = 0: ara[j] < key := 1 < 2
            inner loop breaks
            
            ara[j+1] = key := {1, 2, 3, 6, 5, 4}

i = 4: key = 5
    {[1, 2, 3, 6, 5], 4}
    j = 3: ara[j] < key := 6 > 5 
            ara[j+1] = ara[j] := {1, 2, 3, 6, 6, 4}
    j = 2: ara[j] < key := 3 < 5
            inner loop breaks

            ara[j+1] = key := {1, 2, 3, 5, 6, 4}

i = 5: key = 4
    {[1, 2, 3, 5, 6, 4]}
    j = 4: ara[j] < key := 6 > 4 
            ara[j+1] = ara[j] := {1, 2, 3, 5, 6, 6}
    j = 3: ara[j] < key := 5 > 4
            ara[j+1] = ara[j] := {1, 2, 3, 5, 5, 6}
    j = 2: ara[j] < key := 3 < 4
            inner loop breaks

            ara[j+1] = key := {1, 2, 3, 4, 5, 6}

No more elements to iterate.

Output: {1, 2, 3, 4, 5, 6}

            Array length = 6
        Total iterations = 10
                         = (1/2) * 6 * (6-1) - 5

            General Case = (1/2) * n * (n-1) - m
                    [where `m' depends on how much sorted the array is]

```