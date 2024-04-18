#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

struct INFO {
	int x, y, c=0;
};

int dxy[8][2] = { {2, 1}, {-2, 1}, {2, -1}, {-2, -1},
					{1, 2}, {-1, 2}, {1, -2}, {-1, -2} };

int t;

int main(void) {
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		INFO start, end;
		scanf("%d%d%d%d", &start.x, &start.y, &end.x, &end.y);

		queue<INFO> q;
		bool visited[300][300] = { false, };
		q.push(start);
		visited[start.x][start.y];
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int c = q.front().c;
			q.pop();

			if (x == end.x && y == end.y) {
				printf("%d\n", c);
				break;
			}

			for (int dir = 0; dir < 8; dir++) {
				int xx = x + dxy[dir][0];
				int yy = y + dxy[dir][1];
				if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
				if (visited[xx][yy]) continue;
				visited[xx][yy] = true;

				q.push({ xx, yy, c + 1 });
			}
		}
	}

	return 0;
}