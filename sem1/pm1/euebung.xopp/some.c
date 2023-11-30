#include <stdio.h>

int gcd(int a, int b) {
    return a > b ? gcd(a - b, b) : a < b ? gcd(a, b - a) : a;
}

// void expect(int output, int expected) {
//     if (output == expected) {
//         printf("\x1b[32mpassed\x1b[0m\n");
//     }
//     else {
//         printf("\x1b[31mFailed!\x1b[0m\n");
//     }
// }

// int main() {
//     expect(gcd(4,4), 4);
//     expect(gcd(12, 10), 2);
//     expect(gcd(0, 0), 0);
//     expect(gcd(33, 34), 1);
//     expect(gcd(2, 130), 2);
// }