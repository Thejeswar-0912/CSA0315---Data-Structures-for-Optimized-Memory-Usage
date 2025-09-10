#include <stdio.h>

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[50] = {1, 2, 3, 4, 5};
    int n = 5, pos, val, i;

    printf("Original array: ");
    display(arr, n);

    // Insertion
    pos = 3; val = 10;
    for (i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = val;
    n++;
    printf("After insertion: ");
    display(arr, n);

    // Deletion
    pos = 4;
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("After deletion: ");
    display(arr, n);

    return 0;
}
