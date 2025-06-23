#include <stdio.h>
#include <math.h>
#include "ponto.h"

tPonto novoPonto(int x, int y){
  tPonto p = {x, y};
  
  return p;
}

tPonto lePonto(){
  tPonto p;
  scanf("%d %d", &p.x, &p.y);
  
  return p;
}

void imprimePonto(tPonto p){
  printf("(%d,%d)", p.x, p.y);
}

tPonto setX(tPonto p, int x){
  p.x = x;
  return p;
}

tPonto setY(tPonto p, int y){
  p.y = y;
  return p;
}

int getX(tPonto p){
  return p.x;
}

int getY(tPonto p){
  return p.y;
}

tPonto movPonto(tPonto p, int dX, int dY){
  p.x += dX;
  p.y += dY;

  return p;
}

float distanciaPontos(tPonto p1, tPonto p2){
  return sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));
}

int quadrantePonto(tPonto p){
  if (p.x == 0 || p.y == 0) {
    return 0;
  }

  if (p.x > 0 && p.y > 0) {
    return 1;
  }

  if (p.x < 0 && p.y > 0) {
    return 2;
  }

  if (p.x < 0 && p.y < 0) {
    return 3;
  }

  return 4;
}

tPonto getSimetrico(tPonto p) {
  tPonto pS = {-p.x, -p.y};
  return pS;
}
