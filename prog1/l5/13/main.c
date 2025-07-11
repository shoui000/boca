#include <stdio.h>

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
  char str1[1000];
  char str2[1000];

  while ( scanf("%s", str1) == 1 && scanf("%s", str2) == 1){
    if ( ComparaString(str1, str2) ) {
      printf("IGUAL\n");
    } else {
      printf("DIFERENTE\n");
    }
  }
  return 0;
}
