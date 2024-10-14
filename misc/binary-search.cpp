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

    return 0;
}