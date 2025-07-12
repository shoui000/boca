#include <stdio.h>

#define MAX_SIZE 500

int main() {
  char matriz[MAX_SIZE][MAX_SIZE];
  char letra;
  int i = 0, j = 0;
  while ( scanf("%c", &letra) == 1) {

    if ( letra >= 'A' && letra <= 'Z' || letra >= 'a' && letra <= 'z' ) {
      matriz[i][j] = letra;
      j++;
      continue;
    }

    if ( j != 0 ) {
      matriz[i][j] = '\0';
      i++;
      j = 0;
    }
  }

  for (int x = i+1; x < MAX_SIZE; x++) {
    matriz[x][0] = '\0';
  }

  for (int x = MAX_SIZE-1; x >= 0; x--) {
    if (matriz[x][0] == '\0') { continue; }

    printf(" %s", matriz[x]);
  }

  printf(" ");

  return 0;
}
