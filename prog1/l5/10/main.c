#include <stdio.h>

int TaOrdenado(int vet[], int qtd) {
	for (int i = 0; i < qtd-1; i++) {
		if (vet[i] > vet[i+1]) {
			return 0;
			break;
		}
	}

	return 1;
}

void trocaDeOrdem(int i, int vet[]) {
	int temp = vet[i];
	vet[i] = vet[i+1];
	vet[i+1] = temp;
}

void OrdenaCrescente(int vet[], int qtd) {
	while ( !TaOrdenado(vet, qtd) ) {
		for (int i = 0; i < qtd-1; i++) {
			if (vet[i] > vet[i+1]) {
				trocaDeOrdem(i, vet);
			}
		}
	}
}

void ImprimeDadosDoVetor(int vet[], int qtd) {
	printf("{");
	for (int i = 0; i < qtd; i++) {
		printf("%d", vet[i]);

		if (i != qtd-1) {
			printf(", ");
		}
	}

	printf("}");
}

int main() {
	int n;
	scanf("%d", &n);
	int vetor[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
	}

	OrdenaCrescente(vetor, n);
	ImprimeDadosDoVetor(vetor, n);
	return 0;
}
