#include <stdio.h>

int main() {
    int arr[100], n, i, key, low, high, mid;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high) {
        if (arr[mid] < key)
            low = mid + 1;
        else if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            break;
        } else
            high = mid - 1;
        mid = (low + high) / 2;
    }

    if (low > high)
        printf("Element not found\n");
        
    return 0;
}
