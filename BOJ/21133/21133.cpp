#define _CRT_SECURE_NO_WARNINGS //scanf¿À·ù ¾ø¾Ú
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int c = n / 2; //¸ò
	for (int i = 0; i < c; i++) {
		printf("%d\n", (i + 1)*2);
	}
	for (int i = 0; i < c; i++) {
		printf("%d\n", (i + 1) * 2 - 1);
	}
	if (n % 2 != 0) printf("%d\n", n);
}