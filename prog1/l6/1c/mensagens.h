#include "pacote.h"
#define MAX_PCTS 100

#ifndef mensagens
#define mensagens

typedef struct {
  int id, lastPct;
  tPacote pcts[MAX_PCTS];
} tMensagens;

tMensagens novaMensagem(tPacote p);

tMensagens adicionarPct(tMensagens m, tPacote p);

tMensagens ordenarPcts(tMensagens m);

void imprimirMensagem(tMensagens m);

#endif // !mensagens
