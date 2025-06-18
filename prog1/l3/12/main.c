#include <stdio.h>
#include <math.h>

int somaDosDigitos(int n) {
  if (n >= 0 && n <= 9) {
    return n;
  }

  int sum = 0;
  int x = log10(n);

  for (int i = x; i >= 0; i--) {
    int z = (int)(n / pow(10, i));
    n -= z * pow(10, i);
    sum += z;
  }

  return sum;
}

void parImpar(int n) {
  if (n % 2 == 0) {
    printf("Par ");
  } else {
    printf("Impar ");
  }
}

int verificaPrimo(int n) {
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

void valorPrimo(int n) {
  if (verificaPrimo(n)) {
    printf("Primo");
  } else {
    printf("Nao e primo");
  }
}

int main() {
  int n, x;
  scanf("%d", &n);
  x = somaDosDigitos(n);

  while (1) {
    printf("%d ", x);
    parImpar(x);
    valorPrimo(x);
    printf("\n");

    if (x >= 0 && x <= 9) {
      break;
    }

    x = somaDosDigitos(x);
  }

  return 0;
}
