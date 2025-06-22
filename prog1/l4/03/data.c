#include <stdio.h>
#include "data.h"

int ehAnoBissexto(int ano){
  if (ano % 4 != 0) {
    return 0;
  }

  if (ano % 100 != 0) {
    return 1;
  }

  if (ano % 400 == 0) {
    return 1;
  }

  return 0;
}

tData leData() {
  int dia, mes, ano;
  scanf("%d %d %d", &dia, &mes, &ano);

  if (mes > 12) {
    mes = 12;
  }

  if (mes <= 0) {
    mes = 1;
  }

  if (dia <= 0) {
    dia = 1;
  }

  if (ano <= 0) {
    ano = 1;
  }

  int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (ehAnoBissexto(ano)) {
    meses[1] = 29;
  }

  if (dia > meses[mes-1]) {
    dia = meses[mes-1];
  }

  tData data = {dia, mes, ano};

  return data;
}

tData avancaDia(tData d){
  int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (ehAnoBissexto(d.ano)) {
    meses[1] = 29;
  }

  if (d.dia < meses[d.mes-1]) {
    d.dia++;

    return d;
  }

  if (d.mes < 12) {
    d.dia = 1;
    d.mes++;

    return d;
  }

  d.dia = 1;
  d.mes = 1;
  d.ano++;

  return d;
}

int ehIgual(tData d1, tData d2) {
  return (d1.ano == d2.ano &&
          d1.mes == d2.mes &&
          d1.dia == d2.dia);
}

int ehMaior(tData d1, tData d2) {
  if (d1.ano == d2.ano) {
    if (d1.mes == d2.mes) {
    } return d1.mes > d2.mes;
  } return d1.ano > d2.ano;
}

void imprimeData(tData d1) {
  printf("'%.2d/%.2d/%.4d'", d1.dia, d1.mes, d1.ano);
}
