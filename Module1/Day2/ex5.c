#include <stdio.h>
#include <string.h>

void encode(char *str) {
    int key = 7; // Encryption key

    // Iterate over each character of the string
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i] ^ key; // XOR operation with the key
    }
}

void decode(char *str) {
    int key = 7; // Decryption key

    // Call the encode function with the same key to decrypt
    encode(str);
}

int main() {
    char str[100];

    printf("Enter the string to encode: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the trailing newline character

    printf("Original string: %s\n", str);

    encode(str);
    printf("Encoded string: %s\n", str);

    decode(str);
    printf("Decoded string: %s\n", str);

    return 0;
}
