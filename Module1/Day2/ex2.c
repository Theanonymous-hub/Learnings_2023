#include <stdio.h>
#include <string.h>

void swap(void* ptr1, void* ptr2, size_t size) {
    char temp[size];
    memcpy(temp, ptr1, size);
    memcpy(ptr1, ptr2, size);
    memcpy(ptr2, temp, size);
}

int main() {
    int int1, int2;
    printf("Enter the first integer: ");
    scanf("%d", &int1);
    printf("Enter the second integer: ");
    scanf("%d", &int2);

    printf("Before swap: int1 = %d, int2 = %d\n", int1, int2);
    swap(&int1, &int2, sizeof(int));
    printf("After swap: int1 = %d, int2 = %d\n", int1, int2);

    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("Before swap: str1 = %s, str2 = %s\n", str1, str2);
    swap(str1, str2, strlen(str1) + 1);
    printf("After swap: str1 = %s, str2 = %s\n", str1, str2);

    return 0;
}
