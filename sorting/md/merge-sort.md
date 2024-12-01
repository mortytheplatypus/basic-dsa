# Merge Sort

### Algorithm
Merge sort is a `divide-and-conquer` algorithm that works as follows:

```
1. Divide the unsorted list into two halves.
2. Recursively sort each half.
3. Merge the two halves back together.
```

### Space Complexity
Merge sort requires a temporary array to store the merged array. Hence, the space complexity of merge sort is **$O(n)$**.
  

### Time Complexity
Merge sort shows consistent time complexities across all cases, and that is $O(nlogn)$.
\newpage

### Pseudocode  

```c
    void mergeSort(int ara[], int low, int high) {
        if (low == high) {
            return;
        }

        int mid = (low + high) / 2;

        mergeSort(ara, low, mid);
        mergeSort(ara, mid+1, high);

        merge(ara, low, mid, high);
    }

    void merge(int ara[], int low, int mid, int high) {
        int n = high-low+1, i = low, j = mid+1, k = 0; 
        int newAra[n]; 

        // merge the two halves
        for (k = 0; k < n; k++) {
            if (i <= mid && j <= high) {
                if (ara[i] < ara[j]) {
                    newAra[k] = ara[i++];
                } else {
                    newAra[k] = ara[j++];
                }
            } else if (i <= mid) {
                newAra[k] = ara[i++];
            } else {
                newAra[k] = ara[j++];
            }
        }

        // copy the merged array back to the original array
        for (k = 0; k < n; k++) {
            ara[low+k] = newAra[k]; 
        }
    }
```

\newpage

### Example
Performs the same across all cases with a time complexity of $O(nlogn)$. The following is an animation of the input array ${3, 1, 6, 8, 7, 2, 5, 4}$

```
Animation:
            {3, 1, 6, 8, 7, 2, 5, 4}
              /                   \
        {3, 1, 6, 8}         {7, 2, 5, 4}
         /        \           /        \
     {3, 1}     {6, 8}     {7, 2}    {5, 4}
      /  \       /  \       /  \       /  \
    {3}  {1}   {6}  {8}   {7}  {2}   {5}  {4}
     \    /     \    /     \    /     \    /
     {1, 3}     {6, 8}     {2, 7}    {4, 5}
        \          /         \          /
        {1, 3, 6, 8}         {2, 4, 5, 7}
              \                   /
            {1, 2, 3, 4, 5, 6, 7, 8} 

Recursion Stack:

    merge_sort({3, 1, 6, 8, 7, 2, 5, 4})
        merge_sort({3, 1, 6, 8})
            merge_sort({3, 1})
                merge_sort({3})
                merge_sort({1})

                merge({3}, {1}) -> {1, 3}

            merge_sort({6, 8})
                merge_sort({6})
                merge_sort({8})

                merge({6}, {8}) -> {6, 8}  

            merge({1, 3}, {6, 8}) -> {1, 3, 6, 8}

        merge_sort({7, 2, 5, 4})
            merge_sort({7, 2})
                merge_sort({7})
                merge_sort({2})

                merge({7}, {2}) -> {2, 7}

            merge_sort({5, 4})
                merge_sort({5})
                merge_sort({4})

                merge({5}, {4}) -> {4, 5}  

            merge({2, 7}, {4, 5}) -> {2, 4, 5, 7}

        merge({1, 3, 6, 8}, {2, 4, 5, 7}) -> {1, 2, 3, 4, 5, 6, 7, 8} 
```

### Time Complexity Analysis of Merge Sort


`merge` method: consists of two loops, the first for creating a temporary new array to store the sorted elements and the second for copying the sorted elements back to the original array

Hence, the time complexity of the `merge` method: $O(n)$ [where `n` is the number of elements in the array]

Let's say it is `kn` [where `k` is an arbitrary constant]

___  

`merge_sort` method: recursively divides the array into two halves and calls the `merge` method to merge the two halves

Assume, the time complexity of `merge_sort` method is $T(n)$ [where the input is an array `n` elements] 

```
    T(n) = 2T(n/2) + kn

         = 2(2T(n/4) + k(n/2)) + kn
         = 4T(n/4) + 2kn
         = 2^2T(n/2^2) + 2kn

         = 2^2(2T(n/2^3) + k(n/2^2)) + 2kn
         = 2^3T(n/2^3) + 2^2k(n/2^2) + 2kn
         = 2^3T(n/2^3) + 3kn

         ...

         = 2^iT(n/2^i) + ikn

    Here, 
        for base case, the subarray has only `1' element

        so, i is the smallest integer for which n/2^i <= 1 

        now,
                n <= 2^i
            =>  log(n) <= log(2^i)
            =>  log(n) <= i
            =>  i >= log(n)

    since, T(1) = O(1)

    T(n) = 2^iT(n/2^i) + ikn
         = 2^(log(n))T(1) + log(n)kn
         = nT(1) + log(n)kn [since 2^log(n) = n]
         = n + knlog(n)
         = O(nlog(n))

 ```   