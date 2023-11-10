#include <stdio.h>

int readIntegerSafely(const char* str) {
    int readCount = 0;
    int input;
    while (readCount == 0) {
        printf("%s", str);
        readCount = scanf("%d", &input);
        if (readCount == 0) {
            printf("invalid input!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }
    return input;
}

int main() {
    int a = readIntegerSafely("Enter the first number: ");
    int b = readIntegerSafely("Enter the second number: ");
    printf("A und U fuer a = %d und b = %d ist A = %d und U = %d\n", a, b, a * b, 2*a + 2*b);
}

