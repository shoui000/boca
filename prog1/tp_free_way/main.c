#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_PATH 1000
#define MAX_ROADS 12
#define MAX_COLUMNS 102
#define MAX_CARS_PER_ROAD 10
#define SPRITE_MAX_WIDTH 3
#define SPRITE_MAX_HEIGHT 2
#define MAX_SPRITES 5
#define MAX_MAP_HEIGHT 37

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
  int animate, mapWidth, mapHeight, roadsCount;

  chicken chicken;
  int spriteIndex;

  char sprites[MAX_SPRITES][SPRITE_MAX_HEIGHT][SPRITE_MAX_WIDTH];
  char map[MAX_MAP_HEIGHT][MAX_COLUMNS];

  road roads[MAX_ROADS];
} GAME;

GAME readConfig(GAME g, char *path);
GAME readSprites(GAME g, char *path);
GAME startGame(char *path);
int normalizeCoord(int base, int max, int min, int diff);
void printMap(GAME g);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERRO: Informe o diretorio com os arquivos de configuracao.\n");
    exit(1);
  }

  GAME g = startGame(argv[1]);

  printMap(g);

  exit(0);
}

void printMap(GAME g) {
  for (int i = 0; i < g.mapHeight; i++) {
    for (int j = 0; j < g.mapWidth; j++) {
      putchar(g.map[i][j]);
    }

    putchar('\n');
  }
}

GAME startGame(char *path) {
  GAME g;

  g = readConfig(g, path);
  g = readSprites(g, path);

  // Arrumando as coordenadas de cada elemento
  
  // // Galinha
  g.chicken.a = normalizeCoord(g.chicken.b, g.mapWidth-1, 1, -1);
  g.chicken.c = normalizeCoord(g.chicken.b, g.mapWidth-1, 1, +1);

  // // Carros
  for (int i = 0; i < g.roadsCount; i++) {
    for (int j = 0; j < g.roads[i].carsCount; j++) {
      g.roads[i].cars[j].a = normalizeCoord(g.roads[i].cars[j].b, g.mapWidth-1, 1, -1);
      g.roads[i].cars[j].c = normalizeCoord(g.roads[i].cars[j].b, g.mapWidth-1, 1, +1);
    }
  }

  // Arruma o mapa
  
  for (int i = 0; i < g.mapHeight; i++) {
    for (int j = 0; j < g.mapWidth; j++) {
      g.map[i][j] = ' ';
    }

    g.map[i][0] = '|';
    g.map[i][g.mapWidth-1] = '|';
  }

  for (int i = 1; i < g.mapWidth-1; i++) {
    g.map[0][i] = '-';
    g.map[g.mapHeight-1][i] = '-';
  }

  for (int i = 1; i <= g.roadsCount; i++) {
    int y = (i * 3);
    if (y == g.mapHeight-1) { continue; }

    for (int j = 1; j < g.mapWidth-1; j++) {
        g.map[y][j] = (j % 3) ? '-' : ' ';
    }
  }

  return g;
}

int normalizeCoord(int base, int max, int min, int diff) {
  int res = base + diff;
  while (res < min) res += max;
  if (res > max) res = ( (res % max) == 0) ? max : res % max;

  return res;
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
  int temp;
  sscanf(buffer, "%d %d", &temp, &g.roadsCount);
  g.mapWidth = temp+2;
  g.mapHeight = (g.roadsCount * 3) + 1;

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
