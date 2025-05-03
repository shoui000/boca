#include <stdio.h>

int main() {
  float height;
  float width;

  scanf("%f", &height);
  scanf("%f", &width);

  float res = (height * 2) + (width * 2);

  printf("%.2f", res);

  return 0;
}
