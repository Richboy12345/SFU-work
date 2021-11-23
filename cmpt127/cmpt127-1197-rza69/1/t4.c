#include <stdio.h>
#include <math.h>

int main() {
  
  double d = 0;
  int a = 0;
  a = scanf("%lf", &d);
  if (a) {
	printf("%d ", (int)floor(d));
  	printf("%d ", (int)round(d));
 	printf("%d", (int)ceil(d));
 	printf("\n");
  }
  else {
	printf("scanf error: (0)\n");
  }

  return 0;
}
