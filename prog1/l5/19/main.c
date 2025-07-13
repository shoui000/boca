#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int c, l;
  int* m;
} matriz;

matriz leMatriz() {
  int c, l;
  scanf("%d %d", &c, &l);

  int* m = malloc((c * l) * sizeof(int));
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      scanf("%1d", &m[(i * c) + j]);
    }
  }

  matriz matriz = {c, l, m};
  return matriz;
}

void imprimirMatriz(matriz m) {
  for (int i = 0; i < m.l; i++) {
    for (int j = 0; j < m.c; j++) {
      printf("%d", m.m[(i * m.c) + j]);

      if (j != m.c-1) { putchar(' '); }
    }

    putchar('\n');
  }
}

void evoluiAgua(matriz m) {
  for (int i = 1; i < m.l-1; i++) {
    for (int j = 1; j < m.c-1; j++) {
      if (m.m[(i * m.c) + j] > 0) { continue; }

      if ( m.m[((i-1) * m.c) + j] == 1 ||
           m.m[(i * m.c) + j-1] == 1 ||
           m.m[(i * m.c) + j+1] == 1 ||
           m.m[((i+1) * m.c) + j] == 1) {
        m.m[(i * m.c) + j] = 2;
      }

    }
  }

  for (int i = 1; i < m.l-1; i++) {
    for (int j = 1; j < m.c-1; j++) {
      if (m.m[(i * m.c) + j] == 2) {
        m.m[(i * m.c) + j] = 1;
      }
    }
  }
}

int contaTerra(matriz m) {
  int soma = 0;

  for (int i = 0; i < m.l; i++) {
    for (int j = 0; j < m.c; j++) {
      if (m.m[(i * m.c) + j] == 0) {
        soma++;
      }
    }
  }

  return soma;
}

int main() {
  int h;
  scanf("%d", &h);
  matriz m = leMatriz();
  printf("%d ", contaTerra(m));

  for (int i = 0; i < h; i++) {
    evoluiAgua(m);
  }
  printf("%d\n", contaTerra(m));

  return 0;
}
