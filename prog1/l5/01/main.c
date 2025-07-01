#include <math.h>
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  
  int notas[n];
  int nota = 0, menor = 0, maior = 0, acimaMedia = 0, reprovados = 0;
  double media = 0;

  for (int i = 0; i < n; i++) {
    scanf("%d ", &nota);

    notas[i] = nota;
    media += nota;
    
    if (nota < 70) {
      reprovados++;
    }

    if (i == 0 || nota < menor) {
      menor = nota;
    }

    if (i == 0 || nota > maior) {
      maior = nota;
    }
  }

  media /= n;
  double desvioPadrao = 0;

  for (int i = 0; i < n; i++) {
    desvioPadrao += pow(notas[i] - media, 2);
    if (notas[i] > media) {
      acimaMedia++;
    }
  }

  desvioPadrao = sqrt(desvioPadrao / n);

  printf("MENOR:%d, MAIOR:%d, MEDIA:%.2lf, STD:%.2lf, ACIMA_MEDIA_CONC:%d, REPROV:%d",
      menor, maior, media, desvioPadrao, acimaMedia, reprovados);

  return 0;
}
