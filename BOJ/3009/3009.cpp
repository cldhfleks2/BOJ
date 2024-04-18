#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int x[3], y[3], res_x, res_y;


int main(void) {
	scanf("%d%d%d%d%d%d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
	if (x[0] == x[1]) res_x = x[2];
	if (x[1] == x[2]) res_x = x[0];
	if (x[0] == x[2]) res_x = x[1];
	if (y[0] == y[1]) res_y = y[2];
	if (y[1] == y[2]) res_y = y[0];
	if (y[0] == y[2]) res_y = y[1];

	printf("%d %d", res_x, res_y);

	return 0;
}