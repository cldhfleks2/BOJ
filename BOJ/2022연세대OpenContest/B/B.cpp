#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int t, int n, int junk) {
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		scanf("%d%d", &junk, &junk);
		for (int j = 0; j < n; j++)
			scanf("%d%d", &junk, &junk);
		printf("Material Management %d\nClassification ---- End!\n", i);
	}

	return 0;
}