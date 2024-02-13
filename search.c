#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1;
}

void insertElement(int arr[], int *size, int element, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void updateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            arr[i] += 5;
        } else {
            arr[i] *= 2;
        }
    }
}

void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int size, choice, element, position, key;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n1. Linear Search\n2. Insert Element\n3. Delete Element\n4. Reverse Array\n5. Update Array\n6. Display Array\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                position = linearSearch(arr, size, key);
                if (position != -1) {
                    printf("Element found at index: %d\n", position);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertElement(arr, &size, element, position);
                printf("Element inserted successfully.\n");
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                printf("Element deleted successfully.\n");
                break;
            case 4:
                reverseArray(arr, size);
                printf("Array reversed successfully.\n");
                break;
            case 5:
                updateArray(arr, size);
                printf("Array updated successfully.\n");
                break;
            case 6:
                displayArray(arr, size);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
