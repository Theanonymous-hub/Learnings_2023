#include <stdio.h>

int findMaxUsingIfElse(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int findMaxUsingTernaryOperator(int num1, int num2) {
    int max = (num1 > num2) ? num1 : num2;
    return max;
}

int main() {
    int num1, num2;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    int maxIfElse = findMaxUsingIfElse(num1, num2);
    printf("Max using if-else: %d\n", maxIfElse);
    
    int maxTernaryOperator = findMaxUsingTernaryOperator(num1, num2);
    printf("Max using ternary operator: %d\n", maxTernaryOperator);
    
    return 0;
}