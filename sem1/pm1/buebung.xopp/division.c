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
    int number = readIntegerSafely("Gib eine ganze Zahl ein: ");
    printf("Der Rest von %d / 57 = %d\n", number, number % 57);
    if (number % 57 == 0) {
        printf("Scherzkeks\n");
    }
}