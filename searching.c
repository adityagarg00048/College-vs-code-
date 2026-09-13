#include <stdio.h>

int main() {
    int arr[] = {15, 23, 7, 45, 89, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 45;
    int found_index = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        printf("Element %d found at index %d\n", target, found_index);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}