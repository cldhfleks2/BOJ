#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	int n[3];
	for (int i = 0; i < 3; i++)
		scanf("%d", &n[i]);
	std::sort(n, n + 3);

	printf("%d", n[1]);
	return 0;
}