#include <stdio.h>

int main() {
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;

    int input_char;
    while ((input_char = getchar()) != EOF) {
        blanks += input_char == ' ';
        tabs += input_char == '\t';
        newlines += input_char == '\n';
    }

    printf("blanks: %d\ntabs: %d\nnewlines: %d", blanks, tabs, newlines);
}
