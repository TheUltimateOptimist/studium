#include <stdio.h>
#include <stdbool.h>

int main() {
    int day, month, year;
    
    printf("Tag, Monat, Jahr eingeben (Format: 24 12 2022)\n");
    scanf("%d %d %d", &day, &month, &year);
    
    // 1. Januar 1900 war Montag
    int shift = year - 1900;
    shift = shift + shift / 4 + (day - 1);
    
    if (month > 1) {
        shift = shift + 31;
    }
    if (month > 2) {
        shift = shift + 28;
    }
    if (month > 3) {
        shift = shift + 31;
    }
    if (month > 4) {
        shift = shift + 30;
    }
    if (month > 5) {
        shift = shift + 31;
    }
    if (month > 6) {
        shift = shift + 30;
    }
    if (month > 7) {
        shift = shift + 31;
    }
    if (month > 8) {
        shift = shift + 31;
    }
    if (month > 9) {
        shift = shift + 30;
    }
    if (month > 10) {
        shift = shift + 31;
    }
    if (month > 11) {
        shift = shift + 30;
    }
    
    /* Bei Januar oder Februar eines Schaltjahres 1 von shift abziehen,
       aber nur, wenn das Datum nicht das erste Jahr, also 1900, ist
       (weil dann die Zahl stimmt). */
    if ((month == 1 || month == 2) && (year % 4 == 0) && year != 1900) {
        shift = shift - 1;
    }
    
    switch(shift % 7) {
        case 0: printf("Montag\n");
            break;
        case 1: printf("Dienstag\n");
            break;
        case 2: printf("Mittwoch\n");
            break;
        case 3: printf("Donnerstag\n");
            break;
        case 4: printf("Freitag\n");
            break;
        case 5: printf("Samstag\n");
            break;
        case 6: printf("Sonntag\n");
            break;
    }
}