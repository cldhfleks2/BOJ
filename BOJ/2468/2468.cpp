#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

struct INFO {
	int x, y;
};

int dxy[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int n; 
int map[100][100];
int max_h; //최대 높이
int max = 1;
void init() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			max_h = std::max(max_h, map[i][j]);
		}
}

//
void floodArea() {
	int cnt = 0;
	int area[100][100] = { 0, };

	//N x N영역이 몇개의 부분영역으로 나뉘는지 탐색
	//부분영역갯수 : cnt
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] <= 0) continue; //물에 잠긴곳은 탐색X
			if (area[i][j] != 0) continue; //탐색한 곳 제외

			queue<INFO> q;
			bool visited[100][100] = { false, };
			
			q.push({ i,j });
			visited[i][j] = true;
			area[i][j] = ++cnt; //1, 2, 3... 이번탐색에 쓰일 숫자
			//탐색 시작
			while (!q.empty()) {
				int x = q.front().x;
				int y = q.front().y;
				q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int xx = x + dxy[dir][0];
					int yy = y + dxy[dir][1];
					if (xx < 0 || yy < 0 || xx == n || yy == n) continue;
					if (map[xx][yy] <= 0) continue; //물에잠긴곳은 탐색안함
					if (visited[xx][yy]) continue; //이미 탐색한곳 제외
					visited[xx][yy] = true;

					area[xx][yy] = cnt; //탐색된곳은 전부같은 숫자로 칠함
					q.push({ xx, yy }); //탐색 이어나가기
				}
			}

		}
	}

	//DEBUG
	//printf("=======================\n");
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++)
	//		printf("%d  ", area[i][j]);
	//	printf("\n");
	//}
	//printf("=======================\n");
	//printf(">> %d\n", cnt);
	max = std::max(max, cnt); 
}

void rainy() {
	while (max_h--) {
		//비가 한층 내린다. (높이 -1)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j]--;

		//몇개의 부분영역이 생기는지 파악
		floodArea();
	}
}

int main(void) {
	init();

	rainy();

	printf("%d", max);

	return 0;
}
