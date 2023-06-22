#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *sourceFile, *destinationFile;
    char sourcePath[100], destinationPath[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead, bytesWritten;

    // Get the source file path from the user
    printf("Enter the path of the source file: ");
    scanf("%s", sourcePath);

    // Open the source file in read mode
    sourceFile = fopen(sourcePath, "rb");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return EXIT_FAILURE;
    }

    // Get the destination file path from the user
    printf("Enter the path of the destination file: ");
    scanf("%s", destinationPath);

    // Open the destination file in write mode
    destinationFile = fopen(destinationPath, "wb");
    if (destinationFile == NULL) {
        printf("Failed to open the destination file.\n");
        fclose(sourceFile);
        return EXIT_FAILURE;
    }

    // Copy the contents of the source file to the destination file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        bytesWritten = fwrite(buffer, 1, bytesRead, destinationFile);
        if (bytesWritten != bytesRead) {
            printf("Error occurred while writing to the destination file.\n");
            fclose(sourceFile);
            fclose(destinationFile);
            return EXIT_FAILURE;
        }
    }

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");

    return EXIT_SUCCESS;
}