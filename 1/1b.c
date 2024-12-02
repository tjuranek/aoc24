#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10000
#define MAX_VALUE 100000  // Assuming numbers won't be larger than this

// Count occurrences of a number in an array
int count_occurrences(int number, int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            count++;
        }
    }
    return count;
}

int main() {
    FILE *file = fopen("1b-input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int left[MAX_NUMBERS], right[MAX_NUMBERS];
    int count = 0;
    
    // Read numbers from file
    while (fscanf(file, "%d %d", &left[count], &right[count]) == 2) {
        count++;
    }
    fclose(file);

    // Calculate similarity score
    long long total = 0;
    for (int i = 0; i < count; i++) {
        int number = left[i];
        int occurrences = count_occurrences(number, right, count);
        total += (long long)number * occurrences;
    }

    printf("Similarity score: %lld\n", total);
    return 0;
} 