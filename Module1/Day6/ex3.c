#include <stdio.h>

// Define the structure for a time period
struct TimePeriod {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct TimePeriod calculateDifference(struct TimePeriod t1, struct TimePeriod t2) {
    struct TimePeriod diff;

    // Convert both time periods to seconds
    int totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Calculate the absolute difference in seconds
    int diffSeconds = totalSeconds1 - totalSeconds2;
    if (diffSeconds < 0) {
        diffSeconds = -diffSeconds;
    }

    // Convert the difference back to hours, minutes, and seconds
    diff.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    diff.minutes = diffSeconds / 60;
    diff.seconds = diffSeconds % 60;

    return diff;
}

int main() {
    struct TimePeriod t1, t2, difference;

    // Read the first time period from the user
    printf("Enter the first time period:\n");
    printf("Hours: ");
    scanf("%d", &t1.hours);
    printf("Minutes: ");
    scanf("%d", &t1.minutes);
    printf("Seconds: ");
    scanf("%d", &t1.seconds);

    // Read the second time period from the user
    printf("\nEnter the second time period:\n");
    printf("Hours: ");
    scanf("%d", &t2.hours);
    printf("Minutes: ");
    scanf("%d", &t2.minutes);
    printf("Seconds: ");
    scanf("%d", &t2.seconds);

    // Calculate the difference between the two time periods
    difference = calculateDifference(t1, t2);

    // Display the difference
    printf("\nDifference: %d hours, %d minutes, %d seconds\n",
           difference.hours, difference.minutes, difference.seconds);

    return 0;
}
