#include <stdio.h>
#include <stdbool.h>

void printem(int x, int y, bool z) {
    printf("x = %d, y = %d, z = %d\n", x, y, z);
}

int main() {
    int x = 1, y = 2;
    bool z = true;
    printf("1. %d\n", y++*5+x);
    printem(x, y, z);
    printf("2. %d\n", x*5%++y);
    printem(x, y, z);
    printf("3. %d\n", x++-y--);
    printem(x, y, z);
    printf("4. %d\n", x*5<y||z&&x>y);
    printem(x, y, z);
    printf("5. %d\n", x=y=y+1);
    printem(x, y, z);
}