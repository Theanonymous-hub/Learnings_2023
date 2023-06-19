#include <stdio.h>

int main() {
    int arr[10];
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Enter %d elements of the array:\n", length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
