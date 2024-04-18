#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int func(int n) {
	int res = 1;
	for (int i = 1; i <= n; i++)
		res *= 2;
	return res;
}

int main(void) {
	int n;
	scanf("%d", &n);

	printf("%d", func(n));

	return 0;
}