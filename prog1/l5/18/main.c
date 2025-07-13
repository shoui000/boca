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
      scanf("%d", &m[(i * c) + j]);
    }
  }

  matriz matriz = {c, l, m};
  return matriz;
}

// matriz A precisa ter a quantidade de colunas iguais a quantidade de linhas de matriz B
int podeMultplicar(matriz a, matriz b) { return (a.c == b.l); }

// o resultado de uma multiplicacao de matrizes é
// se a matriz a tem A x B ( linha X coluna )
// e a matriz b tem C x D
// o resultado matriz C tem que ter A x D
matriz multiplicarMatriz(matriz a, matriz b) {
  matriz c;
  c.l = a.l;
  c.c = b.c;
  c.m = malloc((c.c * c.l) * sizeof(int));

  for (int i = 0; i < c.l; i++) {
    for (int j = 0; j < c.c; j++) {
      int elemento = 0;

      for (int x = 0; x < a.c; x++) {
        elemento += a.m[(i * a.c) + x] * b.m[(x * b.c) + j];
      }

      c.m[(i * c.c) + j] = elemento;
    }
  }

  return c;
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

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    matriz matrizA = leMatriz();
    matriz matrizB = leMatriz();

    if ( !podeMultplicar(matrizA, matrizB) ) {
      printf("IMPOSSIVEL\n");
    } else {
      matriz matrizC = multiplicarMatriz(matrizA, matrizB);
      imprimirMatriz(matrizC);

      free(matrizC.m);
    }

    putchar('\n');
    free(matrizA.m);
    free(matrizB.m);
  }

  return 0;
}
