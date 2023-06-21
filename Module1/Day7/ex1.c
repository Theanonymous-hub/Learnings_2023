#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int numStudents) {
    const char* delimiter = " ";
    char* token;
    int i = 0;

    // Make a copy of the input string to avoid modifying the original
    char* inputCopy = strdup(input);

    // Tokenize the input string and initialize the structures
    token = strtok(inputCopy, delimiter);
    while (token != NULL && i < numStudents) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, delimiter);
        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';

        token = strtok(NULL, delimiter);
        students[i].marks = atof(token);

        i++;
        token = strtok(NULL, delimiter);
    }

    free(inputCopy); // Free the memory allocated for the input copy
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar(); // Clear the newline character from the input buffer

    struct Student* students = malloc(numStudents * sizeof(struct Student));

    printf("Enter student data (rollno name marks) separated by spaces:\n");

    for (int i = 0; i < numStudents; i++) {
        char input[1000];
        fgets(input, sizeof(input), stdin);

        // Remove the trailing newline character if present
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        parseString(input, &students[i], 1);
    }

    // Print the parsed data for verification
    printf("\nParsed student data:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    free(students); // Free the memory allocated for the student array

    return 0;
}
