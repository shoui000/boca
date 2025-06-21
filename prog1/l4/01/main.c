#include <stdio.h>
#include "produto.h"

int main() {
  int n;
  scanf("%d", &n);

  tProduto maior, menor;
  
  for (int i = 0; i < n; i++) {
    tProduto p = LeProduto();
    
    if (!TemProdutoEmEstoque(p)) {
      printf("FALTA:");
      ImprimeProduto(p);
    }

    if (i == 0) {
      maior = p;
      menor = p;
    }

    if (EhProduto1MaiorQ2(p, maior)) {
      maior = p;
    }

    if (EhProduto1MenorQ2(p, menor)) {
      menor = p;
    }
  }

  printf("MAIOR:");
  ImprimeProduto(maior);

  printf("MENOR:");
  ImprimeProduto(menor);

  return 0;
}
