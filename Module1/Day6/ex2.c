#include <stdio.h>

// Define the structure for a complex number
struct Complex {
    double real;
    double imag;
};

// Function to read a complex number from the user
void readComplex(struct Complex* c) {
    printf("Enter the real part: ");
    scanf("%lf", &(c->real));

    printf("Enter the imaginary part: ");
    scanf("%lf", &(c->imag));
}

// Function to write a complex number to the console
void writeComplex(struct Complex c) {
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imag);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main() {
    struct Complex num1, num2, sum, product;

    printf("Reading the first complex number:\n");
    readComplex(&num1);

    printf("\nReading the second complex number:\n");
    readComplex(&num2);

    printf("\n");

    printf("The first complex number is: ");
    writeComplex(num1);

    printf("The second complex number is: ");
    writeComplex(num2);

    printf("\n");

    // Addition of complex numbers
    sum = addComplex(num1, num2);
    printf("Addition of the two complex numbers: ");
    writeComplex(sum);

    // Multiplication of complex numbers
    product = multiplyComplex(num1, num2);
    printf("Multiplication of the two complex numbers: ");
    writeComplex(product);

    return 0;
}
