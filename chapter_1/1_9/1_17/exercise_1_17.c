#include <stdio.h>

#define MAX_LINE    10
#define TARGET_LINE 5

#define TRUE    1
#define FALSE   0

// Function prototypes
int get_line(char line_to_save[], int max_length);

// Main function.
int main() {
    int curr_buffer_size = 0;
    char buffer[MAX_LINE + 1];
    int buffer_overflow = 0;

    while ((curr_buffer_size = get_line(buffer, MAX_LINE)) > 0) {
        // Last char isn't a newline -> input is longer than MAX_LINE.
        if (buffer[curr_buffer_size - 1] != '\n') {
            buffer_overflow = TRUE;
        }
        // Last char is a newline -> overflown part of a buffer is printed out.
        else if (buffer_overflow) {
            buffer_overflow = FALSE;
        }
        // Print buffer's content.
        printf("%s", buffer);
    }
}

// Function definitions
int get_line(char output[], int max_length) {
    int i;
    char input;
    // Input chars until buffer size is hit.
    for (i = 0; i < max_length - 1 && (input = getchar()) != EOF && input != '\n'; i++) {
        output[i] = input;
    }
    // Last inputted char is a newline
    // -> add newline char manually as it is now put into the buffer
    if (input == '\n') {
        output[i++] = '\n';
    }
    // Place terminator at the end.
    output[i] = '\0';
    // Return input length.
    return i;
}
