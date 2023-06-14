#include <stdio.h>

void printExponent(double num) {
    unsigned long long* p = (unsigned long long*) &num; // Treat the memory of 'num' as an unsigned long long

    unsigned long long exponent = (*p >> 52) & 0x7FF; // Extract the exponent bits

    // Print the exponent in hexadecimal and binary format
    printf("Exponent in hexadecimal: 0x%llX\n", exponent);
    printf("Exponent in binary: 0b");
    for (int i = 11; i >= 0; --i) {
        printf("%d", (exponent >> i) & 0x01);
    }
    printf("\n");
}

int main() {
    double x;

    printf("Enter a double value: ");
    scanf("%lf", &x);

    printExponent(x);

    return 0;
}
