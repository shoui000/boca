#include <stdio.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int min(int a, int b) {
  return (a > b) ? b : a;
}

int eMaior(int pessoa1[4], int pessoa2[4]) {
  int maiorNP1 = max(pessoa1[1], max(pessoa1[2], pessoa1[3]));
  int maiorNP2 = max(pessoa2[1], max(pessoa2[2], pessoa2[3]));

  if (maiorNP1 != maiorNP2) {
    return (maiorNP1 > maiorNP2);
  } else {
    int sP1 = pessoa1[1] + pessoa1[2] + pessoa1[3];
    int sP2 = pessoa2[1] + pessoa2[2] + pessoa2[3];

    int menorNP1 = min(pessoa1[1], min(pessoa1[2], pessoa1[3]));
    int menorNP2 = min(pessoa2[1], min(pessoa2[2], pessoa2[3]));

    if (sP1-menorNP1-maiorNP1 != sP2-menorNP2-maiorNP2) {
      return (sP1-menorNP1-maiorNP1 > sP2-menorNP2-maiorNP2);
    } else {
      if (menorNP1 != menorNP2) {
        return (menorNP1 > menorNP2);
      } else {
        return (pessoa1[0] < pessoa2[0]);
      }
    }
  }

  return 0;
}

int eMenor(int pessoa1[4], int pessoa2[4]) {
  int maiorNP1 = max(pessoa1[1], max(pessoa1[2], pessoa1[3]));
  int maiorNP2 = max(pessoa2[1], max(pessoa2[2], pessoa2[3]));

  if (maiorNP1 != maiorNP2) {
    return (maiorNP1 < maiorNP2);
  } else {
    int sP1 = pessoa1[1] + pessoa1[2] + pessoa1[3];
    int sP2 = pessoa2[1] + pessoa2[2] + pessoa2[3];

    int menorNP1 = min(pessoa1[1], min(pessoa1[2], pessoa1[3]));
    int menorNP2 = min(pessoa2[1], min(pessoa2[2], pessoa2[3]));

    if (sP1-menorNP1-maiorNP1 != sP2-menorNP2-maiorNP2) {
      return (sP1-menorNP1-maiorNP1 < sP2-menorNP2-maiorNP2);
    } else {
      if (menorNP1 != menorNP2) {
        return (menorNP1 < menorNP2);
      } else {
        return (pessoa1[0] > pessoa2[0]);
      }
    }
  }

  return 0;
}

int main(){
  int n;
  scanf("%d", &n);

  int campea[2][2] = { {-1, 0}, {-1, 0} };

  for (int i = 1; i <= n; i++) {
    int melhores[2][4] = { {-1, 0, 0, 0}, {-1, 0, 0, 0} };
    int piores[2][4] = { {-1, 0, 0, 0}, {-1, 0, 0, 0} };
    int somatorio[2] = { 0, 0 };

    while (1) {
      int id;
      scanf("%d", &id);

      if (id == -1) {
        break;
      } else {
        char sexo;
        scanf(" %c", &sexo);
        int pos = (sexo == 'M') ? 0 : 1;
        int notas[3];

        scanf("%d %d %d", &notas[0], &notas[1], &notas[2]);
        somatorio[pos] += max(notas[0], max(notas[1], notas[2]));

        // se for o primeiro homem ou mulher a ser declarado --- foi
        // se for o melhor homem ou melhor mulher
        int pessoa[4] = {id, notas[0], notas[1], notas[2]};
        if (melhores[pos][0] == -1 || eMaior(pessoa, melhores[pos])) {
          melhores[pos][0] = id; melhores[pos][1] = notas[0]; melhores[pos][2] = notas[1]; melhores[pos][3] = notas[2];
        } 

        if (piores[pos][0] == -1 || eMenor(pessoa, piores[pos])) {
          piores[pos][0] = id; piores[pos][1] = notas[0]; piores[pos][2] = notas[1]; piores[pos][3] = notas[2];
        }
      }
    }

    printf("MELHORES ATLETAS DA DELEGACAO %d\n", i); 
    printf("MASCULINO: %d ", melhores[0][0]);
    printf("FEMININO: %d\n", melhores[1][0]);
    printf("PIORES ATLETAS DA DELEGACAO %d\n", i); 
    printf("MASCULINO: %d ", *piores[0]);
    printf("FEMININO: %d\n", *piores[1]);
    printf("\n");

    for (int j = 0; j < 2; j++) {
      if (campea[j][0] == -1 || campea[j][1] < somatorio[j]) {
        campea[j][0] = i; campea[j][1] = somatorio[j];
      }
    }
  }

  printf("DELEGACAO CAMPEA:\n");
  printf("MASCULINO: %d ", campea[0][0]);
  printf("FEMININO: %d", campea[1][0]);

  return 0;
}
