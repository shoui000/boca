#include <stdio.h>

int ValidarPlaca();

int EhLetraMaiuscula(char c);

int EhDigito(char c);

void ImprimirRegiao(int n);

int main() {
	int x;
	scanf("%d", &x);
	getchar();
	for (int i = 0; i < x; i++) {
		int z = ValidarPlaca();
		if (z == -1) {
			printf("INVALIDA");
		} else {
			printf("VALIDA ");
			ImprimirRegiao(z);
		}

		printf("\n");
	}
	return 0;
}

int ValidarPlaca() {
	char c;
	int i = 0;
	int sum = 0;
	int valido = 1;

	int modelo[7] = {0, 0, 0, 1, 0, 1, 1};
	while (1) {
		scanf("%c", &c);
		if (c == '\n'){
			break;
		}

		if ( (EhDigito(c) != modelo[i]) || (i >= 7) || (modelo[i] == 0 && !EhLetraMaiuscula(c)) ) {
			valido = 0;
		}
		
		if (EhDigito(c)) {
			sum += c - 48;
		}

		i++;
	}
	
	return ( valido ? ( i == 7 ? sum : -1) : -1);
}

void ImprimirRegiao(int n) {
	switch (n % 5) {
		case 0:
			printf("SUL");
			break;
		case 1:
			printf("SUDESTE");
			break;
		case 2:
			printf("CENTRO-OESTE");
			break;
		case 3:
			printf("NORTE");
			break;
		case 4:
			printf("NORDESTE");
			break;
	}
}

int EhDigito(char c) {
	return (c >= '0' && c <= '9');
}

int EhLetraMaiuscula(char c) {
	return (c >= 'A' && c <= 'Z');
}
