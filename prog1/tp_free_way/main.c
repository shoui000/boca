#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_PATH 1000
#define MAX_ROADS 12
#define MAX_COLUMNS 100
#define MAX_CARS_PER_ROAD 10
#define SPRITE_MAX_WIDTH 3
#define SPRITE_MAX_HEIGHT 2
#define UNUSABLE_ROADS 2
#define MAX_SPRITES 5

typedef struct {
  int a, b, c;
} car;

typedef struct {
  int speed, carsCount, direction;
  car cars[MAX_CARS_PER_ROAD];
} road;

typedef struct {
  int a, b, c, road, lifes;
} chicken;

typedef struct {
  int animate, mapWidth, roadsCount;

  chicken chicken;
  int spriteIndex;

  char sprites[MAX_SPRITES][SPRITE_MAX_HEIGHT][SPRITE_MAX_WIDTH];

  road roads[MAX_ROADS];
} GAME;

void readConfig(GAME *g, char *path);
void readSprites(GAME *g, char *path);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERRO: Informe o diretorio com os arquivos de configuracao.\n");
    exit(1);
  }

  GAME g;

  // Passagem por referencia eu posso usar ne? Vinicius ensinou (Ensinou memo, n to passando fake)
  readConfig(&g, argv[1]);
  readSprites(&g, argv[1]);

  exit(0);
}

void readConfig(GAME *g, char *path) {
  char configPath[MAX_SIZE_PATH+20];
  strcpy(configPath, path);
  strcat(configPath, "/config_inicial.txt");

  FILE *f;
  f = fopen(configPath, "r");

  if (f == NULL) {
    printf("ERRO: Nao foi possivel abrir o arquivo \"%s\"\n", configPath);
    exit(1);
  }

  // lendo o arquivo config_inicial.txt que possui a seguinte formatacao:
  // animacao
  // largura_mapa qtd_pistas
  // direcao velocidade num_carro X1 X2 … Xn
  // direcao velocidade num_carro X1 X2 … Xn
  // G X_galinha vidas

  fscanf(f, "%d\n", &g->animate);
  int x;
  fscanf(f, "%d %d\n", &g->mapWidth, &x);
  g->roadsCount = x - UNUSABLE_ROADS;

  char d;
  for (int i = 0; i < g->roadsCount; i++) {
    d = fgetc(f);

    if (d == '\n') {
      g->roads[i].carsCount = 0;
      g->roads[i].speed = 0;
      g->roads[i].direction = 0;
      continue;
    }

    g->roads[i].direction = (d == 'D') ? 1 : -1;
    fscanf(f, " %d %d", &g->roads[i].speed, &g->roads[i].carsCount);

    for (int j = 0; j < g->roads[i].carsCount; j++) {
      fscanf(f, "%d", &g->roads[i].cars[j].b);
      fgetc(f);
    }
  }

  fscanf(f, "G %d %d", &g->chicken.b, &g->chicken.lifes);
  
  fclose(f);
}

void readSprites(GAME *g, char *path) {
  char spritesPath[MAX_SIZE_PATH+20];
  strcpy(spritesPath, path);
  strcat(spritesPath, "/personagens.txt");
  FILE *f;
  f = fopen(spritesPath, "r");

  if (f == NULL) {
    printf("ERRO: Nao foi possivel abrir o arquivo \"%s\"\n", spritesPath);
    exit(1);
  }

  for (int x = 0; x < MAX_SPRITES; x++) {
    for (int i = 0; i < SPRITE_MAX_HEIGHT; i++) {
      for (int j = 0; j < SPRITE_MAX_WIDTH; j++) {
        g->sprites[x][i][j] = fgetc(f);
      }

      fgetc(f); // \r
      fgetc(f); // \n
    }
  }

  fclose(f);
}
