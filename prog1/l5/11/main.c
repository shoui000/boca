#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* vetor, int qtd){
  int swaps = 0;
  do {
    swaps = 0;
    for (int i = 0; i < (qtd-1)/2; i++) {
      if (vetor[i * 2 + 0] > vetor[(i+1) * 2 + 0]) {
        int temp = vetor[(i+1) * 2 + 0];
        vetor[(i+1) * 2 + 0] = vetor[i * 2 + 0];
        vetor[i * 2 + 0] = temp;

        char ctemp = vetor[(i+1) * 2 + 1];
        vetor[(i+1) * 2 + 1] = vetor[i * 2 + 1];
        vetor[i * 2 + 1] = ctemp;
        swaps++;
      }
    }
  } while (swaps);
}

void imprimeVetor(int vetor[], int qtd) {
  printf("{");
  for (int i = 0; i < qtd; i++) {
    printf("%d", vetor[i]);

    if (i != qtd-1) {
      printf(", ");
    }
  }

  printf("}\n");
}

void* juntaVetores(int vetorA[], int qtdA, int vetorB[], int qtdB) {
  int *vetorC = (int *)malloc((qtdA+qtdB) * 2 * sizeof(int));
  for (int i = 0; i < qtdA; i++) {
    vetorC[i * 2 + 0] = vetorA[i];
    vetorC[i * 2 + 1] = 'A';
  }

  for (int i = 0; i < qtdB; i++) {
    vetorC[(i+qtdA) * 2 + 0] = vetorB[i];
    vetorC[(i+qtdA) * 2 + 1] = 'B';
  }

  return vetorC;
}

void imprimeOrigem(int vetorC[], int qtd) {
  for (int i = 1; i < qtd; i+=2) {
    printf("%c", vetorC[i]);
  }
}

int main() {
  int qtdA;
  scanf("%d", &qtdA);

  int vetorA[qtdA];
  for (int i = 0; i < qtdA; i++) {
    scanf("%d", &vetorA[i]);
  }

  int qtdB;
  scanf("%d", &qtdB);

  int vetorB[qtdB];
  for (int i = 0; i < qtdB; i++) {
    scanf("%d", &vetorB[i]);
  }

  int* vetorC = juntaVetores(vetorA, qtdA, vetorB, qtdB);
  int qtdC = (qtdA + qtdB) * 2;
  bubbleSort(vetorC, qtdC);
  imprimeOrigem(vetorC, qtdC);

  return 0;
}

/*
 * explicação do código: ele Le os dois vetores e junta em um grande vetor
 * nesse vetor grande (chamamos de vetorC), ele possui o tamanho igual o tamanho
 * dos outros dois vetores * 2, porque ele guarda, não só os elementos dos vetores,
 * bem como suas posições.
 *
 * como ele faz isso? ele guarda os elementos do vetor em posições pares e suas origens
 * em posições ímpares
 *
 * ele funciona como se fosse uma matrix, porém, como um grande vetorzão
 */
