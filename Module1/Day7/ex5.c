#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchByName(struct Student members[], int size, const char* name) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(members[i].name, name) == 0) {
            printf("Member found:\n");
            printf("Roll No: %d\n", members[i].rollno);
            printf("Name: %s\n", members[i].name);
            printf("Marks: %.2f\n\n", members[i].marks);
            found = 1;
        }
    }

    if (!found) {
        printf("Member with name '%s' not found.\n", name);
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

    char searchName[20];
    printf("\nEnter the name to search: ");
    scanf("%s", searchName);

    searchByName(members, size, searchName);

    return 0;
}
