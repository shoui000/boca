#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 51

int main() {
	char s[MAX_STRING_SIZE];

	while (scanf("%50[^\n]\n", s) != EOF) {
		for (int i = 0; i < (int)strlen(s); i++) {
			if (s[i] == ' ') { continue; }
			putchar(s[i]);
		}
		putchar('\n');
	}
	return 0;
}

