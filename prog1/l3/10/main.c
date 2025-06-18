#include <stdio.h>

int EhLetraMaiuscula(char c) { return (c >= 'A' && c <= 'Z'); }
int EhLetraMinuscula(char c) { return (c >= 'a' && c <= 'z'); }
int EhLetra(char c) { return (EhLetraMaiuscula(c) || EhLetraMinuscula(c)); }

char Codifica(char letra, int n) {
  int b = EhLetraMaiuscula(letra) ? 2 * n : n;
  int z = EhLetraMaiuscula(letra) ? 'A' : 'a';

  return (((letra - z + b) % 26) + z);
}

char Decodifica(char letra, int n) {
  int b = EhLetraMaiuscula(letra) ? 2 * n : n;
  int z = EhLetraMaiuscula(letra) ? 'A' : 'a';

  letra -= b % 26;
  while (letra < z) {
    letra += 26;
  }

  return letra;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

	if (a != 1 && a != 2) {
		printf("Operacao invalida.");
	} else {
		getchar();

		char c;
		while(scanf("%c", &c) == 1){
			if (EhLetra(c)) {
        char r = (a == 1) ? Codifica(c, b) : Decodifica(c, b);
        printf("%c", r);
			} else {
				printf("%c", c);
			}
			if (c == '.'){ break; }
		}

	}

	return 0;
}
