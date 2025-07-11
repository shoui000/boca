#include <stdio.h>

typedef struct{
  int codigo;
  char sobrenome[21];
  char nome[21];
  int nota;
  int idade;
} tCandidato;

tCandidato LeCandidato();

void ImprimeCandidato(tCandidato candidato) {
  printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", 
      candidato.codigo, candidato.nome, candidato.sobrenome,
      candidato.nota, candidato.idade);
}

int ComparaString(char * str1, char * str2) {
  int i = 0;
  while (1) {
    if (str1[i] != str2[i]) {
      return 0;
    }

    if (str1[i] == '\0') {
      break;
    }

    i++;
  }

  return 1;
}

int main(){
  int qtdCand, i = 0;
  scanf("%d", &qtdCand);

  tCandidato candidatos[qtdCand];

  for(i = 0; i < qtdCand; i++){
    candidatos[i] = LeCandidato();
  }

  int impressos[qtdCand];
  for (i = 0; i < qtdCand; i++) { impressos[i] = 0; }

  for (i = 0; i < qtdCand; i++) {
    for (int j = i; j < qtdCand; j++) {
      if (j == i) {
        continue;
      }

      if ( ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome) ) {
        if ( !impressos[i] ) {
          ImprimeCandidato(candidatos[i]);
          impressos[i] = 1;
        }

        if ( !impressos[j] ) {
          ImprimeCandidato(candidatos[j]);
          impressos[j] = 1;
        }
      }
    }
  }

  return 0;
}

tCandidato LeCandidato(){
  tCandidato candidato;

  scanf("%*[^{]");
  scanf("%*[{ ]");
  scanf("%d", &candidato.codigo);
  scanf("%*[, ]");
  scanf("%[^,],", candidato.sobrenome);
  scanf("%*[ ]");
  scanf("%[^,],", candidato.nome);
  scanf("%d", &candidato.nota);
  scanf("%*[, ]");
  scanf("%d", &candidato.idade);
  scanf("%*[^\n]\n");

  return candidato;
}
