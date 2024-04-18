#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d\n", &n);

	
	while (n--) {
		char s[81];
		scanf("%[^\n]s", &s);
		scanf("%c", &s[80]);
		int score = 1;
		int res=0;

		for (int i = 0;; i++) {
			char c = s[i];
			if (c == '\0')
				break;
			if (c == 'O') {
				res += score;
				score++;
			}
			else {
				res += 0;
				score = 1;
			}
		}
		printf("%d\n", res);
	}



	return 0;
}