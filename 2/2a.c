#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 200
#define MAX_NUMBERS 20

// Check if differences between adjacent numbers are between 1 and 3
bool checkDifferences(int numbers[], int count) {
    for (int i = 1; i < count; i++) {
        int diff = abs(numbers[i] - numbers[i-1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

// Check if sequence is consistently increasing or decreasing
bool checkDirection(int numbers[], int count) {
    if (count <= 1) return true;
    
    bool increasing = numbers[1] > numbers[0];
    
    for (int i = 2; i < count; i++) {
        if (increasing && numbers[i] <= numbers[i-1]) {
            return false;
        }
        if (!increasing && numbers[i] >= numbers[i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    FILE *file = fopen("2a-input.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    char line[MAX_LINE];
    int safeCount = 0;

    while (fgets(line, sizeof(line), file)) {
        int numbers[MAX_NUMBERS];
        int count = 0;
        char *token = strtok(line, " \n");
        
        // Parse numbers from line
        while (token != NULL && count < MAX_NUMBERS) {
            numbers[count++] = atoi(token);
            token = strtok(NULL, " \n");
        }

        // Check if sequence is safe
        if (checkDifferences(numbers, count) && checkDirection(numbers, count)) {
            safeCount++;
        }
    }

    printf("Number of safe reports: %d\n", safeCount);
    fclose(file);
    return 0;
}
