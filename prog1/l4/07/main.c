#include <stdio.h>
#include "ponto.h"
#include "reta.h"

int main() {
  int n;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    tReta r = leReta();

    int i, f;
    i = quadrantePonto(getPInicial(r));
    f = quadrantePonto(getPFinal(r));

    if (i == 0 && f == 0) {
      printf("DIFERENTE");
    } else if (i != f) {
      printf("DIFERENTE");
    } else {
      printf("MESMO");
    }

    printf("\n");
  }

  return 0;
}
