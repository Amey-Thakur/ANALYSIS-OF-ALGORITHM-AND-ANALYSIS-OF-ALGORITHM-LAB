/**
 * @file Merge_Sort.c
 * @brief Implementation of Merge Sort Algorithm
 * 
 * @author AMEY MAHENDRA THAKUR
 * @repository https://github.com/Amey-Thakur/ANALYSIS-OF-ALGORITHM-AND-ANALYSIS-OF-ALGORITHM-LAB
 * 
 * Experiment No. 3: Analysis of Merge Sort
 */

#include <stdio.h>

/* Function Prototypes */
void printArray(int arr[], int size);
void divide(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

/**
 * @brief Main function to demonstrate Merge Sort
 */
int main() {
    int arr[100], n, i;

    printf("\t--- MERGE SORT ---\t\n");

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

    printf("\nOriginal array:\n");
    printArray(arr, n);

    // Sorting the array
    divide(arr, 0, n - 1);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}

/**
 * @brief Utility function to print an array
 * @param arr The array to be printed
 * @param size The number of elements in the array
 */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Recursively divides the array into two halves
 * @param arr The array to be divided
 * @param low The starting index
 * @param high The ending index
 */
void divide(int arr[], int low, int high) {
    if (low < high) {
        // Calculate mid point to divide array into two halves
        int mid = low + (high - low) / 2;

        // Recursive call to sort the first half
        divide(arr, low, mid);
        // Recursive call to sort the second half
        divide(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

/**
 * @brief Merges two subarrays of arr[]
 * @param arr The main array containing subarrays
 * @param low Starting index of first subarray
 * @param mid Ending index of first subarray
 * @param high Ending index of second subarray
 */
void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    /* Create temporary arrays */
    int L[n1], R[n2];

    /* Copy data to temporary arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    /* Merge the temporary arrays back into arr[low..high] */
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = low; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
