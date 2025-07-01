#include <stdio.h>

int main() {
  int a, b;
  scanf("%d", &a);
  getchar();
  int vetor1[a];

  for (int i = 0; i < a; i++) {
    scanf("%d", &vetor1[i]);
    getchar();
  }

  scanf("%d", &b);
  int vetor2[b];

  for (int i = 0; i < b; i++) {
    scanf("%d", &vetor2[i]);
    getchar();
  }

  int diff = 1, diffLocal = 0, atLeastOne = 0;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if (vetor1[i] == vetor2[j]) {
        diffLocal = 1;
        break;
      }
    }

    diff = diffLocal && diff;
    atLeastOne = diffLocal || atLeastOne;
  }

  if (!atLeastOne) {
    printf("NENHUM");
    return 0;
  }

  if (diff) {
    printf("TODOS");
    return 0;
  }

  printf("PARCIAL");

  return 0;
}
