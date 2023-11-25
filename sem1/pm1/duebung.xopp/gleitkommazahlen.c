#include <stdio.h>

void addierer(int n) {
    float floatt = 0.0f;
    double doublee = 0.0;
    for (int i = 1; i <= n; i++) {
        floatt = floatt + (1.0f / i);
        doublee = doublee + (1.0 / i);
    }
    printf("n = %d:\nfloat = %.16f\ndouble = %.16lf\n", n, floatt, doublee);
}

int main() {
    if (0.1 + 0.2 == 0.3) {
        printf("%lf\n", 0.1 + 0.2);
    }
    if (0.1 + 0.3 == 0.4) {
        printf("%lf\n", 0.1 + 0.3);
    }
    addierer(10000);
    addierer(100000);
    addierer(1000000);
}
