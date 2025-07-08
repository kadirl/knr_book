/*
* Created:   2025-07-08
*
* Exercise 1-18:
* Write a program to remove trailing blanks and tabs from each line
* of input, and to delete entirely blank lines.
*/

#include <stdio.h>

// Contants definitions
#define TRUE 1
#define FALSE 0
#define MAX_BUFFER_SIZE 1000

// Function prototypes
int get_line(char buffer[], int buffer_size);
void remove_trailing_blanks(char buffer[], int input_size);

// Main
int main() {
    char buffer[MAX_BUFFER_SIZE + 1];
    int input_size;

    // First, input the line and store it somewhere before printing.
    // Read lines until nothing is left and EOF is inputted.
    while ((input_size = get_line(buffer, MAX_BUFFER_SIZE)) != EOF) {
        // Attempt at harder approach:
        // STOP! I am not doing this. Too lazy :(
        // Since the program must print all lines longer than 80 char,
        // Before looking for the trailing blanks, I should check
        // if the line was overflown in the first place.
        // However, is it even possible, I do need to output the current line,
        // clear the buffer and continue only after it?
        // Probably I can solve this by always counting how many blanks
        // did I have since last non-blank char and then don't print
        // them. However, I need to think about this and I am not
        // in the mood for this >:(

        // Simpler approach:
        // Hardlimit the line length by 1000 chars :)
        // If line is not empty, then remove blanks & output
        if (buffer[0] != '\0') {
            remove_trailing_blanks(buffer, input_size);
            printf("%s$$\n", buffer);
        }
    }
    // Second I need to find the last non-empty char
}

// Functions implementations
int get_line(char buffer[], int buffer_size) {
   int i = 0;
   char c;
   // Input line until EOF or newline is met
   while (i < buffer_size - 1 && (c = getchar()) != EOF && c != '\n') {
       buffer[i++] = c;
   }
   // Place null char
   buffer[i + 1] = '\0';
   // Return line length
   return i;
}

void remove_trailing_blanks(char buffer[], int input_size) {
    int i = input_size - 1;
    while (i >= 0 && (buffer[i] == ' ' || buffer[i] == '\t')) {
        i--;
    }
    buffer[i + 1] = '\0';

}
