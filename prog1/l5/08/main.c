#include <stdio.h>

void ImprimeDadosDoVetor(int vet[], int qtd) {
  printf("{");
  for (int i = 0; i < qtd; i++) {
    printf("%d", vet[i]);

    if (qtd-i > 1) {
      printf(", ");
    }
  }
  printf("}");
}

void TrocaParEImpar(int vet[], int qtd) {
  for (int i = 0; i < qtd-1; i+=2) {
    int temp = vet[i+1];
    vet[i+1] = vet[i];
    vet[i] = temp;
  }

  ImprimeDadosDoVetor(vet, qtd);
}

int main() {
  int qtd;
  scanf("%d ", &qtd);
  int vetor[qtd];
  
  for (int i = 0; i < qtd; i++) {
    scanf("%d ", &vetor[i]);
  }

  TrocaParEImpar(vetor, qtd);

  return 0;
}
