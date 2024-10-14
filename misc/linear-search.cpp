#include <iostream>

using namespace std;

int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
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

    int index = linear_search(arr, n, target);

    if (index == -1) {
        cout << target << " is not found in the array\n";
    } else {
        cout << target << " is found at index " << index << endl;
    }

    return 0;
}