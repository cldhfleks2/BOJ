#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
char s[101];

int main(void) {
	scanf("%s", &s);
	int cur = 0;
	while (s[cur] != '\0') {
		if (cur > 0 && cur % 10 == 0) printf("\n");
		printf("%c", s[cur]);
		cur++;
	}

	return 0;
}