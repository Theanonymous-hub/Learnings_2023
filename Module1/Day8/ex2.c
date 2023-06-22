#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

// Function to convert content to uppercase
void convertToUpper(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

// Function to convert content to lowercase
void convertToLower(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

// Function to convert content to sentence case
void convertToSentenceCase(char *str) {
    int isFirstChar = 1;
    while (*str) {
        if (isFirstChar && islower((unsigned char)*str)) {
            *str = toupper((unsigned char)*str);
        } else if (!isFirstChar && isupper((unsigned char)*str)) {
            *str = tolower((unsigned char)*str);
        }

        isFirstChar = (*str == '.' || *str == '?' || *str == '!') ? 1 : 0;
        str++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <option> <source_file> <destination_file>\n", argv[0]);
        printf("Options:\n");
        printf("-u\tConvert content to uppercase\n");
        printf("-l\tConvert content to lowercase\n");
        printf("-s\tConvert content to sentence case\n");
        return EXIT_FAILURE;
    }

    char *option = argv[1];
    char *sourcePath = argv[2];
    char *destinationPath = argv[3];

    FILE *sourceFile, *destinationFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead, bytesWritten;

    // Open the source file in read mode
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return EXIT_FAILURE;
    }

    // Open the destination file in write mode
    destinationFile = fopen(destinationPath, "w");
    if (destinationFile == NULL) {
        printf("Failed to open the destination file.\n");
        fclose(sourceFile);
        return EXIT_FAILURE;
    }

    // Copy the contents of the source file to the destination file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (strcmp(option, "-u") == 0) {
            convertToUpper(buffer);
        } else if (strcmp(option, "-l") == 0) {
            convertToLower(buffer);
        } else if (strcmp(option, "-s") == 0) {
            convertToSentenceCase(buffer);
        }

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