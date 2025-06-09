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

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = n+1; i < m; i++){
        if (EhPrimo(i)){
            printf("%d ", i);
        }
    }

    return 0;
}