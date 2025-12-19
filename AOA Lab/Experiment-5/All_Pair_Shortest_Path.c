/**
 * @file All_Pair_Shortest_Path.c
 * @brief Implementation of All-Pairs Shortest Path Algorithm (Floyd-Warshall)
 * 
 * @author AMEY MAHENDRA THAKUR
 * @repository https://github.com/Amey-Thakur/ANALYSIS-OF-ALGORITHM-AND-ANALYSIS-OF-ALGORITHM-LAB
 * 
 * Experiment No. 5: Analysis of All Pair Shortest Path
 */

#include <stdio.h>

#define MAX 20
#define INF 999

/**
 * @brief Returns the minimum of two integers
 * @param a First integer
 * @param b Second integer
 * @return int The minimum value
 */
int min(int a, int b) {
    return (a < b) ? a : b;
}

/**
 * @brief Computes all-pairs shortest paths using the Floyd-Warshall algorithm
 * @param matrix The adjacency matrix of the graph
 * @param n The number of vertices
 */
void shortestPath(int matrix[MAX][MAX], int n) {
    int A[MAX][MAX][MAX];
    int i, j, k;

    // Initialize A(0) with the input matrix
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            A[0][i][j] = matrix[i][j];
        }
    }

    // Dynamic Programming steps to calculate A(1) to A(n)
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                // A[k][i][j] = min(A[k-1][i][j], A[k-1][i][k] + A[k-1][k][j])
                A[k][i][j] = min(A[k - 1][i][j], (A[k - 1][i][k] + A[k - 1][k][j]));
            }
        }
    }

    // Print all matrices from A(0) to A(n)
    for (k = 0; k <= n; k++) {
        printf("\nA(%d):\n", k);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (A[k][i][j] >= INF) {
                    printf("INF\t");
                } else {
                    printf("%d\t", A[k][i][j]);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int matrix[MAX][MAX], n, i, j;

    printf("\t--- ALL PAIRS SHORTEST PATH (FLOYD-WARSHALL) ---\t\n");

    printf("\nEnter the number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid input or number of vertices exceeds limit (%d).\n", MAX);
        return 1;
    }

    printf("\nEnter the adjacency matrix (Use %d for infinity):\n", INF);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Process and print shortest paths
    shortestPath(matrix, n);

    return 0;
}
