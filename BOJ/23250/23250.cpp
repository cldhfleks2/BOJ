#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n;
unsigned long long int k;
bool clear = false;

void hanoi(int n, int from, int to, int aux) {
	if (clear)
		return;
	if (n == 1) {
		k--;
		if (k == 0) {
		printf("%d %d", from, to);
			clear = true;
		}
		return;
	}
	else {
		hanoi(n - 1, from, aux, to);
		k--;
		if (k == 0) {
			printf("%d %d", from, to);
			clear = true;
		}
		hanoi(n - 1, aux, to, from);
	}
}


int main(void) {
	scanf("%d %d", &n, &k);
	hanoi(n, 1, 3, 2);
	return 0;
}
