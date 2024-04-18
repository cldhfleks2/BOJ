#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main(void) {
	int t, temp, res = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%1d", &temp);
		res += temp;
	}
	printf("%d", res);
}