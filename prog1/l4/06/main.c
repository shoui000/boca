#include <stdio.h>
#include "ponto.h"
#include "reta.h"

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    tPonto p = lePonto();
    tReta r = leReta();

    float i, f;
    i = distanciaPontos(p, getPInicial(r));
    f = distanciaPontos(p, getPFinal(r));

    if (i == f) {
      printf("EQUIDISTANTE");
    } else if (i < f) {
      printf("INICIO");
    } else {
      printf("FIM");
    }

    printf("\n");
  }

  return 0;
}
