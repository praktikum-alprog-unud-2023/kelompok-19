#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 1000
int getRandomNumber() {
    return rand() % 1000 + 1;
}

// Function to fill an array with random numbers
void fillArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = getRandomNumber();
    }
}

// Function to display the contents of an array
void displayArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to perform a regular bubble sort
void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap values if array[j] > array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to perform a bubble sort with pointers
void bubbleSortWithPointer(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(array + j) > *(array + j + 1)) {
                // Swap values if array[j] > array[j + 1]
                int temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Number of data
    int size1 = 1000;
    int size2 = 16000;
    int size3 = 64000;

    // Arrays to store data
    int array1[size1];
    int array2[size2];
    int array3[size3];

    // Fill arrays with random numbers
    fillArray(array1, size1);
    fillArray(array2, size2);
    fillArray(array3, size3);

    // Sorting and measuring time using regular bubble sort
    start = clock();
    bubbleSort(array1, size1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for Regular Bubble Sort (n=1000): %f seconds\n", cpu_time_used);

    start = clock();
    bubbleSort(array2, size2);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for Regular Bubble Sort (n=16000): %f seconds\n", cpu_time_used);

    start = clock();
    bubbleSort(array3, size3);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for Regular Bubble Sort (n=64000): %f seconds\n", cpu_time_used);

    // Refill arrays with random numbers
    fillArray(array1, size1);
    fillArray(array2, size2);
    fillArray(array3, size3);

    // Sorting and measuring time using bubble sort with pointers
    start = clock();
    bubbleSortWithPointer(array1, size1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for Bubble Sort with Pointers (n=1000): %f seconds\n", cpu_time_used);

    start = clock();
    bubbleSortWithPointer(array2, size2);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for Bubble Sort with Pointers (n=16000): %f seconds\n", cpu_time_used);

    start = clock();
    bubbleSortWithPointer(array3, size3);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for Bubble Sort with Pointers (n=64000): %f seconds\n", cpu_time_used);

    return 0;
}
