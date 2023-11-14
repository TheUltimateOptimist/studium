#include <stdio.h>

int main() {
    int first, second;
    printf("Erste Zahl: ");
    scanf("%d", &first);
    printf("Zweite Zahl: ");
    scanf("%d", & second);
    if (first % 10 == second % 10) {
        printf("Letzte Ziffer gleich\n");
    }
}