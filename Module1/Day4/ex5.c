#include <stdio.h>

int main() {
    int numbers[] = {64, 84, 21, 36, 17, 90, 77, 10, 48, 55};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Odd indexed elements: ");
    int sumOdd = 0;
    for (int i = 1; i < size; i += 2) {
        printf("%d ", numbers[i]);
        sumOdd += numbers[i];
    }
    printf("\n");

    printf("Even indexed elements: ");
    int sumEven = 0;
    for (int i = 0; i < size; i += 2) {
        printf("%d ", numbers[i]);
        sumEven += numbers[i];
    }
    printf("\n");

    printf("Sum of even indexed elements: %d\n", sumEven);
    printf("Sum of odd indexed elements: %d\n", sumOdd);

    return 0;
}
