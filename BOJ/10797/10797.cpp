#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	int n, res=0;
	scanf("%d", &n);
	for (int i = 0, _; i < 5; i++) {
		scanf("%d", &_);
		if (_ == n) res++;
	}

	printf("%d", res);

	return 0;
}