#include <stdio.h>
#include <stdbool.h>

int main() {
    int i = 23, j;
    int zahl = 42;

    j = i + zahl; //i = 23, zahl = 42
    j = j + 1; // erhoehe j um 1
    printf("j hat den Wert %d\n", j);

    zahl = 2 * (17 + 4) - 7 / 3;
    printf("zahl hat den Wert %d\n", zahl);

    return 0;

}