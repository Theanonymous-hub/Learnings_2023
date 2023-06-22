#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[3];
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
};

void extractDataFromFile(const char *filename, struct LogEntry logEntries[], int *numEntries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    // Read and skip the header line
    char header[100];
    fgets(header, sizeof(header), file);

    // Read each line and extract the data
    *numEntries = 0;
    while (*numEntries < MAX_ENTRIES && fscanf(file, "%d,%[^,],%f,%d,%d,%s",
                                              &logEntries[*numEntries].entryNo,
                                              logEntries[*numEntries].sensorNo,
                                              &logEntries[*numEntries].temperature,
                                              &logEntries[*numEntries].humidity,
                                              &logEntries[*numEntries].light,
                                              logEntries[*numEntries].timestamp) == 6) {
        (*numEntries)++;
    }

    fclose(file);
}

void displayLogEntries(const struct LogEntry logEntries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].timestamp);
    }
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    extractDataFromFile("data.csv", logEntries, &numEntries);
    displayLogEntries(logEntries, numEntries);

    return 0;
}