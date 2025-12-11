#include <iostream>
using namespace std;

void binarySearch(int arr[], int n, int target, int& index) {
    int left = 0;
    int right = n - 1;
    index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            index = mid;
            break;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
}

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 22;
    int index;

    binarySearch(arr, n, target, index);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
       cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
