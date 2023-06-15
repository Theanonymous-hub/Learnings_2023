#include <stdio.h>

void printBits(unsigned int num)
{
    int i;
    unsigned int mask = 1 << 31;  // Start with the leftmost bit

    for (i = 0; i < 32; i++)
    {
        // Print the current bit (0 or 1)
        printf("%d", (num & mask) != 0);

        // Shift the mask to the right by 1
        mask >>= 1;

        // Print a space after every 8 bits for readability
        if ((i + 1) % 8 == 0)
            printf(" ");
    }

    printf("\n");
}

int main()
{
    unsigned int num;

    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Bits: ");
    printBits(num);

    return 0;
}
