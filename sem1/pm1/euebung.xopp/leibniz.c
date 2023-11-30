#include <stdio.h>

double leibniz (double n);
double leibniz (double n) {
    int m = (int) n;
    double sum = 0.0;
    for (int i = 0; i < m + 1; i++) {
        sum = sum + (i % 2 == 1 ? -1.0 : 1.0) / (2.0*i + 1.0); 
    }
    printf("%f", 4*sum);
    return 4*sum;
}

int main() {
    printf("%.10lf", leibniz(50));
}
