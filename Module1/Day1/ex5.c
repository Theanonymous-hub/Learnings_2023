#include <stdio.h>

int bit_operations(int num, int oper_type) {
    switch (oper_type) {
        case 1:
            num |= 1;   // Set 1st bit
            break;
        case 2:
            num &= ~(1 << 31);  // Clear 31st bit
            break;
        case 3:
            num ^= (1 << 15);  // Toggle 16th bit
            break;
        default:
            printf("Error: Invalid operation type.\n");
            break;
    }

    return num;
}

int main() {
    int number, operation_type;

    printf("Enter the number: ");
    scanf("%d", &number);

    printf("Enter the operation type (1, 2, or 3): ");
    scanf("%d", &operation_type);

    int result = bit_operations(number, operation_type);

    printf("Result: %d\n", result);

    return 0;
}
