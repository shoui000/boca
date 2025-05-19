#include <stdio.h>

int main(){
	while (1) {
		char c;
		scanf("%c", &c);

		if (c >= 97 && c <= 122) {
			c -= 32;
		}

		printf("%c", c);
		if (c == '.' || c == '?' || c == '!') {
			break;
		}
	}
	return 0;
}

