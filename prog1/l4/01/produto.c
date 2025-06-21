#include <stdio.h>
#include "produto.h"

tProduto LeProduto() {
  tProduto p;

  scanf("%d;%f;%d", &p.codigo, &p.preco, &p.qtd);

  return p;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2) {
  return p1.preco > p2.preco;
}

int EhProduto1MenorQ2(tProduto p1, tProduto p2) {
  return p1.preco < p2.preco;
}

int TemProdutoEmEstoque(tProduto p) {
  return p.qtd > 0;
}

void ImprimeProduto(tProduto p) {
  printf("COD %d, PRE %.2f, QTD %d\n", p.codigo, p.preco, p.qtd);
}

