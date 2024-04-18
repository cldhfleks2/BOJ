#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using std::vector; using std::queue; using std::pair;

int N, L, R, A[50][50], res = 0;
bool visited[50][50], check[50][50];
int dxy[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };


void func() {
	while (1) {
		//초기화
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				check[i][j] = false;

		int temp = 0;
		//국경선을 열며 한덩어리씩 묶어서 색칠
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j]) continue; //이미 다른 구역에 편성되있으면 제외

				for (int k = 0; k < N; k++)
					for (int l = 0; l < N; l++)
						visited[k][l] = false;

				queue<pair<int, int>> q, log;
				q.push({ i, j });
				log.push({ i, j });
				visited[i][j] = true;
				int sum = 0; 
				int cnt = 0;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					check[x][y] = true;
					sum += A[x][y];
					cnt++;
					q.pop();

					for (int d = 0; d < 4; d++) {
						int xx = x + dxy[d][0];
						int yy = y + dxy[d][1];

						//다음위치가 비정상적이거나 다른 구역에 편성되있으면 제외
						if (xx < 0 || yy < 0 || xx == N || yy == N || visited[xx][yy] || check[xx][yy])
							continue;
						int gap = A[x][y] - A[xx][yy];
						gap < 0 ? gap *= -1 : gap = gap;
						if (gap < L || R < gap) continue; //현재위치와 맞닿은위치의 인구수차이가 조건
						visited[xx][yy] = true;
						q.push({ xx, yy });
						log.push({ xx, yy });
					}
				}
				if (cnt == 1) continue;
				
				//영역마다 인구수를 분배
				while (!log.empty()) {
					int x = log.front().first;
					int y = log.front().second;
					log.pop();
					A[x][y] = sum / cnt;
					temp++;
				}

			}
		}
		if (temp == 0) break;

		res++;
	}
	
	printf("%d", res);

}



int main(void) {
	scanf("%d%d%d", &N, &L, &R);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &A[i][j]);

	func();

	return 0;
}