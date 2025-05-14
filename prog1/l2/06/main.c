#include <math.h>
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  double s;

  switch (n) {
    case 1:
      for (int i = 1; i <= 50; i++) {
        s += (i + (i-1)) / (double)i;
      }
      break;

    case 2:
      for (int i = 1; i <= 50; i++) {
        s += powf(2, (double)i) / (double)(51-i);
      }
      break;

    case 3:
      for (int i = 1; i <= 10; i++) {
        s += i / (double)(i * i);
      }
      break;
  }

  printf("%.6f", s);
}
