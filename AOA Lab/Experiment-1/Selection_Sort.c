/**
 * @file Selection_Sort.c
 * @brief Implementation of Selection Sort Algorithm
 * 
 * @author AMEY MAHENDRA THAKUR
 * @repository https://github.com/Amey-Thakur/ANALYSIS-OF-ALGORITHM-AND-ANALYSIS-OF-ALGORITHM-LAB
 * 
 * Experiment No. 1: Analysis of Selection Sort
 */

#include <stdio.h>

/**
 * @brief Swaps two integers
 * @param a Pointer to first integer
 * @param b Pointer to second integer
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Performs Selection Sort on an array
 * @param arr The array to be sorted
 * @param n The number of elements in the array
 */
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
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

    printf("\t--- SELECTION SORT ---\t\n");

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

    selectionSort(arr, n);

    printf("Sorted list using Selection Sort: ");
    printArray(arr, n);

    return 0;
}
