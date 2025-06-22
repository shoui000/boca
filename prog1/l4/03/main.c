#include <stdio.h>
#include "data.h"

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    tData d;

    d = leData();
    imprimeData(d);

    if (ehAnoBissexto(d.ano)) {
      printf(":Bisexto");
    } else {
      printf(":Normal");
    }

    printf("\n");
  }
  return 0;
}
