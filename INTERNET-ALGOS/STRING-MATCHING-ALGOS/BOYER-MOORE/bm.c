#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

// A utility function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS]) {
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of the last occurrence
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

/* A pattern searching function that uses Bad Character Heuristic of
   Boyer Moore Algorithm */
void search(char *txt, char *pat) {
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[NO_OF_CHARS];

    // Fill the bad character array by calling the preprocessing function
    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is the shift of the pattern with respect to the text
    while (s <= (n - m)) {
        int j = m - 1;

        // Keep reducing index j of pattern while characters of pattern and text are matching
        // at this shift s
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        // If the pattern is present at current shift, then index j will become -1 after the above loop
        if (j < 0) {
            printf("Pattern occurs at shift = %d\n", s);

            /* Shift the pattern so that the next character in text aligns with the last occurrence of it in pattern.
               The condition s + m < n is necessary for the case when pattern occurs at the end of text */
            s += (s + m < n) ? m - badchar[(int) txt[s + m]] : 1;

        } else
            // Shift the pattern so that the bad character in text aligns with the last occurrence of it in pattern.
            // The max function is used to make sure that we get a positive shift.
            s += max(1, j - badchar[(int) txt[s + j]]);
    }
}

int main() {
    char txt[] = "ABAAABCD";
    char pat[] = "ABC";
    search(txt, pat);
    return 0;
}
