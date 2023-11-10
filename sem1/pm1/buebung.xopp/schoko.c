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
    int a = readIntegerSafely("Gib a ein: ");
    int b = readIntegerSafely("Gib b ein: ");
    int n = readIntegerSafely("Gib n ein: ");
    if (a + b*5 < n) {
        printf("-1\n");
        return 0;
    }
    int maxLargeToBeEaten = n / 5;
    int remaining = 0;
    if (b <= maxLargeToBeEaten) {
        remaining = n - b*5;
    }
    else {
        remaining = n - maxLargeToBeEaten*5;
    }
    printf("%d\n", remaining);
}