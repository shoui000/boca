#include <stdio.h> 

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	if (a != 1 && a != 2) {
		printf("Operacao invalida.");
	} else {
		getchar();

		char c;
		while(scanf("%c", &c)){
			if (c >= 97 && c <= 122) {
				switch (a) {
					case 1:
						printf("%c", ((c - 97 + b) % 26) + 97);
						break;
					case 2:
            c -= b % 26;
            while (c < 97) {
              c += 26;
            }
            printf("%c", c);
            break;
				}
			} else {
				printf("%c", c);
			}

			if (c == '.'){ break; }
		}

	}

	return 0;
}
