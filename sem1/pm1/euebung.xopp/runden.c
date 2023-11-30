#include <stdio.h>

int runde10(int n) {
    return n / 10 * 10 + 10*(n % 10 > 4);
}
 
int rundeSumme(int a, int b, int c) {
    return runde10(a) + runde10(b) + runde10(c);
}

////////////////////////////////////////////////////////////////
//Test
/////////////////////////////////////////////////////////

void expect(int output, int expected) {
    if (output == expected) {
        printf("\x1b[32mpassed\x1b[0m\n");
    }
    else {
        printf("\x1b[31mFailed!\x1b[0m\n");
    }
}

int main() {
    expect(runde10(200), 200);
    expect(runde10(201), 200);
    expect(runde10(205), 210);
    expect(runde10(209), 210);
}