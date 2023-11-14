#include <stdio.h>

int main() {

    //einlesen von a und b
    int a, b;
    printf("Erste Zahl: ");
    scanf("%d", &a);
    printf("Zweite Zahl: ");
    scanf("%d", &b);

    //a und b duerfen nicht 0 sein
    if (a == 0 || b == 0){
        printf("a und b duerfen nicht 0 sein!\n");
        return 0;
    } 
    //betrag auf a und b anwenden
    a = a >= 0 ? a : -a;
    b = b >= 0 ? b : -b;

    //a und b so ordnen das a groesser als b ist
    if (b > a) {
        //tausche a und b
        a = a + b;
        b = a - b;
        a = a - b;
    }

    printf("a = %d und b = %d\n", a, b);

    while(a % b != 0) {
        int rest = a % b;
        a = b;
        b = rest;
    }
    printf("Der groesste gemeinsame Teiler von a und b ist: %d\n", b);
}