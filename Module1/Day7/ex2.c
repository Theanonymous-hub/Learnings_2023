#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar(); // Clear the newline character from the input buffer

    struct Student* students = malloc(numStudents * sizeof(struct Student));

    initializeStudents(students, numStudents);

    // Input student details
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        getchar(); // Clear the newline character from the input buffer
        
        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove the newline character
        
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        getchar(); // Clear the newline character from the input buffer
    }

    // Print the initialized data for verification
    printf("\nInitialized student data:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    free(students); // Free the memory allocated for the student array

    return 0;
}
