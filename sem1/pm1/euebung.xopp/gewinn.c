#include <stdio.h>

//Erklaerung:
//Der Term (a == b) + (b == c) + (a == c) ergibt 0, 
//wenn a,b,c unterschiedlich sind, 1 wenn zwei variablen
//gleich sind und 3 wenn alle gleich sind.
//Diese drei Werte muss ich jetzt irgendwie auf 0, 10 und 20 abbilden.
//Dafuer addiere ich 1 dazu und erhalte somit 1, 2 und 4.
//Anschliesslich teile ich alle mit ganzzahliger Division durch 2 und 
//erhalte 0, 1, 2. Jetzt muss ich nur noch mit 10 multiplizieren und 
//erhalte 0, 10 und 20 wie laut Aufgabe gefordert.
int gewinn(int a, int b, int c) {
    return ((a == b) + (b == c) + (a == c) + 1)/2*10;
}


/////////////////////////////
//Test
/////////////////////////////
void expect(int output, int expected) {
    if (output == expected) {
        printf("\x1b[32mpassed\x1b[0m\n");
    }
    else {
        printf("\x1b[31mFailed!\x1b[0m\n");
    }
}

int main() {
    expect(gewinn(4, 4, 6), 10);
    expect(gewinn(4, 6, 4), 10);
    expect(gewinn(6, 4, 4), 10);
    expect(gewinn(6, 6, 6), 20);
    expect(gewinn(1, 2, 3), 0);
}