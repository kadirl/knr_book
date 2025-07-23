/*
* Created:   2025-07-09
*
* Exercise 1-19:
* Write a program detab that replaces tabs in the input with
* the proper number of blanks to space to the next tab stop.
* Assume a fixed set of tab stops, say every n columns.
* Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

// Formatting
#define TAB          4

// Buffering
#define BUFFER_SIZE  10

// Booleans
#define TRUE         1
#define FALSE        0


// Function prototypes
int get_line(char buffer[], int buffer_size);
void detab(char input_buffer[], char output_buffer[], int buffer_size);


// Main function
int main(void) {
    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];
    // int is_overflown = FALSE;

    int input_size;
    while((input_size = get_line(input_buffer, BUFFER_SIZE)) != 0) {
        // check if input buffer is overflown
        // if (input_buffer[input_size - 1] != '\n') {
            // is_overflown = TRUE;
        // }

        // detab

        printf("%s", input_buffer);
    }
}


// Function definitions
int get_line(char buffer[], int buffer_size) {
    char input;
    int i = 0;
    // buffer - 2 to have space for '\n' (if any) and for '\0' (always)
    while (i < buffer_size - 2 && (input = getchar()) != EOF && input != '\n') {
        // puts input char at i'th index, then increments for the next char
        buffer[i++] = input;
    }

    // if the last input was a newline, then add a newline here
    if (input == '\n') {
        buffer[i] = '\n';
    }

    // put null char and return input length
    buffer[i + 1] = '\0';
    return i;
}
