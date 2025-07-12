#include <stdio.h>
#include <string.h>

typedef struct{
  int codigo;
  char sobrenome[21];
  char nome[21];
  int nota;
  int idade;
} tCandidato;

tCandidato LeCandidato();

void ImprimeCandidato(tCandidato candidato);

int ehMaior(tCandidato candidato1, tCandidato candidato2) {
  if ( candidato1.nota != candidato2.nota ) {
    return candidato1.nota < candidato2.nota;
  }

  if ( candidato1.idade != candidato2.idade ) {
    return candidato1.idade > candidato2.idade;
  }

  return candidato1.codigo > candidato2.codigo;
}

void OrdenaCrescente(tCandidato * vet, int qtd) {
  int swaps = 0, nome = 0, sobrenome = 0;
  do {
    swaps = 0;
    for (int i = 0; i < qtd-1; i++) {
      if ( ehMaior(vet[i], vet[i+1]) ){
        tCandidato temp = vet[i+1];
        vet[i+1] = vet[i];
        vet[i] = temp;
        swaps++;
      }
    }
  } while (swaps);
}

int main(){
  int qtdCand, i = 0, j;
  scanf("%d", &qtdCand);

  tCandidato candidatos[qtdCand];
  for(i = 0; i < qtdCand; i++){
    candidatos[i] = LeCandidato();
  }

  OrdenaCrescente(candidatos, qtdCand);

  for(i = 0; i < qtdCand; i++){
    ImprimeCandidato(candidatos[i]);
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

void ImprimeCandidato(tCandidato candidato){
  printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
      candidato.codigo, candidato.nome,
      candidato.sobrenome, candidato.nota, candidato.idade);
}
