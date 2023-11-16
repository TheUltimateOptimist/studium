#include <stdio.h>

int main() {
    double pi2 = 1.0;
    for (int i = 0; i < 1000000; i++) {
        pi2 = pi2 * (i + 1 + (i + 1) % 2) / (i + 1 + i % 2);
    }
    printf("%.10lf\n", 2*pi2);
}