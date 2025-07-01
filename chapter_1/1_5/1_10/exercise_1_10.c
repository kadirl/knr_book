#include <stdio.h>

int main() {
    int input_char;

    while ((input_char = getchar()) != EOF) {
        if (input_char == '\t') {
            printf("\\t");
        } else if (input_char == '\b') {
            printf("\\b");
        } else if (input_char == '\\') {
            printf("\\\\");
        } else {
            putchar(input_char);
        }
    }
}
