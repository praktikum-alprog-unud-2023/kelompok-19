#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to sort an array
void sortArray(int *arr, int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                // Swap values if arr[i] > arr[j]
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to calculate mean
double calculateMean(int *arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate median
double calculateMedian(int *arr, int n) {
    // If the number of data is odd, return the middle value
    if (n % 2 != 0) {
        return arr[n / 2];
    }
    // If the number of data is even, return the average of the two middle values
    else {
        return (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
    }
}

// Function to calculate mode
void calculateMode(int *arr, int n) {
    int mode = arr[0];
    int count = 1;
    int maxCount = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }

    printf("Mode: %d\n", mode);
}

int main() {
    int n;

    // Input the number of data
    printf("Enter the number of data: ");
    scanf("%d", &n);

    int *data = (int *)malloc(n * sizeof(int));

    // Input data
    printf("Enter data:\n");
    for (int i = 0; i < n; i++) {
        printf("Data %d: ", i + 1);
        scanf("%d", &data[i]);
    }

    // Sort the array
    sortArray(data, n);

    // Calculate and display mean
    double mean = calculateMean(data, n);
    printf("Mean: %.2f\n", mean);

    // Calculate and display median
    double median = calculateMedian(data, n);
    printf("Median: %.2f\n", median);

    // Calculate and display mode
    calculateMode(data, n);

    // Free allocated memory
    free(data);

    return 0;
}

