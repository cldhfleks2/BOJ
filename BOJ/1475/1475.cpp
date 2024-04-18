#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
char c[7];
int num[10] = {0,};
int main(void) {
	scanf("%s", &c);
	for (int i = 0; i < 7; i++) {
		if (c[i] == '\0') break;
		num[c[i] - '0']++;
	}
	int res = 0;
	while (1) {
		bool six = false;
		bool set = false;
		for (int i = 0; i < 10; i++) {
			if ((0 <= i && i <= 5) || (7 <= i && i <= 8)) {
				if (num[i] > 0) {
					num[i]--;
					set = true;
				}
			}		
		}
		if (!set)
			break;
		res++;
	}

	int res2 = (num[6] + num[9]) / 2;
	res2 += (num[6] + num[9]) % 2 == 0 ? 0 : 1;

	printf("%d", res >= res2 ? res : res2);
	
	return 0;
}