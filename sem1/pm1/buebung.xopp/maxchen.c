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
    int firstNumber = 0;
    int secondNumber = 0;
    while (firstNumber < 1 || firstNumber > 6) {
        firstNumber = readIntegerSafely("Gib eine Zahl zwischen 1 und 6 ein: ");
        if (firstNumber < 1 || firstNumber > 6) {
            printf("Fehler: Die eingegebene Zahl liegt nicht zwischen 1 und 6!\n");
        }
    }
    while (secondNumber < 1 || secondNumber > 6) {
        secondNumber = readIntegerSafely("Gib noch eine Zahl zwischen 1 und 6 ein: ");
        if (secondNumber < 1 || secondNumber > 6) {
            printf("Fehler: Die eingegebene Zahl liegt nicht zwischen 1 und 6!\n");
        }
    }
    if (firstNumber == secondNumber) {
        printf("Pasch %d\n", firstNumber);
    }
    else if (firstNumber == 1 && secondNumber == 2) {
        printf("Maexchen\n");
    }
    else if (firstNumber > secondNumber) {
        printf("%d%d\n", firstNumber, secondNumber);
    }
    else {
        printf("%d%d\n", secondNumber, firstNumber);
    }
}