#include <stdio.h>
#include <stdlib.h>

// Define the structure for a student
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array of students
    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    // Read data for each student
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]s", students[i].name);

        printf("Enter roll number: ");
        scanf("%d", &(students[i].rollNumber));

        printf("Enter marks: ");
        scanf("%f", &(students[i].marks));
    }

    // Display data for each student
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nDetails for Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
