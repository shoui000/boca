#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 101
#define MAX_ARQUIVOS 100

typedef struct {
	int tamanho;
	char nome[MAX_STR_SIZE], extensao[MAX_STR_SIZE];
} tArquivo;

tArquivo tArquivo_le();
void tArquivo_imprime(tArquivo arquivo);
int tArquivo_ehExtensao(tArquivo arquivo, char *extensao);
int tArquivo_qualTamanho(tArquivo arquivo);

typedef struct {
	int qtd_arquivo, tamanho_maximo, tamanho_atual;
	char nome[MAX_STR_SIZE];
	tArquivo arquivos[MAX_ARQUIVOS];
} tPasta;

tPasta tPasta_le();
void tPasta_imprime(tPasta pasta, char *filtro);
tPasta tPasta_adicionaArquivo(tPasta pasta, tArquivo arquivo);
int tPasta_ehPasta(tPasta pasta, char *nome);
int tPasta_cabeArquivo(tPasta pasta, tArquivo arquivo);

int main() {
	int n;
	scanf("%d", &n);

	tPasta pastas[n];

	for (int i = 0; i < n; i++) {
		pastas[i] = tPasta_le();
	}
    
	int q, x = 0;
	scanf("%d", &q);

	char pasta[MAX_STR_SIZE];
	tArquivo arquivo;
	for (int i = 0; i < q; i++){
		scanf("%s", pasta);
		arquivo = tArquivo_le();

		x = 0;
		for (int j = 0; j < n; j++) {
			if (tPasta_ehPasta(pastas[j], pasta)) {
				pastas[j] = tPasta_adicionaArquivo(pastas[j], arquivo);
				x = 1;
				break;
			}
		}

		if (!x) {
			printf("ERRO: Pasta %s nao encontrada.\n", pasta);
		}
	}

	for (int i = 0; i < n; i++){
		tPasta_imprime(pastas[i], "-");
	}

	return 0;
}

tArquivo tArquivo_le() {
	tArquivo a;
	scanf("%s %s %d", a.extensao, a.nome, &a.tamanho);

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
	p.tamanho_atual = 0;
	scanf("%s %d %d", p.nome, &d, &p.tamanho_maximo);

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
	if (tPasta_cabeArquivo(pasta, arquivo)){
		pasta.qtd_arquivo++;
		pasta.arquivos[pasta.qtd_arquivo - 1] = arquivo;
		pasta.tamanho_atual += arquivo.tamanho;
	} else {
		printf("ERRO: Arquivo nao cabe na pasta %s.\n", pasta.nome);
	}

	return pasta;
}

int tPasta_ehPasta(tPasta pasta, char *nome) {
	if (strcmp(pasta.nome, nome) == 0) {
		return 1;
	}

	return 0;
}

int tArquivo_qualTamanho(tArquivo arquivo) {
	return arquivo.tamanho;
}

int tPasta_cabeArquivo(tPasta pasta, tArquivo arquivo) {
	if (arquivo.tamanho + pasta.tamanho_atual > pasta.tamanho_maximo){
		return 0;
	}

	return 1;
}