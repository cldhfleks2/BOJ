#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int h, int m) {
	scanf("%d %d", &h, &m);

	int res_h = h;
	if (m >= 45) {
		printf("%d %d", res_h, m - 45);
		return 0;
	}
	int res_m = 45 - m;

	if (res_m > 0) {
		res_h--;
		if (res_h < 0)
			res_h = 23;
		res_m = 60 - res_m;
	}

	printf("%d %d", res_h, res_m);

	return 0;
}