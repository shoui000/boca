#include <math.h>
#include <stdio.h>

int main(){
  int a;
  scanf("%d", &a);

  while (1) {
    if (a >= 0 && a <= 9) {
      break;
    } else {
      int sum = 0;
      int x = log10(a);

      for (int i = x; i >= 0; i--) {
        int z = (int)(a / pow(10, i));
        a -= z * pow(10, i);
        sum += z;
      }

      a = sum;
    }
  }

  printf("RESP:%d", a);

  return 0;
}
