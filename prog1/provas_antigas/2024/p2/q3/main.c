#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 101
#define MAX_ARQUIVOS 100

typedef struct {
	char nome[MAX_STR_SIZE], extensao[MAX_STR_SIZE];
} tArquivo;

tArquivo tArquivo_le();
void tArquivo_imprime(tArquivo arquivo);
int tArquivo_ehExtensao(tArquivo arquivo, char *extensao);

typedef struct {
	char nome[MAX_STR_SIZE];
	int qtd_arquivo;
	tArquivo arquivos[MAX_ARQUIVOS];
} tPasta;

tPasta tPasta_le();
void tPasta_imprime(tPasta pasta, char *filtro);
tPasta tPasta_adicionaArquivo(tPasta pasta, tArquivo arquivo);
int tPasta_ehPasta(tPasta pasta, char *nome);

int main() {
	int n;
	scanf("%d", &n);

	tPasta pastas[n];

	for (int i = 0; i < n; i++) {
		pastas[i] = tPasta_le();
	}
    
	int q;
	scanf("%d", &q);

	char nome[MAX_STR_SIZE], extensao[MAX_STR_SIZE];
	for (int i = 0; i < q; i++) {
		scanf("%s %s", nome, extensao);

		for (int j = 0; j < n; j++) {
			if (tPasta_ehPasta(pastas[j], nome)) {
				tPasta_imprime(pastas[j], extensao);
				break;
			}
		}
	}

	return 0;
}

tArquivo tArquivo_le() {
	tArquivo a;
	scanf("%s", a.extensao);
	scanf("%s", a.nome);

	return a;
}

void tArquivo_imprime(tArquivo arquivo) {
	printf("(%s) %s\n", arquivo.extensao, arquivo.nome);
}

int tArquivo_ehExtensao(tArquivo arquivo, char *extensao) {
	if (strcmp(arquivo.extensao, extensao) == 0) {
		return 1;
	}

	return 0;
}

tPasta tPasta_le() {
    int d;
	tPasta p;
    p.qtd_arquivo = 0;
	scanf("%s %d", p.nome, &d);

    tArquivo arquivo;
    for (int i = 0; i < d; i++) {
        arquivo = tArquivo_le();
        p = tPasta_adicionaArquivo(p, arquivo);
	}

	return p;
}

void tPasta_imprime(tPasta pasta, char *filtro) {
	int f = strcmp(filtro, "-") == 0;
	printf("%s:\n", pasta.nome);
	for (int i = 0; i < pasta.qtd_arquivo; i++) {
		if (f || tArquivo_ehExtensao(pasta.arquivos[i], filtro)) {
			printf("  ");
			tArquivo_imprime(pasta.arquivos[i]);
		}
	}
}

tPasta tPasta_adicionaArquivo(tPasta pasta, tArquivo arquivo) {
	pasta.qtd_arquivo++;
    pasta.arquivos[pasta.qtd_arquivo-1] = arquivo;

	return pasta;
}

int tPasta_ehPasta(tPasta pasta, char *nome) {
	if (strcmp(pasta.nome, nome) == 0) {
		return 1;
	}

	return 0;
}