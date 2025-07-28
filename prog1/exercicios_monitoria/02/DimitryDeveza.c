#include <stdio.h>

#define ESCOVADO 1
#define ARRUMADA 1
#define PREPARADO 1
#define PENDENTE 0

int EscovarDentes(){
  printf("Escovando os dentes!\n");
  return ESCOVADO;
}

int ArrumarCama(){
  printf("Arrumando a cama!\n");
  return ARRUMADA;
}

int PrepararCafe(){
  printf("Preparando o cafe!\n");
  return PREPARADO;
}

int main() {
  int dentes = PENDENTE, cama = PENDENTE, cafe = PENDENTE, option, tempo = 15;
  while (1) {
    scanf("%d", &option);

    if (option == 0) {
      if (dentes && cama && cafe) {
        printf("Saindo de casa!\n");
        break;
      } else {
        printf("### Ainda ha tarefas pendentes! ###\n");
      }
    } else if (option == 1) {
      if (dentes == PENDENTE) {
        dentes = EscovarDentes();
      } else {
        printf("Isso ja foi feito!\n");
      }

      tempo -= 2;
      printf("Tempo restante: %d minutos\n", tempo);
    } else if (option == 2) {
      if (cama == PENDENTE) {
        cama = ArrumarCama();
      } else {
        printf("Isso ja foi feito!\n");
      }

      tempo -= 3;
      printf("Tempo restante: %d minutos\n", tempo);
    } else if (option == 3) {
      if (cafe == PENDENTE) {
        cafe = PrepararCafe();
      } else {
        printf("Isso ja foi feito!\n");
      }

      tempo -= 5;
      printf("Tempo restante: %d minutos\n", tempo);
    }

    if (tempo <= 0) {
      printf("### Perdeu o onibus! ###");
      break;
    }

  }

  return 0;
}

// que código feio do cão, dava pra fazer melhor
