#include <stdio.h>

int main() {
    int input_char, last_char;

    while ((input_char = getchar()) != EOF) {
        if (input_char == ' ' && input_char == last_char) {
            continue;
        }
        last_char = input_char;

        putchar(input_char);
    }
}
