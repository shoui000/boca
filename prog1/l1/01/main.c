#include <stdio.h>
#include <math.h>

int main() {
  int x;
  int y;
  float z;

  scanf("%d %d", &x, &y);
  z = sqrt(x) + sqrt(y);
  printf("%.2f", z);

  return 0;
}
