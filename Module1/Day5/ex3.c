#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long computeTotalSeconds(const char* timeString) {
    char* token;
    char* rest = strdup(timeString);

    unsigned long hours = 0, minutes = 0, seconds = 0;

    // Tokenize the timeString using ":"
    token = strtok(rest, ":");
    if (token != NULL) {
        hours = strtoul(token, NULL, 10);
    }

    token = strtok(NULL, ":");
    if (token != NULL) {
        minutes = strtoul(token, NULL, 10);
    }

    token = strtok(NULL, ":");
    if (token != NULL) {
        seconds = strtoul(token, NULL, 10);
    }

    free(rest);

    unsigned long totalSeconds = hours * 3600 + minutes * 60 + seconds;

    return totalSeconds;
}

int main() {
    const char* timeString1 = "10:12:50";
    unsigned long totalSeconds1 = computeTotalSeconds(timeString1);
    printf("Total Seconds: %lu\n", totalSeconds1);

    const char* timeString2 = "13:45:40";
    unsigned long totalSeconds2 = computeTotalSeconds(timeString2);
    printf("Total Seconds: %lu\n", totalSeconds2);

    return 0;
}
