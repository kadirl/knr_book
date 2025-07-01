#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    char input;
    int state = OUT;  // because of leading blanks

    while ((input = getchar()) != EOF) {
        // 1:
        // Copy input into output and replace all blanks with newlines
        // 2:
        // What if the input has two consecutive blanks?
        // The program would be outputting empty lines
        // So it needs to find a way if there was a word
        // I should try to use flags IN and OUT
        // When OUT (no preceeding word), nothing should be outputed
        // When IN (was in the word), output \n
        if (state == IN && (input == ' ' || input == '\t' || input == '\n')) {
            putchar('\n');
            state = OUT;
        } else {
            putchar(input);
            state = IN;
        }
    }

    putchar('\n');
}
