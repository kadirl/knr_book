#include <stdio.h>

int main() {
    float celc, fahr;

    int lower = 0;
    int upper = 300;
    int step = 20;

    // print a table header
    printf("%6s\t%6s\n", "F", "C");

    // print table rows
    for (fahr = lower; fahr <= upper; fahr += step) {
        celc = (5.0 / 9.0) * (fahr - 32.0);
        printf("%6.0f\t%6.2f\n", fahr, celc);
    }
}
