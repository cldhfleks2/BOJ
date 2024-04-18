#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n, m, ** wood, res = 0;
bool** visited;
void vertical(int x, int y);
void horizontal(int x, int y);

void find() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				if (wood[i][j] == 0)
					vertical(i, j);
				else
					horizontal(i, j);
				res++;
			}
		}
	}
}

void vertical(int x, int y) { //가로
	visited[x][y] = true;
	if (0 <= y - 1 && wood[x][y - 1] == 0 && !visited[x][y - 1]) // ←
		vertical(x, y - 1);
	if (y + 1 <= m - 1 && wood[x][y + 1] == 0 && !visited[x][y + 1]) // →
		vertical(x, y + 1);
}


void horizontal(int x, int y) { //세로
	visited[x][y] = true;
	if (0 <= x - 1 && wood[x - 1][y] == 1 && !visited[x - 1][y]) // ↑
		horizontal(x - 1, y);
	if (x + 1 <= n - 1 && wood[x + 1][y] == 1 && !visited[x + 1][y]) // ↓
		horizontal(x + 1, y);
}

int main(char c) {
	scanf("%d%d", &n, &m);
	wood = new int* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		wood[i] = new int[m];
		visited[i] = new bool[m];
		scanf("%c", &c);
		for (int j = 0; j < m; j++) {
			scanf("%c", &c);
			if (c == '-')
				wood[i][j] = 0;
			else
				wood[i][j] = 1;
			visited[i][j] = false;
		}
	}

	find();

	printf("%d", res);

	return 0;
}