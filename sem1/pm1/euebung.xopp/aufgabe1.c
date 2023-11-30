#include <stdio.h>

float holeWert(char c) {
    float value;
    printf("%c eingeben: ", c);
    scanf("%f", &value);
    return value;
}

float berechneSpannung(float r, float i) {
    return r * i; // Spannung U = R * I
}
void zeigeErgebnis(char c, float x) {
    printf("%c betraegt: %f\n", c, x);
}

//meine funktionen

float berechneStrom(float u, float r) {
    return u / r;
}

float berechneWiderstand(float u, float i) {
    return u / i;
}

int main() {
    float u, r, i;
    i = holeWert('I');
    r = holeWert('R');
    u = berechneSpannung(r, i);
    zeigeErgebnis('U', u);
    while(1) {
        char input;
        printf("Moechtest du R, U oder I berechnen? Falls R gib R, falls U U und falls I I ein: ");
        scanf(" %c", &input);
        float solution;
        switch(input) {
            case 'R': {
                float u = holeWert('U');
                float i = holeWert('I');
                solution = berechneWiderstand(u, i);
            } 
            break;
            case 'U': {
                float r = holeWert('R');
                float i = holeWert('I');
                solution = berechneSpannung(r, i);
            }
            break;
            case 'I': {
                float u = holeWert('U');
                float r = holeWert('R');
                solution = berechneStrom(u, r);
            }
            break;
            default: printf("Falsche Eingabe!\n"); continue;
        }
        zeigeErgebnis(input, solution);
    }
}