#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>

using std::queue;
using std::vector;
struct INFO {
	int x, y;
};

int dxy[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}
				, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

void logic() {
	while (1) { // "0 0" �� �Է¹��������� �ݺ�
		vector<INFO> land;
		bool map[50][50];
		int w, h;
		scanf("%d%d", &h, &w);
		if (w == 0 && h == 0)
			return;

		for (int i = 0; i < w; i++)
			for (int j = 0, state=0; j < h; j++) {
				scanf("%d", &state);
				if (state == 1) { //�ʿ� üũ
					map[i][j] = true;
					land.push_back({ i, j }); //����ġ���
				}
				else
					map[i][j] = false;
			}

		int res = 0;
		for (int i = 0; i < land.size(); i++) {
			if (!map[land[i].x][land[i].y]) continue;
			res++;
			bool visited[50][50] = { false, };
			queue<INFO> q;
			q.push({ land[i].x, land[i].y });
			visited[land[i].x][land[i].y] = true;

			while (!q.empty()) {
				int x = q.front().x;
				int y = q.front().y;
				q.pop();

				for (int dir = 0; dir < 8; dir++) {
					int xx = x + dxy[dir][0];
					int yy = y + dxy[dir][1];

					if (xx < 0 || yy < 0 || xx == w || yy == h) continue;
					if (!map[xx][yy]) continue; //�ٴٴ� �̵��Ұ�
					if (visited[xx][yy]) continue;
					visited[xx][yy] = true;
					map[xx][yy] = false; //üũ����
					q.push({ xx, yy });
				}
			}
		}

		printf("%d\n", res);
	}
}

int main(void) {
	logic();


	return 0;
}