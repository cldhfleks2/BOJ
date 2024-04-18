#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n, m;
bool **mirror;
int dx[4] = {0, -1, 0, 1}; //우 상 좌 하
int dy[4] = {1, 0, -1, 0}; //

int beam(int x, int y, int dir);
int findNumber(int x, int y);
void init();
void func();

void func() {
	for (int k = 0; k < n; k++) { // →
		printf("%d ", beam(k, 0, 0));
	}
	for (int k = 0; k < m; k++) { // ↑
		printf("%d ", beam(n - 1, k, 1));
	}
	for (int k = 0; k < n; k++) { // ←
		printf("%d ", beam(n - 1 - k, m - 1, 2));
	}
	for (int k = 0; k < m; k++) { // ↓
		printf("%d ", beam(0, m - 1 - k, 3));
	}
}

void init() {
	scanf("%d%d", &n, &m);
	mirror = new bool* [n];
	for (int i = 0; i < n; i++) {
		mirror[i] = new bool[m];
		for (int j = 0, _; j < m; j++) {
			scanf("%d", &_);
			if (_ == 0)
				mirror[i][j] = 0;
			else
				mirror[i][j] = 1;
		}
	}

}

int findNumber(int x, int y) {
	if (y < 0) return x + 1;
	if (x == n) return n + y + 1;
	if (y == m) return n + m + (n - x);
	if (x < 0) return 2 * n + m + (m - y);
}

//x,y에서 dir방향으로 빛이 출발 (출발위치도 거울영향받음)
int beam(int x, int y, int dir) {
	if (x < 0 || y < 0 || x == n || y == m)
		return findNumber(x, y);

	if (mirror[x][y]) {
		if (dir == 0) return beam(x + dx[dir + 1], y + dy[dir + 1], dir + 1);
		if (dir == 1) return beam(x + dx[dir - 1], y + dy[dir - 1], dir - 1);
		if (dir == 2) return beam(x + dx[dir + 1], y + dy[dir + 1], dir + 1);
		if (dir == 3) return beam(x + dx[dir - 1], y + dy[dir - 1], dir - 1);
	}
	else {
		return beam(x + dx[dir], y + dy[dir], dir);
	}
}


int main(void) {
	init();
	func();

	return 0;
}

