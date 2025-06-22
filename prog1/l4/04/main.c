#include <stdio.h>
#include "ponto.h"

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    tPonto p = lePonto();

    imprimePonto(p);
    printf(" %d ", quadrantePonto(p));

    tPonto simetrico = getSimetrico(p);
    imprimePonto(simetrico);
    printf(" %d\n", quadrantePonto(simetrico));
  }
  return 0;
}
