#include <stdio.h>

#define     IN      1
#define     OUT     0
#define     MAX_WORD_LEN    256
#define     BAR_LENGTH  80

int main() {
    // Count word length.
    // First, reliably count words.
    // Will need IN & OUT states.
    int state = OUT;
    char input;

    // Init array for storing word lengths.
    int lens[MAX_WORD_LEN];
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        lens[i] = 0;
    }

    // Process the input.
    int word_length = 0;
    while ((input = getchar()) != EOF) {
        if (state == IN && (input == ' ' || input == '\n' || input == '\t')) {
            state = OUT;
            lens[word_length]++;
            word_length = 0;
        } else {
            state = IN;
            word_length++;
        }
    }

    // Find the word length with the most number of occurences.
    int max_count = 0;
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        if (lens[i] > max_count) {
            max_count = lens[i];
        }
    }

    // Output the histogram.
    // Header
    printf("Histogram of word lengths:\n");
    // Bars
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        // Skip empty lines.
        if (lens[i] == 0) {
            continue;
        }

        // Otherwise, print world length and the bar itself.
        printf("%3d%4d [", i, lens[i]);
        // Find relative bar length and output the bar
        float bar_length = lens[i] * BAR_LENGTH / max_count;
        for (int j = 0; j < bar_length; j++) {
            putchar('=');
        }
        printf("]\n");
    }
}
