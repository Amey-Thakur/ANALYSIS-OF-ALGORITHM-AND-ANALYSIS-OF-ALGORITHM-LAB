/**
 * @file Binary_Search.c
 * @brief Implementation of Recursive Binary Search Algorithm
 * 
 * @author AMEY MAHENDRA THAKUR
 * @repository https://github.com/Amey-Thakur/ANALYSIS-OF-ALGORITHM-AND-ANALYSIS-OF-ALGORITHM-LAB
 * 
 * Experiment No. 2: Analysis of Binary Search
 */

#include <stdio.h>

/**
 * @brief Searches for a key in a sorted array using Binary Search
 * @param arr The sorted array to search in
 * @param target The element to search for
 * @param low The starting index of the search range
 * @param high The ending index of the search range
 * @return int The index of the target if found, otherwise -1
 */
int binarySearch(int arr[], int target, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2; // Avoid potential overflow

        // If the element is present at the middle itself
        if (arr[mid] == target) {
            return mid;
        }

        // If element is smaller than mid, it can only be present in left subarray
        if (target < arr[mid]) {
            return binarySearch(arr, target, low, mid - 1);
        }

        // Else the element can only be present in right subarray
        return binarySearch(arr, target, mid + 1, high);
    }

    // Element is not present in array
    return -1;
}

int main() {
    int arr[100], n, target, i, result;

    printf("\t--- BINARY SEARCH ---\t\n");

    printf("\nEnter the number of elements: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n > 100 || n <= 0) {
        printf("Please enter a number between 1 and 100.\n");
        return 1;
    }

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the key element to be searched: ");
    scanf("%d", &target);

    // Initial call to binary search
    result = binarySearch(arr, target, 0, n - 1);

    if (result == -1) {
        printf("\nELEMENT NOT FOUND!\n");
    } else {
        printf("\nTHE ELEMENT IS FOUND AT LOCATION %d (Index: %d)\n", result + 1, result);
    }

    return 0;
}
