#include <stdio.h>

typedef struct {
  int A, D, N;
/*
Contém as informações do Pokémon, incluindo dados necessários para cálculo de poder e o valor
*/
} Pokemon;

/*
Lê um Pokémon da entrada padrão e retorna a struct preenchida
*/
Pokemon lerPokemon() {
  int a, d, n;
  scanf("%d", &a);
  scanf("%d", &d);
  scanf("%d", &n);

  Pokemon p = {a, d, n};
  return p;
}

/*
Verifica se um número é primo.
Retorna 1 se for primo, 0 caso contrário.
*/
int ehPrimo(int n) {
  int x = n/2;
  
  if (n < 2) {
    return 0;
  }

  for (int i = 2; i <= x; i++) {
    if (n % i == 0) {
      return 0;
    }
  }

  return 1;
}

/*
Calcula o poder de combate do Pokémon.
Retorna o valor calculado.
*/
float CalculaValor(int bonus, Pokemon p) {
  float poder;
  poder = ((p.A + p.D) / 2.0 );

  if (ehPrimo(p.N)) {
    poder += bonus;
  }

  return poder;
}

/*
Imprime o resultado da batalha entre dois Pokémons no formato especificado.
*/
void ImprimeResultado(Pokemon p1, Pokemon p2, int bonus) {
  int poder1, poder2;
  poder1 = CalculaValor(bonus, p1);
  poder2 = CalculaValor(bonus, p2);

  if (poder1 > poder2) {
    printf("Primeiro");
  } else if (poder1 < poder2) {
    printf("Segundo");
  } else if (poder1 == poder2) {
    printf("Empate");
  }

  printf("\n");
}

int main() {
  int n, bonus;
  scanf("%d\n%d", &n, &bonus);

  for (int i = 0; i < n; i++) {
    Pokemon p1 = lerPokemon();
    Pokemon p2 = lerPokemon();

    ImprimeResultado(p1, p2, bonus);
  }
}
