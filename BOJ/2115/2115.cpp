#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int m, n;
bool** gallery;

void init() {
	scanf("%d%d", &m, &n);
	gallery = new bool* [m];
	for (int i = 0; i < m; i++) {
		gallery[i] = new bool[n];
		char _;
		scanf("%c", &_);
		for (int j = 0; j < n; j++) {
			scanf("%c", &_);
			if (_ == 'X')
				gallery[i][j] = false;
			else if (_ == '.')
				gallery[i][j] = true;
		}
	}
}

void func() {
	int res = 0;

	for (int k = 1; k < m - 1; k++) { // ¡æ ¹æÇâ À­º® Å½»ö
		int cnt = 0;
		for (int l = 1; l < n - 1; l++) {
			if (gallery[k][l] && !gallery[k - 1][l])
				cnt++;
			else{
				res += cnt / 2;
				cnt = 0;
			}
		}
		res += cnt / 2;
	}
	for (int k = 1; k < m - 1; k++) { // ¡æ ¹æÇâ ¾Æ·§º® Å½»ö
		int cnt = 0;
		for (int l = 1; l < n - 1; l++) {
			if (gallery[k][l] && !gallery[k + 1][l])
				cnt++;
			else{
				res += cnt / 2;
				cnt = 0;
			}
		}
		res += cnt / 2;
	}
	for (int k = 1; k < n - 1; k++) { // ¡é ¹æÇâ ¿Þº®Å½»ö
		int cnt = 0;
		for (int l = 1; l < m - 1; l++) {
			if (gallery[l][k] && !gallery[l][k - 1])
				cnt++;
			else{
				res += cnt / 2;
				cnt = 0;
			}
		}
		res += cnt / 2;
	}
	for (int k = 1; k < n - 1; k++) { // ¡é ¹æÇâ ¿À¸¥º®Å½»ö
		int cnt = 0;
		for (int l = 1; l < m - 1; l++) {
			if (gallery[l][k] && !gallery[l][k + 1])
				cnt++;
			else{
				res += cnt / 2;
				cnt = 0;
			}
		}
		res += cnt / 2;
	}

	printf("%d", res);
}


int main(void) {
	init();
	func();

	return 0;
}