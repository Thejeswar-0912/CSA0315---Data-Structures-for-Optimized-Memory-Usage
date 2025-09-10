#include <stdio.h>
int main() {
    int arr[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d is Even\n", arr[i]);
        } else {
            printf("%d is Odd\n", arr[i]);
        }
    }
    return 0;
}
