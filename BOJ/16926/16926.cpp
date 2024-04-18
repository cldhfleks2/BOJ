#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n, m, r, dir, **A, **B, min;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
void rotate(int start_x, int start_y, int R, int C);
void func();
void printAll(int**& C);
void init();

void init() {
	scanf("%d%d%d", &n, &m, &r);
	if (n > m)
		min = m;
	else
		min = n;
	A = new int* [n];
	B = new int* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[m];
		B[i] = new int[m];
		for (int j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
	}
}

void printAll(int **&C) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}
}

void func() {
	while (r--) {
		for (int k = 0; k < min / 2; k++) {
			dir = 0;
			rotate(k, k, n - 2 * k, m - 2 * k);
		}
	}

	printAll(B);
}

void rotate(int start_x, int start_y, int R, int C) {
	int x = start_x;
	int y = start_y;
	int end_x = start_x + R;
	int end_y = start_y + C;
	int cnt = 2 * (R - 1) + 2 * (C - 1);
	while (cnt--) {
		int xx = x + dx[dir];
		int yy = y + dy[dir];
		if (xx < start_x || yy < start_y || xx == end_x || yy == end_y) {
			dir = (dir + 1) % 4;
			xx = x + dx[dir];
			yy = y + dy[dir];
		}
		int num = A[x][y];
		B[xx][yy] = num;
		x = xx;
		y = yy;
	}
	x = start_x;
	y = start_y;
	end_x = start_x + R;
	end_y = start_y + C;
	cnt = 2 * (R - 1) + 2 * (C - 1);
	while (cnt--) {
		int xx = x + dx[dir];
		int yy = y + dy[dir];
		if (xx < start_x || yy < start_y || xx == end_x || yy == end_y) {
			dir = (dir + 1) % 4;
			xx = x + dx[dir];
			yy = y + dy[dir];
		}
		A[xx][yy] = B[xx][yy];
		x = xx;
		y = yy;
	}
}

int main(void) {
	init();
	func();

	return 0;
}