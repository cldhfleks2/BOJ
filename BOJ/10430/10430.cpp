#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int a, int b, int c) {
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n%d\n%d\n%d", (a + b) % c,
		((a % c) + (b % c)) % c, (a * b) % c,
		((a % c) * (b % c)) % c);



	return 0;
}