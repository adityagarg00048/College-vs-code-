#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {15, 23, 7, 45, 89, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 45;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Linear Search: Element %d found at index %d\n", target, result);
    } else {
        printf("Linear Search: Element %d not found\n", target);
    }

    return 0;
}