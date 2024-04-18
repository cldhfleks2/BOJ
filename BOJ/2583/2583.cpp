#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using std::queue;
using std::vector;

struct INFO {
	int x, y;
};

int dxy[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int m, n, k;
bool map[100][100] = {true, }; //초깃값 true

vector<int> area;

void rectangleTo(int x, int y, int xx, int yy) {
	for (int i = x; i < xx; i++)
		for (int j = y; j < yy; j++) 
			map[i][j] = false;

	//DEBUG
	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		printf("%d  ", map[i][j]);
	//	}
	//	printf("\n");
	//}
}

void calculateArea() {
	for(int i = 0 ; i < m ; i++)
		for (int j = 0; j < n; j++) {
			if (!map[i][j]) continue;
			
			queue<INFO> q;
			bool visited[100][100] = { false, };
			q.push({ i, j });
			visited[i][j] = true;
			int cnt = 0;

			while (!q.empty()) {
				int x = q.front().x;
				int y = q.front().y;
				map[x][y] = false;
				q.pop();
				cnt++; //현재 영역크기 계산

				for (int dir = 0; dir < 4; dir++) {
					int xx = x + dxy[dir][0];
					int yy = y + dxy[dir][1];
					if (xx < 0 || yy < 0 || xx == m || yy == n) continue;
					if (visited[xx][yy]) continue;
					if (!map[xx][yy]) continue;
					visited[xx][yy] = true;

					q.push({xx, yy});
				}
			}

			area.push_back(cnt);
		}

	
}

int main(void) {
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) map[i][j] = true;

	while (k--) {
		int x, y, xx, yy;
		scanf("%d%d%d%d", &y, &x, &yy, &xx);
		rectangleTo(x, y, xx, yy);
	}
	
	calculateArea();

	sort(area.begin(), area.end());
	printf("%d\n", area.size());
	for (int i = 0; i < area.size(); i++)
		printf("%d ", area[i]);

	return 0;
}