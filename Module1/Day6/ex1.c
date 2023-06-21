#include <stdio.h>

// Define the structure for a box
struct Box {
    double length;
    double width;
    double height;
};

// Function to calculate the volume of the box
double calculateVolume(struct Box* box) {
    return box->length * box->width * box->height;
}

// Function to calculate the total surface area of the box
double calculateSurfaceArea(struct Box* box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    // Create an instance of the Box structure
    struct Box myBox;

    // Prompt the user to enter the dimensions of the box
    printf("Enter the length of the box: ");
    scanf("%lf", &myBox.length);

    printf("Enter the width of the box: ");
    scanf("%lf", &myBox.width);

    printf("Enter the height of the box: ");
    scanf("%lf", &myBox.height);

    // Create a pointer to the Box structure and initialize it to point to myBox
    struct Box* ptrBox = &myBox;

    // Calculate the volume using the structure pointer
    double volume = calculateVolume(ptrBox);
    printf("Volume of the box: %.2f\n", volume);

    // Calculate the total surface area using the structure pointer
    double surfaceArea = calculateSurfaceArea(ptrBox);
    printf("Total surface area of the box: %.2f\n", surfaceArea);

    return 0;
}
