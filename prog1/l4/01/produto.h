#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
  int codigo;
  float preco;
  int qtd;
} tProduto;

tProduto LeProduto();

int EhProduto1MaiorQ2(tProduto p1, tProduto q2);

int EhProduto1MenorQ2(tProduto p1, tProduto q2);

int TemProdutoEmEstoque(tProduto p);

void ImprimeProduto(tProduto p);

#endif // !PRODUTO_H
