#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        // Prevent potential integer overflow compared to (left + right) / 2
        int mid = left + (right - left) / 2; 

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    // Target not found
    return -1; 
}

int main() {
    // Array MUST be sorted for Binary Search
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, 0, size - 1, target);

    if (result != -1) {
        printf("Binary Search: Element %d found at index %d\n", target, result);
    } else {
        printf("Binary Search: Element %d not found\n", target);
    }

    return 0;
}