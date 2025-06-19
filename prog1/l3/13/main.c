#include <stdio.h>

int EhLetra(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int CalculaValorPalavra() {
  char c;
  int sum = 0;
  while (1) {
    int z = scanf("%c", &c);

    if (EhLetra(c)) {
      int x, valor;
      x = (c >= 'A' && c <= 'Z') ? 'A' - 27 : 'a' - 1;
      valor = c - x;

      sum += valor;
    }

    if (c == '\n') break;
    if (z == EOF) break;
  }

  return sum;
}

int EhPrimo(int n) {
  if (n == 0 || n == 1) {
    return 0;
  } else {
    for (int i = 2; i <= n/2; i++) {
      if (n % i == 0) {
        return 0;
        break;
      }
    }

    return 1;
  }
}

int ProximoPrimo(int n) {
  if (EhPrimo(n)) {
    return n;
  }

  int x = (n < 0) ? -n : n;
  int i = x;
  while (1) {
    if (i == 32767) {
      return n;
    }

    if (EhPrimo(i)) {
      return (n < 0) ? -i : i;
    }

    i++;
  }

  return 0;
}

int main() {
  int x;

  while(1) {
    x = CalculaValorPalavra();
    
    if (x == 0) {
      break;
    }

    if (EhPrimo(x)) {
      printf("E primo\n");
    } else {
      printf("Nao e primo ");
      printf("%d\n", ProximoPrimo(x));
    }
  }
  return 0;
}
