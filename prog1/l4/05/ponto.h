#ifndef ponto
#define ponto

typedef struct {
  int x, y;
} tPonto;

tPonto novoPonto(int x, int y);

tPonto lePonto();

void imprimePonto(tPonto p);

tPonto setX(tPonto p, int x);

tPonto setY(tPonto p, int y);

int getX(tPonto p);

int getY(tPonto p);

tPonto movPonto(tPonto p, int dX, int dY);

float distanciaPontos(tPonto p1, tPonto p2);

int quadrantePonto(tPonto p);

tPonto getSimetrico(tPonto p);

#endif // !ponto
