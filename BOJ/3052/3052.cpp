#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	int r[42];
	memset(r, 0, 42 * sizeof(int));

	while (scanf("%d", &n) != EOF) {
		r[n % 42]++;
	}
	int res = 0;
	for (int i = 0; i < 42; i++)
		if (r[i] != 0)
			res++;

	printf("%d", res);
}