/**
 * @file Insertion_Sort.c
 * @brief Implementation of Insertion Sort Algorithm
 * 
 * @author AMEY MAHENDRA THAKUR
 * @repository https://github.com/Amey-Thakur/ANALYSIS-OF-ALGORITHM-AND-ANALYSIS-OF-ALGORITHM-LAB
 * 
 * Experiment No. 1: Analysis of Insertion Sort
 */

#include <stdio.h>

/**
 * @brief Performs Insertion Sort on an array
 * @param arr The array to be sorted
 * @param n The number of elements in the array
 */
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i]; // The element to be inserted into the sorted sequence
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than key, 
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Place the key at its correct position
    }
}

/**
 * @brief Utility function to print an array
 * @param arr The array to be printed
 * @param n The number of elements in the array
 */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    int arr[100];

    printf("\t--- INSERTION SORT ---\t\n");

    printf("\nEnter the number of elements: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n > 100 || n <= 0) {
        printf("Please enter a number between 1 and 100.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal list: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted list using Insertion Sort: ");
    printArray(arr, n);

    return 0;
}
