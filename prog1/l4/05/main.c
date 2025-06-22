#include <stdio.h>
#include "ponto.h"

int main() {
  int n;
  scanf("%d", &n);

  tPonto anterior;
  for (int i = 0; i < n; i++) {
    tPonto p = lePonto();

    if (i == 0) {
      printf("-");
    } else {
      printf("%.2f", distanciaPontos(p, anterior));
    }

    anterior = p;
    printf("\n");
  }

  return 0;
}
