#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d\n", &n);
	int max = -1000001, min = 1000001;
	while (n--) {
		int a;
		scanf("%d", &a);
		if (max <= a)
			max = a;
		if (min >= a)
			min = a;
	}

	printf("%d %d", min, max);

	return 0;
}