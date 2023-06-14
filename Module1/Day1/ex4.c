#include <stdio.h>

int main() {
    float num1, num2;
    char operator;

    printf("Enter Number1: ");
    scanf("%f", &num1);

    printf("Enter the operator: ");
    scanf(" %c", &operator); 
    printf("Enter Number2: ");
    scanf("%f", &num2);

    switch (operator) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            else
                printf("Error: Division by zero is not allowed.\n");
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
    }

    return 0;
}
