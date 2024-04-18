#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::queue; using std::pair;
typedef pair<int, int> pii;
/*
n,m : 맵크기
cheeze : 치즈위치 배열 true:치즈
visited : BFS에서 방문했는지 체크용
remainsCheeze = 방금전단계에서 남은 치즈
매단계마다 BFS 0,0부터 탐색, 탐색하며 치즈를 깎고, 탐색종료시
clear()실행
*/
int n, m, remainsCheeze=0, hour=1;
bool **cheeze, **visited; 
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void clear();
void init();
int countCheeze();
void DEBUG();
void func();

void func() {
	queue<pii> loc;
	while (remainsCheeze > 0) { //치즈가 한개라도 남은경우
		loc.push({ 0,0 }); //0,0부터탐색
		visited[0][0] = true;

		while (!loc.empty()) {
			int x = loc.front().first; //현재위치 (x,y)
			int y = loc.front().second;
			loc.pop();

			//4방향으로탐색
			for (int d = 0; d < 4; d++) {
				int xx = x + dx[d]; //다음위치 (xx,yy)
				int yy = y + dy[d]; 

				//올바르지않은 범위
				if (xx < 0 || yy < 0 || xx == n || yy == m)
					continue;

				if (!visited[xx][yy]) {
					visited[xx][yy] = true;

					if (cheeze[xx][yy]) //치즈가있다면 없앰
						cheeze[xx][yy] = false; 
					else //치즈가 없다면 다음위치에서 탐색을 이어서 진행
						loc.push({ xx, yy }); 
				}
			}

		}

		//탐색후 모두 초기화
		clear();
		//DEBUG(); //디버그용

		if (countCheeze() == 0) //탐색후 치즈가 없는경우
			break;
		remainsCheeze = countCheeze();
		hour++;
	}
	printf("%d\n%d", hour, remainsCheeze);
}

void DEBUG() {
	printf("==================================%d 시간뒤\n", hour);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%2d", cheeze[i][j]);
		printf("\n");
	}
	printf("=====================================\n");
}

int countCheeze() { 
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (cheeze[i][j]) res++;
	return res;
}

void init() {
	scanf("%d%d", &n, &m);
	cheeze = new bool* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		cheeze[i] = new bool[m];
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++) {
			scanf("%d", &cheeze[i][j]);
			visited[i][j] = false;
		}
	}
	remainsCheeze = countCheeze(); //남은치즈 초깃값
}

void clear() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = false;
}

int main(void) {
	init();
	func();

	return 0;
}