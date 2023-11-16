#include <stdio.h>

int main() {
    double pi4 = 0.0;
    for (int i = 0; i < 1000000; i++) {
        //1.0 - 2*(i % 2) bei i = 0: 1, i = 1: -1, ...
        pi4 = pi4 + (1.0 - 2*(i % 2))/(2*i + 1);
    }
    printf("%.10lf\n", 4*pi4);
}

