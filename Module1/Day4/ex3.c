#include <stdio.h>

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        // Swap elements at start and end indices
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move start towards the right and end towards the left
        start++;
        end--;
    }
}

int main() {
    int myArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    // Reverse the array based on specified steps
    for (int i = 0; i < size / 2; i++) {
        // Swap the elements based on current step
        reverseArray(myArray, i, size - i - 1);

        printf("After step %d: ", i + 1);
        for (int j = 0; j < size; j++) {
            printf("%d ", myArray[j]);
        }
        printf("\n");
    }

    printf("\nFinal Reversed Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }

    return 0;
}
