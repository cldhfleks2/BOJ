#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int a, int b, int c) {
	while (true) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
			break;
		if (a * a + b * b == c * c ||
			a*a + c*c == b*b ||
			b*b + c*c == a*a)
			printf("right\n");
		else
			printf("wrong\n");
	}

}