#ifndef DATA
#define DATA

typedef struct {
  int dia;
  int mes;
  int ano;
} tData;

tData leData();

tData avancaDia(tData d);

int ehAnoBissexto(int ano);

int ehIgual(tData d1, tData d2);

int ehMaior(tData d1, tData d2);

void imprimeData(tData d1);

#endif // !DATA
