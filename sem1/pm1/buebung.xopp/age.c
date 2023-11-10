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
    int age = readIntegerSafely("Gib dein Alter ein: ");
    if (age >= 60) {
        printf("Oldtimer\n");
    }
    else {
        printf("Jungspund\n");
    }
}