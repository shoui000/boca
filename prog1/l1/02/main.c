#include <stdio.h>

int main() {
  float height;
  float width;

  scanf("%f %f", &height, &width);

  float res = (height * 2) + (width * 2);

  printf("%.2f", res);

  return 0;
}
