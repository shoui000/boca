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

void InverteVetor(int *vet, int qtd) {
  for (int i = 0; i < qtd/2; i++) {
    int temp = vet[qtd-1-i];
    vet[qtd-1-i] = vet[i];
    vet[i] = temp;
  }
}

int main() {
  int qtd;
  scanf("%d ", &qtd);

  int vetor[qtd];
  for (int i = 0; i < qtd; i++) {
    scanf("%d ", &vetor[i]);
  }

  InverteVetor(vetor, qtd);
  ImprimeDadosDoVetor(vetor, qtd);

  return 0;
}
