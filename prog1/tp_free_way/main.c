#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERRO: Informe o diretorio com os arquivos de configuracao.\n");
    exit(1);
  }

  exit(0);
}
