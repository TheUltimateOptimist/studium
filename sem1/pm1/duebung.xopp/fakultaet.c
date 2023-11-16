#include <stdio.h>

// int main() {
//     unsigned int input;
//     int aint = 2147483647;
//     printf("%d\n", aint + 1);
//     unsigned int unsigendInt = 4294967295;
//     printf("%u\n", unsigendInt + 1);
//     long long longlong = 9223372036854775807LL;
//     printf("%lld\n", longlong + 1);
//     unsigned long long unsignedLongLong = 18446744073709551615LLU;
//     printf("%llu\n", unsignedLongLong + 1);
// }

int main() {
    unsigned int input;
    printf("Gib ein n ein: ");
    scanf("%u", &input);
    unsigned long long solution = 1LLU;
    while (input > 0) {
        solution*=input;
        input--;
    }
    printf("Ergebnis: %llu\n", solution);
    // if (solution > 2147483647LLU) {
    //     printf("int overflow\n");
    // }
    // if (solution > 4294967295LLU) {
    //     printf("unsigned int overflow\n");
    // }
    // if (solution > 9223372036854775807LLU) {
    //     printf("long long overflow\n");
    // }
}