#include <stdio.h>

int mdc(int a, int b){
	if (a == 0) {
		return b;
	} else if (b == 0) {
		return a;
	}

	return mdc(b, a % b);
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);

	int x = mdc(a, b);
	int y = a * (b / x);

	printf("%d %d", x, y);

	return 0;
}
