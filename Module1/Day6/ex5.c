#include <stdio.h>
#include <string.h>

// Define the structure for a student
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

// Function to swap the fields of two student structures using pointers
void swapFields(struct Student* s1, struct Student* s2) {
    struct Student temp;

    // Swap the name field
    strcpy(temp.name, s1->name);
    strcpy(s1->name, s2->name);
    strcpy(s2->name, temp.name);

    // Swap the rollNumber field
    int rollNumberTemp = s1->rollNumber;
    s1->rollNumber = s2->rollNumber;
    s2->rollNumber = rollNumberTemp;

    // Swap the marks field
    float marksTemp = s1->marks;
    s1->marks = s2->marks;
    s2->marks = marksTemp;
}

int main() {
    // Create two student structures
    struct Student student1;
    struct Student student2;

    // Input data for student 1
    printf("Enter details for Student 1:\n");
    printf("Name: ");
    scanf("%s", student1.name);
    printf("Roll Number: ");
    scanf("%d", &student1.rollNumber);
    printf("Marks: ");
    scanf("%f", &student1.marks);

    // Input data for student 2
    printf("\nEnter details for Student 2:\n");
    printf("Name: ");
    scanf("%s", student2.name);
    printf("Roll Number: ");
    scanf("%d", &student2.rollNumber);
    printf("Marks: ");
    scanf("%f", &student2.marks);

    printf("\nBefore swapping:\n");
    printf("Student 1: %s, Roll Number: %d, Marks: %.2f\n", student1.name, student1.rollNumber, student1.marks);
    printf("Student 2: %s, Roll Number: %d, Marks: %.2f\n", student2.name, student2.rollNumber, student2.marks);

    // Swap the fields of the two student structures
    swapFields(&student1, &student2);

    printf("\nAfter swapping:\n");
    printf("Student 1: %s, Roll Number: %d, Marks: %.2f\n", student1.name, student1.rollNumber, student1.marks);
    printf("Student 2: %s, Roll Number: %d, Marks: %.2f\n", student2.name, student2.rollNumber, student2.marks);

    return 0;
}
