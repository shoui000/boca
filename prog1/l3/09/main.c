#include <stdio.h>

int verificapH(float pH) {
  if (pH < 7) {
    return 1;
  } 

  if (pH > 7) {
    return 2;
  }

  return 0;
}

int verificaGotaChuvaAcida(float pH) {
  if (pH < 5.7) {
    return 1;
  }

  return 0;
}

float porcentagem(float total, float valor) {
  return (100.0 * valor) / total;
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal) {
  if (porcentagemGotasChuvaAcida >= 75) {
    printf("Chuva Acida ");
  } else if (porcentagemGotasChuvaNormal >= 75) {
    printf("Chuva Normal ");
  } else {
    printf("Chuva com indicios de chuva acida ");
  }

  printf("%.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
}

int main() {
  int area, densidade, tempo;
  scanf("%d %d %d", &area, &densidade, &tempo);

  int quantidadeGota = area * densidade * tempo;

  if (quantidadeGota == 0) {
    printf("Nenhuma gota foi avaliada");
  } else {
    float gotas[7] = {0, 0, 0, 10000, 10000, 0, 0};
    // qtNeutro, qtAcido, qtBasico, maxNeutro, maxAcido, maxBasico, qtChuvaAcida

    for (int i = 0; i < quantidadeGota; i++) {
      float g;
      scanf("%f", &g);
      int z = verificapH(g);
      gotas[z] += 1;
      if (verificaGotaChuvaAcida(g)) {
        gotas[6]++;
      }

      // define o mais neutro
      float dif = g - 7;
      float prevDif = gotas[3] - 7;
      dif = (dif < 0) ? -dif : dif;
      prevDif = (prevDif < 0) ? -prevDif : prevDif;
      gotas[3] = (dif < prevDif) ? g : gotas[3];

      if (z == 1) {
        gotas[z+3] = (g < gotas[z+3]) ? g : gotas[z+3];
      } else if (z == 2) {
        gotas[z+3] = (g > gotas[z+3]) ? g : gotas[z+3];
      }
    }

    printf("%.0f %.0f %.0f %.2f %.2f %.2f\n", 
        gotas[1], gotas[2], gotas[0], gotas[4], gotas[5], gotas[3]);

    imprimeResultadosAnalise(porcentagem(quantidadeGota, gotas[6]), 
        porcentagem(quantidadeGota, quantidadeGota-gotas[6]));
  }

  return 0;
}
