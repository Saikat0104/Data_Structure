#include <iostream>

using namespace std;


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 22;
    int foundIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        cout << "Element " << target << " found at index " << foundIndex << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
