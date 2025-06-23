#include <stdio.h>

int main() {
  char c;
  scanf("%c", &c);
  getchar();

  if (c == 'R') {
    char caractere;
    int altura, base;
    scanf("%c ", &caractere);
    scanf("%d %d", &altura, &base);

    for (int i = 0; i < altura; i++) {
      for (int j = 0; j < base; j++) {
        printf("%c", caractere);
      }

      printf("\n");
    }

  } else if (c == 'T') {
    char caractere, modo;
    int lado, x;
    scanf("%c ", &caractere);
    scanf("%d ", &lado);
    scanf("%c", &modo);

    for (int i = 0; i < lado; i++) {
      x = (modo == 'C') ? i+1 : lado-i;

      for (int j = 0; j < x; j++) {
        printf("%c", caractere);
      }

      printf("\n");
    }

  } else if (c == 'Q') {
    char mB, dP, mC;
    int lado;
    scanf("%c ", &mB);
    scanf("%c ", &dP);
    scanf("%c ", &mC);
    scanf("%d", &lado);

    for (int i = 0; i < lado; i++) {
      for (int j = 0; j < lado; j++) {
        if (i == j) {
          printf("%c", dP);
        } else if (j > i) {
          printf("%c", mC);
        } else {
          printf("%c", mB);
        }
      }

      printf("\n");
    }

  } else {
    printf("NAO EH FORMA VALIDAAAAAA!!!!!!!\n");
  }

  return 0;
}
