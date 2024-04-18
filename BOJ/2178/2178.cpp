#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::queue; using std::pair;
int n, m, ** map, ** res;
bool** visited;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;

		q.pop();
		
		//4방향으로 이동
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (0 <= xx && xx <= n - 1 && 0 <= yy && yy <= m - 1) {
				if (map[xx][yy] == 1 && !visited[xx][yy]) {
					visited[xx][yy] = true; //방문했음
					res[xx][yy] = res[x][y] + 1; //x, y에서 이동거리 +1
					q.push({ xx, yy }); //이동한위치 에서 다시 탐색하도록
				}
			}
		}
	}
}

int main(void) {
	scanf("%d%d", &n, &m);
	map = new int* [n];
	res = new int* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		res[i] = new int[m];
		visited[i] = new bool[m];
		char c;
		scanf("%c", &c); //줄바꿈문자지움
		for (int j = 0; j < m; j++) {
			scanf("%c", &c);
			if (c == '1')
				map[i][j] = 1;
			else
				map[i][j] = 0;
			res[i][j] = 0;
			visited[i][j] = false;
		}
	}

	BFS(0, 0); //0, 0부터 탐색시작

	printf("%d\n", res[n - 1][m - 1] + 1);

	return 0;
}