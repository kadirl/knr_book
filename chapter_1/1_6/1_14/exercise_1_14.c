#include <stdio.h>

#define     CHARSET_LEN    256
#define     BAR_LENGTH  80

int main() {
    char input;

    // Init array for storing word lengths.
    int lens[CHARSET_LEN];
    for (int i = 0; i < CHARSET_LEN; i++) {
        lens[i] = 0;
    }

    // Process the input.
    while ((input = getchar()) != EOF) {
        lens[input]++;
    }

    // Find the word length with the most number of occurences.
    int max_count = 0;
    for (int i = 0; i < CHARSET_LEN; i++) {
        if (lens[i] > max_count) {
            max_count = lens[i];
        }
    }

    // Output the histogram.
    // Header
    printf("Histogram of word lengths:\n");
    // Bars
   for (int i = 0; i < CHARSET_LEN; i++) {
        // Skip empty lines.
        if (lens[i] == 0) {
            continue;
        }

        // Otherwise, print world length and the bar itself.
        printf("%3c%4d [", i, lens[i]);
        // Find relative bar length and output the bar
        float bar_length = lens[i] * BAR_LENGTH / max_count;
        for (int j = 0; j < bar_length; j++) {
            putchar('=');
        }
        printf("]\n");
    }
}
