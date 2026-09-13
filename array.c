
#include <stdio.h>

void traverse(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int size, int element, int capacity, int index) {
    if (size >= capacity) {
        printf("Array is full. Insertion failed.\n");
        return size;
    }
    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return size + 1;
}

int delete(int arr[], int size, int index) {
    if (index >= size || index < 0) {
        printf("Invalid index. Deletion failed.\n");
        return size;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;

    traverse(arr, size);
    
    // Insert 25 at index 2
    size = insert(arr, size, 25, 100, 2);
    printf("After Insertion:\n");
    traverse(arr, size);

    // Delete element at index 3
    size = delete(arr, size, 3);
    printf("After Deletion:\n");
    traverse(arr, size);

    return 0;
}