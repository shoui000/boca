#include <stdio.h>

int EhPrimo(int num) {
    int a = 1;
    for (int i = 2; i < num; i++){
        if (num % i == 0){
            a = 0;
            break;
        }
    }

    return a;
}

void ImprimeMultiplos(int num, int max) {
    int realMax = max / num;
    if (realMax == 1) {
        printf("*");
    } else {
        for (int i = 2; i <= realMax; i++)
        {
            printf("%d ", num * i);
        }
    }

    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = n+1; i < m; i++) {
        if (EhPrimo(i)){
            printf("%d\n", i);
            ImprimeMultiplos(i, m-1);
        }
    }

    return 0;
}