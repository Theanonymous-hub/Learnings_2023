#include <stdio.h>

int main() {
    int numbers[] = {10,20,30,40,9};
    int evenSum = 0;
    int oddSum = 0;
    int length = sizeof(numbers) / sizeof(numbers[0]);
    
    for (int i = 0; i < length; i++) {
        if (numbers[i] % 2 == 0) {
            evenSum += numbers[i];
        } else {
            oddSum += numbers[i];
        }
    }
    
    printf("Sum of even elements: %d\n", evenSum);
    printf("Sum of odd elements: %d\n", oddSum);
    
    return 0;
}
