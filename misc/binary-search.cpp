#include <iostream>

using namespace std;

int binary_search(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (right + left) / 2;

        if (arr[mid] > target) {
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int binary_search_rec(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = (right + left) / 2;

    if (arr[mid] > target) {
        return binary_search_rec(arr, left, mid - 1, target);
    } else if (arr[mid] < target) {
        return binary_search_rec(arr, mid + 1, right, target);
    } else {
        return mid;
    }
}

int main() {
    int n; cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target; cin >> target;

    int index = binary_search(arr, n, target);

    if (index == -1) {
        cout << target << " is not found in the array\n";
    } else {
        cout << target << " is found at index " << index << endl;
    }

    int index_rec = binary_search_rec(arr, 0, n - 1, target);

    if (index_rec == -1) {
        cout << target << " is not found in the array\n";
    } else {
        cout << target << " is found at index " << index_rec << endl;
    }

    return 0;
}