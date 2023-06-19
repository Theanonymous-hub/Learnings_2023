#include <stdio.h>

int stringToInteger(const char* str) {
    int res = 0;
    int i = 0;

    while (str[i] != '\0') {
        int ival = str[i] - '0';  // Convert character to integer value
        res = res * 10 + ival;
        i++;
    }

    return res;
}

int main() {
    char inputString[] = "5278";
    int result = stringToInteger(inputString);

    printf("Converted Integer: %d\n", result);

    return 0;
}
