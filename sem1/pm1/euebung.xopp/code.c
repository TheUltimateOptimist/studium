#include <stdio.h>
#include <stdbool.h>

//For explanations of the different exercises see "explanations.txt"

//Aufgabe 2:
int gewinn(int a, int b, int c) {
    return ((a == b) + (b == c) + (a == c) + 1)/2*10;
}

//Aufgabe 3:
int runde10(int n) {
    return n / 10 * 10 + 10*(n % 10 > 4);
}
 
int rundeSumme(int a, int b, int c) {
    return runde10(a) + runde10(b) + runde10(c);
}

//Aufgabe 4:
int gcd(int a, int b) {
    return a > b ? gcd(a - b, b) : a < b ? gcd(a, b - a) : a;
}

//Aufgabe 5:
int kgv(int a, int b) {
    return a*b / gcd(a, b);
}

//Aufgabe 6:
bool mauern(int klein, int gross, int ziel) {
    return gross + klein / 5 >= ziel / 5 && klein - klein / 5 >= ziel % 5;
}


/////////////////////////////////
//Testing
/////////////////////////////////
void expect(int output, int expected) {
    if (output == expected) {
        printf("\x1b[32mpassed\x1b[0m\n");
    }
    else {
        printf("\x1b[31mFailed!\x1b[0m\n");
    }
}

int main() {
    printf("Testing Aufgabe 2:\n");
    expect(gewinn(4, 4, 6), 10);
    expect(gewinn(4, 6, 4), 10);
    expect(gewinn(6, 4, 4), 10);
    expect(gewinn(6, 6, 6), 20);
    expect(gewinn(1, 2, 3), 0);
    printf("\n");
    printf("Testing Aufgabe 3\n");
    expect(runde10(200), 200);
    expect(runde10(201), 200);
    expect(runde10(205), 210);
    expect(runde10(209), 210);
    //rundeSummme not tested, because trivial
    printf("\n");
    printf("Testing Aufgabe 4\n");
    expect(gcd(4,4), 4);
    expect(gcd(12, 10), 2);
    expect(gcd(33, 34), 1);
    expect(gcd(2, 130), 2);
    //aufgabe 5 not tested, because trivial
    printf("\n");
    printf("Testing Aufgabe 6\n");
    expect(mauern(1, 3, 15), true);
    expect(mauern(1, 2, 15), false);
    expect(mauern(10, 2, 15), true);
    expect(mauern(1, 100, 11), true);
    expect(mauern(1, 100, 12), false);
    expect(mauern(1, 1, 0), true);
    expect(mauern(0, 0, 2), false);
}
