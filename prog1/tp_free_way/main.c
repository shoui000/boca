#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_PATH 1000
#define MAX_ROADS 12
#define MAX_COLUMNS 100
#define MAX_CARS_PER_ROAD 10
#define SPRITE_MAX_WIDTH 3
#define SPRITE_MAX_HEIGHT 2
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
  char map[(MAX_ROADS * 3) + 1][MAX_COLUMNS + 4];

  road roads[MAX_ROADS];
} GAME;

GAME readConfig(GAME g, char *path);
GAME readSprites(GAME g, char *path);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERRO: Informe o diretorio com os arquivos de configuracao.\n");
    exit(1);
  }

  GAME g;
  g = readConfig(g, argv[1]);
  g = readSprites(g, argv[1]);

  exit(0);
}

GAME readConfig(GAME g, char *path) {
  char configPath[MAX_SIZE_PATH+20];
  strcpy(configPath, path);
  strcat(configPath, "/config_inicial.txt");

  FILE *f;
  f = fopen(configPath, "r");

  if (f == NULL) {
    printf("ERRO: Nao foi possivel abrir o arquivo \"%s\"\n", configPath);
    exit(1);
  }

  char buffer[512];
  fgets(buffer, 512, f);
  sscanf(buffer, "%d", &g.animate);

  fgets(buffer, 512, f);
  sscanf(buffer, "%d %d", &g.mapWidth, &g.roadsCount);

  for (int i = 0; i < g.roadsCount; i++) {
    fgets(buffer, 512, f);

    if (strlen(buffer) < 2 || i == g.roadsCount-1) {
      g.roads[i].carsCount = 0; g.roads[i].direction = 0; g.roads[i].speed = 0;
      continue;
    }

    char *token = strtok(buffer, " ");

    char b;
    sscanf(token, "%c", &b);
    g.roads[i].direction = (b == 'D') ? 1 : -1;

    token = strtok(NULL, " ");
    sscanf(token, "%d", &g.roads[i].speed);

    token = strtok(NULL, " ");
    sscanf(token, "%d", &g.roads[i].carsCount);

    for (int j = 0; j < g.roads[i].carsCount; j++) {
      token = strtok(NULL, " ");
      sscanf(token, "%d", &g.roads[i].cars[j].b);
    }

  }

  fgets(buffer, 512, f);
  sscanf(buffer, "G %d %d", &g.chicken.b, &g.chicken.lifes);
  g.chicken.road = g.roadsCount-1;

  fclose(f);

  return g;
}

GAME readSprites(GAME g, char *path) {
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
        g.sprites[x][i][j] = fgetc(f);
      }

      fgetc(f); // \r
      fgetc(f); // \n
    }
  }

  fclose(f);
  return g;
}
