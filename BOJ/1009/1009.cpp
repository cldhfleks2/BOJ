#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int t, a, b;
int list[10][4] = { {10, 10, 10, 10}, {1, 1, 1, 1}, {2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6, 4, 6}, 
	{5, 5, 5, 5}, {6, 6, 6, 6}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1, 9, 1} };

int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		int num = a % 10;

		int res = list[num][(b-1) % 4];
		printf("%d\n", res);
	}

	return 0;
}