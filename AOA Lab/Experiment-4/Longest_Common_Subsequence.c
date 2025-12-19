/**
 * @file Longest_Common_Subsequence.c
 * @brief Implementation of Longest Common Subsequence (LCS) Algorithm
 * 
 * @author AMEY MAHENDRA THAKUR
 * @repository https://github.com/Amey-Thakur/ANALYSIS-OF-ALGORITHM-AND-ANALYSIS-OF-ALGORITHM-LAB
 * 
 * Experiment No. 4: Analysis of Longest Common Subsequence
 */

#include <stdio.h>
#include <string.h>

/**
 * @brief Utility function to find maximum of two integers
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * @brief Computes the length of the Longest Common Subsequence
 * @param X The first string
 * @param Y The second string
 * @param m Length of first string
 * @param n Length of second string
 * @return int Length of LCS
 */
int lcs(char* X, char* Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
       that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    /* L[m][n] contains the length of LCS of X[0..n-1] & Y[0..m-1] */
    return L[m][n];
}

int main() {
    char X[] = "BDCABA";
    char Y[] = "ABCBDAB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("\t--- LONGEST COMMON SUBSEQUENCE ---\t\n");

    printf("\nFIRST STRING: %s\n", X);
    printf("SECOND STRING: %s\n", Y);

    int result = lcs(X, Y, m, n);

    printf("\nLENGTH OF LONGEST COMMON SUBSEQUENCE IS: %d\n", result);

    return 0;
}
