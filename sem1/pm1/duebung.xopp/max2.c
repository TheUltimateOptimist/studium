#include <stdio.h>

int main() {
    int input;
    int biggestNumber = -1;
    for (int i = 0; i < 10; i++) {
        printf("Gib die %d. Zahl ein: ", i + 1);
        scanf("%d", &input);
        if (input < 0) {
            continue;
        }
        if (input > biggestNumber) {
            biggestNumber = input;
        }
    } 
    if (biggestNumber < 0) {
        //wenn nie eine positive Zahl kam
        printf("Es konnte keine Zahl bestimmt werden.\n");
    }
    else {
        //wenn mindestens eine positive Zahl kam
        printf("Das Maximum der eingegebenen Zahlen betraegt: %d\n", biggestNumber);
    }
} 