#include <stdio.h>

int main() {
  int pNum;
  int menor;
  int i = 0;
  while (scanf("%d", &pNum)) {
    if (i == 0 || pNum < menor) {
      menor = pNum;
    }
    
    i++;
  }

  while (getchar() != '\n');

  int sNum;
  int primeira, ultima, presente=0;
  i = 0;
  while (scanf("%d", &sNum)) {
    if (sNum == menor) {
      if (i == 0 || !presente) {
        primeira = i;
        ultima = i;
      } else if (i > ultima) {
        ultima = i;
      }

      presente = 1;
    }
    i++;
  }
  
  if (!presente) {
    primeira = i;
    ultima = i;
  }

  printf("%d %d %d", menor, primeira, ultima);
  return 0;
}
