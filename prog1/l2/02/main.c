#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (n+=1; n < m; n++){
		if (n % 3 == 0 || n % 4 == 0 || n % 7 == 0) {
			printf("%d ", n);
		}
	}
}
