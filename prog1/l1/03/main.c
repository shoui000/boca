#include <stdio.h>

int main() {
  float x1, y1, x2, y2;
  scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

  float res  = ((x2-x1) * 2) + ((y2-y1) * 2);
  printf("%.2f", res);

  return 0;
}
