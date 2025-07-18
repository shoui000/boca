#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
  int id, size;
  int nums[MAX_SIZE];
} tCartela;

tCartela leCartela();

void imprimeCartela(tCartela cartela);

int main() {
  tCartela cartela;

  cartela = leCartela();

  imprimeCartela(cartela);

  return 0;
}

tCartela leCartela() {
  tCartela t;
  scanf("%d %d\n", &t.id, &t.size);

  for (int i = 0; i < (t.size*t.size); i++) {
    scanf("%d ", &t.nums[i]);
  }

  return t;
}

void imprimeCartela(tCartela cartela) {
  printf("ID:%d\n", cartela.id);

  for (int i = 0; i < cartela.size; i++) {
    for (int j = 0; j < cartela.size; j++) {
      printf("%03d", cartela.nums[(j * cartela.size) + i]);

      if (j != cartela.size-1) {
        putchar('|');
      }
    }

    putchar('\n');
  }
}
