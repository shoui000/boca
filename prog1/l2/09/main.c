#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  for (int x = n+1 ; x<m ; x++){
    int primo = 1;
    for (int i = 2; i < x; i++) {
      if (x % i == 0) {
        primo = 0;
        break;
      }
    }

    if (primo) { // da pra fazer de um jeito muito mais matemático, mas eu to com preguiça
      printf("%d\n", x);

      if ((x * 2) >= m) {
        printf("*");
      }

      for (int y = x+1 ; y<m ; y++) {
        if (y % x == 0) {
          printf("%d ", y);
        }
      }
      printf("\n");
    }
  }

  return 0;
}
