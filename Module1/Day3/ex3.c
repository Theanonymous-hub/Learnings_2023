#include <stdio.h>

int findLargestAfterDeletion(int num)
{
    int largest = 0;
    int divisor = 1;

    while (divisor <= num)
    {
        int tempNum = (num / (divisor * 10)) * divisor + (num % divisor);
        if (tempNum > largest)
            largest = tempNum;
        
        divisor *= 10;
    }

    return largest;
}

int main()
{
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestNum = findLargestAfterDeletion(num);
    printf("Largest number after deleting a single digit: %d\n", largestNum);

    return 0;
}
