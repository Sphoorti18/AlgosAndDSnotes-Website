#include <stdio.h>
#include <string.h>

// Function to find the length of LCS using dynamic programming
int lcs(char *X, char *Y, int m, int k) {
    int L[m+1][k+1];
    int i, j;

    // Build the L[m+1][k+1] table in bottom-up fashion
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= k; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // L[m][k] contains the length of LCS for X[0..m-1], Y[0..k-1]
    return L[m][k];
}

// Function to print the LCS
void printLCS(char *X, char *Y, int m, int k) {
    int L[m+1][k+1];
    int i, j;

    // Build the L[m+1][k+1] table in bottom-up fashion
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= k; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // Create a string to store the LCS
    int index = L[m][k];
    char lcs[index + 1];
    lcs[index] = '\0';  // Set the terminating character

    // Start from the right-most bottom-most corner and store characters in lcs[]
    i = m; j = k;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--; j--; index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the LCS
    printf("LCS of %s and %s is %s\n", X, Y, lcs);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int k = strlen(Y);

    printf("Length of LCS is %d\n", lcs(X, Y, m, k));
    printLCS(X, Y, m, k);

    return 0;
}
