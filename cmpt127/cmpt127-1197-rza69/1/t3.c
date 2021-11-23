#include <stdio.h>
#include <math.h>

int main() {

  double d = 0;
  scanf("%lf", &d);
  printf("%d ", (int)floor(d));
  printf("%d ", (int)round(d));
  printf("%d", (int)ceil(d));
  printf("\n");

  return 0;
}
