#include <stdio.h>
#include <math.h>

int EhPalindromo(int num) {
  int x = log10(num);
  for (int i = x; i >= 0; i -= 2) {
    int y = (num > 9) ? num / pow(10, i) : num;
    int z = num % 10;

    if (y != z) {
      return 0;
      break;
    }

    num -= y * pow(10, i);
    num /= 10;
  }

  return 1;
}

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    printf(EhPalindromo(n) ? "S\n" : "N\n");
  }
  return 0;
}
