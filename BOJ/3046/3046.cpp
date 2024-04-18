#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int r1, int s) {
	scanf("%d%d", &r1, &s);
	if (r1 < 0) {
		printf("%d", 2*s + r1);
	}
	else {
		printf("%d", 2*s - r1);
	}
}