#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d", &n);
	while (n--) {
		int cnt;
		char s[22];

		scanf("%d %[^\n]s", &cnt, &s);
		scanf("%c", &s[21]);
		for (int i = 0; i < 21; i++) {
			char c = s[i];
			if (c == '\0')
				break;
			int j = cnt;
			while (j--) {
				printf("%c", c);
			}
		}
		printf("\n");
	}

	return 0;
}