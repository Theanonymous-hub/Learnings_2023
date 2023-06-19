#include <stdio.h>
#include <ctype.h>

void toggleCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char inputString[] = "Hello World";
    char outputString[100];

    toggleCase(inputString);
    printf("Output String: %s\n", inputString);

    // Additional examples
    char example1[] = "hELLO wORLD";
    toggleCase(example1);
    printf("Output String: %s\n", example1);

    char example2[] = "A+B";
    toggleCase(example2);
    printf("Output String: %s\n", example2);

    char example3[] = "a+b";
    toggleCase(example3);
    printf("Output String: %s\n", example3);

    char example4[] = "Prog4upROG4U";
    toggleCase(example4);
    printf("Output String: %s\n", example4);

    return 0;
}
