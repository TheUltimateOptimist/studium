#include <stdio.h>
#include <stdbool.h>

bool mauern(int klein, int gross, int ziel) {
    return gross + klein / 5 >= ziel / 5 && klein - klein / 5 >= ziel % 5;
}

///////////////////////////////////
//TEST
///////////////////////////////////

void expect(bool output, bool expected) {
    if (output == expected) {
        printf("\x1b[32mpassed\x1b[0m\n");
    }
    else {
        printf("\x1b[31mFailed!\x1b[0m\n");
    }
}

int main() {
    expect(mauern(1, 3, 15), true);
    expect(mauern(1, 2, 15), false);
    expect(mauern(10, 2, 15), true);
    expect(mauern(1, 100, 11), true);
    expect(mauern(1, 100, 12), false);
    expect(mauern(1, 1, 0), true);
    expect(mauern(0, 0, 2), false);
}