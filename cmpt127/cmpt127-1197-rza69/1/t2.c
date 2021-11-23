#include <stdio.h>
#include <limits.h>

int main() {
  printf("%lu ", sizeof(char) * CHAR_BIT);
  printf("%lu ", sizeof(unsigned char) * CHAR_BIT);
  printf("%lu ", sizeof(int) * CHAR_BIT);
  printf("%lu ", sizeof(unsigned int) * CHAR_BIT);
  printf("%lu ", sizeof(long) * CHAR_BIT);
  printf("%lu ", sizeof(unsigned long) * CHAR_BIT);
  printf("%lu ", sizeof(float) * CHAR_BIT);
  printf("%lu ", sizeof(double) * CHAR_BIT);
  printf("%lu", sizeof(long double) * CHAR_BIT);
  printf("\n");

  return 0;
}
