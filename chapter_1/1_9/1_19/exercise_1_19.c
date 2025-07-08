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
void reverse(char buffer[], int buffer_size);

// Main
int main() {
    char buffer[MAX_BUFFER_SIZE + 1];
    int input_size;

    // First, input the line and store it somewhere before printing.
    // Read lines until nothing is left and EOF is inputted.
    while ((input_size = get_line(buffer, MAX_BUFFER_SIZE)) != EOF) {
        // Hardlimit the line length by 1000 chars :)
        // If line is not empty, then remove blanks & output
        if (buffer[0] != '\0') {
            printf("%s\n", buffer);
            reverse(buffer, input_size);
            printf("%s\n", buffer);
        }
    }
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
   buffer[i] = '\0';
   // Return line length
   return i;
}

void reverse(char buffer[], int buffer_size) {
    char temp;
    int i = 0, j = buffer_size - 1;

    while (i < buffer_size / 2) {
        temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
        i++;
        j--;
    }
}
