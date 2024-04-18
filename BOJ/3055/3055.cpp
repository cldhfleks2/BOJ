#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using std::queue; using std::vector; using std::pair;

int R, C, map[50][50];
int dxy[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
bool water_visit[50][50], hed_visit[50][50];
int time = 1;
/*
map에 저장된 값:
1: 돌
2: 물
3: 고슴도치
4: 목적지
*/
/*
맵에있는 모든 고슴도치가 사방으로 한칸 이동
1 : 고슴도치가 굴을 찾음
0 : 고슴도치가 굴을 찾지 못함
-1 : 고슴도치가 싹다 뒤짐
*/
int hed_move() {
	int cnt = 0; //고슴도치 갯수
	//모든 고슴도치를 찾아서 큐에넣음
	queue<pair<int, int>> hed;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			if (map[i][j] == 3) {
				hed.push({ i, j });
				cnt++;
			}

	if (cnt == 0) return -1; //고슴도치가 한마리도 안남았으면 실패!

	//채워진 큐를 근거로 BFS진행
	while (!hed.empty()) {
		int x = hed.front().first;
		int y = hed.front().second;
		hed.pop();
		map[x][y] = 0; //맵에서 고슴도치를 삭제

		for (int d = 0; d < 4; d++) {
			int xx = x + dxy[d][0];
			int yy = y + dxy[d][1];
			//돌, 물을 만나면 제외
			if (xx < 0 || yy < 0 || xx == R || yy == C || hed_visit[xx][yy] || map[xx][yy] == 1 || map[xx][yy] == 2) continue;
			hed_visit[xx][yy] = true;
			if (map[xx][yy] == 4) return 1; //고슴도치가 굴로 탈출하면 종료
			map[xx][yy] = 3; //고슴도치 한칸 이동
		}
		
	}

	return 0; //고슴도치는 아직 굴을 발견하지 못함
}

//맵에 있는 모든 물을 사방으로 한칸 이동
void water_move() {
	//방문배열 초기화
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			water_visit[i][j] = false;

	//맵에있는 모든 물을 큐에 넣음
	queue<pair<int, int>> q;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (map[i][j] == 2) {
				q.push({ i, j }); //큐에 넣고
				water_visit[i][j] = true; //방문 체크해줌
			}

	//채워진 큐를 근거로 BFS진행 
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int xx = x + dxy[d][0];
			int yy = y + dxy[d][1];
			//돌과 목적지로는 갈 수 없다.
			if (xx < 0 || yy < 0 || xx == R || yy == C || water_visit[xx][yy] || map[xx][yy] == 1 || map[xx][yy] == 4) continue;
			water_visit[xx][yy] = true;
			map[xx][yy] = 2; //물 한칸 이동
		}
	}

}

void func() {
	while (1) {
		int res = hed_move();
		if (res == 1) { //고슴도치가 비버굴로 탈출한 경우
			printf("%d", time); //총 걸린 시간을 리턴하고 프로그램 종료
			return;
		}
		else if (res == -1) { //고슴도치가 다 뒤진경우
			printf("KAKTUS");
			return;
		}

		water_move(); //물을 한칸 이동

		time++;
	}
}

int main(void) {
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++) {
		char c;
		scanf("%c", &c);//줄바꿈문자 제거
		for (int j = 0; j < C; j++) {
			scanf("%c", &c);
			switch (c) {
			case 'X': map[i][j] = 1;
				break;
			case '*' : map[i][j] = 2;
				break;
			case 'S': map[i][j] = 3;
				hed_visit[i][j] = true; //방문 체크 먼저 해준다. 초깃값
				break;
			case 'D': map[i][j] = 4;
				break;
			default: map[i][j] = 0;
				break;
			}
		}
	}

	func();
	
	return 0;
}