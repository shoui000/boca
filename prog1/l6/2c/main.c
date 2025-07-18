#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
  int id, size, venceu;
  int nums[MAX_SIZE];
  int marcas[MAX_SIZE];
} tCartela;

tCartela leCartela();
void imprimeCartela(tCartela cartela);
tCartela marcaCartela(tCartela c, int n);
int venceuCartela(tCartela c);
tCartela resetaCartela(tCartela c);
void imprimeMarcas(tCartela cartela);

typedef struct {
  int size;
  tCartela cartelas[MAX_SIZE];
} tPartida;

tPartida leCartelasPartida();
void imprimeInvCartelasPartida(tPartida p);
tPartida resetaPartida(tPartida p);
void jogaPartida(tPartida p);

int main() {
  tPartida partida;
  int qtdPartidas, i;

  partida = leCartelasPartida();

  scanf("%d", &qtdPartidas);
  for (i = 0; i < qtdPartidas; i++) {
    if (i != 0) { putchar('\n'); }

    printf("PARTIDA %d\n", i+1);
    partida = resetaPartida(partida);
    jogaPartida(partida);
  }

  return 0;
}

tCartela leCartela() {
  tCartela t;
  scanf("%d %d\n", &t.id, &t.size);

  for (int i = 0; i < (t.size*t.size); i++) {
    scanf("%d ", &t.nums[i]);
  }

  t.venceu = 0;

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

tPartida leCartelasPartida() {
  tPartida p;
  scanf("%d", &p.size);

  for (int i = 0; i < p.size; i++) {
    p.cartelas[i] = leCartela();
  }

  return p;
}

void imprimeInvCartelasPartida(tPartida p) {
  for (int i = p.size-1; i >= 0; i--) {
    imprimeCartela(p.cartelas[i]);
  }
}

tPartida resetaPartida(tPartida p) {
  for (int i = 0; i < p.size; i++) {
    p.cartelas[i] = resetaCartela(p.cartelas[i]);
  }
  
  return p;
}

tCartela resetaCartela(tCartela c) {
  for (int i = 0; i < (c.size*c.size); i++) {
    c.marcas[i] = 0;
  }

  return c;
}

void jogaPartida(tPartida p) {
  int n, venceu = 0;
  while (1) {
    scanf("%d", &n);

    if (n == -1) { break; }

    if (!venceu) {
      for (int i = 0; i < p.size; i++) {
        p.cartelas[i] = marcaCartela(p.cartelas[i], n);

        if (p.cartelas[i].venceu) {
          venceu = 1;
        }
      }
    }
  }

  if (venceu == 0) {
    printf("SEM VENCEDOR\n");
    return;
  }

  printf("COM VENCEDOR\n");

  for (int i = 0; i < p.size; i++) {
    if (p.cartelas[i].venceu) {
      imprimeCartela(p.cartelas[i]);
    }
  }

}

tCartela marcaCartela(tCartela c, int n) {
  for (int i = 0; i < (c.size*c.size); i++) {
      if (c.nums[i] == n) { 
        c.marcas[i] = 1;
        break;
      }
  }

  if (venceuCartela(c)) { c.venceu = 1; }

  return c;
}

int venceuCartela(tCartela c) {
  for (int i = 0; i < (c.size*c.size); i++) {
    if (c.marcas[i] == 0) { return 0; break; }
  }

  return 1;
}

void imprimeMarcas(tCartela cartela) {
  printf("ID:%d\n", cartela.id);

  for (int i = 0; i < cartela.size; i++) {
   for (int j = 0; j < cartela.size; j++) {
      printf("%03d", cartela.marcas[(j * cartela.size) + i]);

      if (j != cartela.size-1) {
        putchar('|');
      }
    }

    putchar('\n');
  }
}
