#include <stdio.h>

int fahrerlaubnis(int alter, int land);
int main() {
    printf("%d", fahrererlaubnis(5, 5));
}
int fahrerlaubnis(int alter, int land) {
  if (alter < 0 || land < 1 || land > 2) {
    return 3;
  }
  if (land == 2 && alter == 17) {
    return 2;
  }
  if (alter >= 17) {
    return 1;
  }
  return 0;
}