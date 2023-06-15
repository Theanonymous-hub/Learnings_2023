#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

void findSmallestAndLargestDigits(int n, ...)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int num, temp;

    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++)
    {
        num = va_arg(args, int);
        temp = num;

        while (temp != 0)
        {
            int digit = temp % 10;

            if (digit < smallest)
                smallest = digit;

            if (digit > largest)
                largest = digit;

            temp /= 10;
        }
    }

    va_end(args);

    if (smallest == INT_MAX || largest == INT_MIN)
    {
        printf("Not Valid\n");
    }
    else
    {
        printf("Smallest digit: %d\n", smallest);
        printf("Largest digit: %d\n", largest);
    }
}

int main()
{
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    int values[n];
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &values[i]);
    }

    findSmallestAndLargestDigits(n, values[0], values[1], values[2]);

    return 0;
}
