#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

char *readInput() {
    size_t bufferSize = 100;
    char *buffer = malloc(bufferSize*sizeof(char));
    char c;
    int index = 0;
    do {
        c = fgetc(stdin);
        if (!(bufferSize > index)) {
            char *newBuffer = malloc(2*bufferSize*sizeof(char));
            for (int i = 0; i < bufferSize; i++) {
                newBuffer[i] = buffer[i];
            }
            bufferSize *= 2;
        }
        buffer[index] = c;
        index++;
    }
    while(c != '\n' && c != EOF);
    buffer[index - 1] = '\0';
    return buffer;
}

// int main() {
//     //int age = readIntegerSafely("Gib dein Alter ein: ");
//     int age = 100;
//     char buffer[3];
//     printf("enter it: ");
//     printf("%p\n", fgets(buffer, sizeof(buffer), stdin));
//     printf("%s\n", buffer);
//     if (age >= 60) {
//         printf("Oldtimer\n");
//     }
//     else {
//         printf("Jungspund\n");
//     }
// }
int main() {
    printf("enter it: ");
    fflush(stdout);
    char *text = readInput();
    printf("%s\n", text);
}