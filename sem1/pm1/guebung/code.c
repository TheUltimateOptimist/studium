#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void hallo() {
    char name[200];
    printf("Gib deinen Namen ein: ");
    scanf("%s", name);
    printf("Hallo %s\n", name);
}

void quad(char art[], int width) {
    int index = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            art[index] = 'X';
            index++;
        }
        art[index] = '\n';
        index++;
    }
    art[index] = '\0';
}

void dreieck(int anz_zeilen) {
    if (anz_zeilen == 0) {
        return;
    }
    int characters = 0;
    for (int i = 1; i <= anz_zeilen; i++) {
        characters += i;
    }
    char letters[anz_zeilen + characters + 1];
    int index = 0;
    for (int i = 1; i <= anz_zeilen; i++) {
        for (int j = 1; j <= i; j++) {
            letters[index] = 'X';
            index++;
        }
        letters[index] = '\n';
        index++;
    }
    letters[index] = '\0';
    printf("%s", letters);
}

unsigned int string_length(char str[]) {
    size_t length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}

bool palindrom(char str[]) {
    if (strlen(str) <= 1) {
        return false;
    }
    for (int i = 0; i < strlen(str) / 2; i++) {
        if (str[i] != str[strlen(str) - 1 - i]) {
            return false;
        }
    }
    return true;
}

void entferne(char str[], char c) {
    size_t length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == c) {
            for (int j = i; j < length; j++) {
                str[j] = str[j + 1];
            }
            printf("%s\n", str);
            return;
        }
    }
    printf("%s\n", str);
}

void expect(int output, int expected) {
    if (output == expected) {
        printf("\x1b[32mpassed\x1b[0m\n");
    }
    else {
        printf("\x1b[31mFailed!\x1b[0m\n");
    }
}

int main(int argc, char *argv[]) {
    // die aufgaben nummer muss bei ausfuehrung des programmes mitgegeben werden
    // die eingegebene nummer wird dann getestet
    if (argc < 2) {
        printf("Exited without testing anything.\nEnter a number from 0 to 9 to specify what should be tested.\n");
        exit(1);
    }
    if (argv[1][0] < 48 || argv[1][0] > 57) {
        printf("Exited due to invalid input.\nEnter a number from 0 to 9 to specify what should be tested.\n");
        exit(1);
    }
    int identifier = argv[1][0] - 48;
    switch (identifier) {
        case 1: hallo();
        break;
        case 2: {
            char art[10*10 + 10 + 1];
            quad(art, 10);
            printf("%s", art);
        }
        break;
        case 3: dreieck(6);
        break;
        case 4: {
            expect(string_length("hallo"), 5);
            expect(string_length(""), 0);
            expect(string_length("hahahahaha"), 10);
        }
        break;
        case 5: {
            expect(palindrom("anna"), true);
            expect(palindrom("lagerregal"), true);
            expect(palindrom("weihnachten"), false);
            expect(palindrom(""), false);
            expect(palindrom("A"), false);
        }
        break;
        case 6: {
            char a[] = "Testwort";
            char b[] = "Weihnachten";
            char c[] = "Hund";
            char d[] = "";
            entferne(a, 'w');
            entferne(b, 'n');
            entferne(c, 'a');
            entferne(d, 'x');
        }
    }
}