#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayMembers(struct Student members[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Member %d:\n", i + 1);
        printf("Roll No: %d\n", members[i].rollno);
        printf("Name: %s\n", members[i].name);
        printf("Marks: %.2f\n\n", members[i].marks);
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student members[size];

    for (int i = 0; i < size; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &members[i].rollno);
        printf("Name: ");
        scanf("%s", members[i].name);
        printf("Marks: ");
        scanf("%f", &members[i].marks);
    }

    displayMembers(members, size);

    return 0;
}
