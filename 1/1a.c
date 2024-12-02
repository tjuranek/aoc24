#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10000

void sort(int arr[], int n) {
    // Simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *file = fopen("1a-input.txt", "r");
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

    // Sort both arrays
    sort(left, count);
    sort(right, count);

    // Calculate total distance
    long long total = 0;
    for (int i = 0; i < count; i++) {
        total += abs(left[i] - right[i]);
    }

    printf("Total distance: %lld\n", total);
    return 0;
}
