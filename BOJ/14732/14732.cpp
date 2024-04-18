#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	//int temp, x1 = 500, y1 = 500, x2 = 0, y2 = 0;
	int temp, x1, y1, x2, y2, cnt=0;
	bool saloon[501][501] = { false };
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d %d %d", &x1 ,&y1, &x2, &y2);
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				if (!saloon[i][j]) {
					saloon[i][j] = true;
					cnt++;
				}
			}
		}
	}
	printf("%d", cnt);
}