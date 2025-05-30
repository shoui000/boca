#include <stdio.h>

int main() {

  int parenteses = 0;
  printf("RESP:");
  while(1) {
    char c;
    scanf("%c", &c);

    if (c == ')') {
      parenteses--;
    }

    if (parenteses == 0 && c == '.') {
      break;
    } else if (parenteses > 0) {
      printf("%c", c);
    }

    if (c == '(') {
      parenteses++;
    }
  }

  return 0;
}
