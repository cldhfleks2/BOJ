#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int a, b, n, m, **map, **robots; 
int dx[5] = {0, 1, 0, -1, 0}; //E:1  S:2  W:3  N:4 (시계방향)
int dy[5] = {0, 0, 1, 0, -1};

void playGame() {
	int r, cnt; //로봇번호r 반복횟수cnt
	char order; //명령어
	bool END_GAME = false;
	while (m--) {
		scanf("%d%c%c%d", &r, &order, &order, &cnt);
		int y, x, dir; //x, y좌표, 현재방향dir
		for(int i = 0 ; i < b; i++)
			for(int j = 0 ; j < a ; j++)
				if (robots[i][j] == r) { //로봇위치를 찾음
					y = i; x = j; dir = map[i][j];
				}
		if (END_GAME)
			continue;

		if (order == 'L') { //반시계방향 턴
			while (cnt--) {
				dir--;
				if (dir == 0)
					dir = 4;
			}
			map[y][x] = dir; //재설정
		}
		else if (order == 'R') { //시계방향 턴
			while (cnt--) {
				dir++;
				if (dir == 5)
					dir = 1;
			}
			map[y][x] = dir;
		}
		else if (order == 'F') { //전진
			int yy = y, xx = x; //다음위치
			while (cnt--) {
				//로봇위치 변경1
				robots[yy][xx] = 0;
				map[yy][xx] = 0;
				yy += dy[dir]; xx += dx[dir];  //다음위치 계산
				//벽에부딪히는경우
				if (yy <= -1 || b <= yy || xx <= -1 || a <= xx) {
					printf("Robot %d crashes into the wall", r);
					END_GAME = true;
					break;
				}
				//로봇에 충돌하는경우
				if (!END_GAME && robots[yy][xx] != 0) {
					printf("Robot %d crashes into robot %d", r, robots[yy][xx]);
					END_GAME = true;
					break;
				}
				//로봇위치 변경2
				robots[yy][xx] = r;
				map[yy][xx] = dir;

			}
		}

	}

	if (!END_GAME) printf("OK");
}

int main(char c) {
	scanf("%d%d%d%d", &a, &b, &n, &m);
	map = new int* [b];
	robots = new int* [b];
	for (int i = 0; i < b; i++) {
		map[i] = new int[a];
		robots[i] = new int[a];
		for (int j = 0; j < a; j++) {
			map[i][j] = 0; //초기화
			robots[i][j] = 0;
		}
	}

	for (int i = 0, x, y; i < n; i++) {
		scanf("%d%d%c%c", &x, &y, &c, &c); //%c%c:공백읽고 방향을읽음
		if (c == 'E') {
			map[b - y][x - 1] = 1; //입력좌표계 고려
		}
		else if (c == 'S') {
			map[b - y][x - 1] = 2;
		}
		else if (c == 'W') {
			map[b - y][x - 1] = 3;
		}
		else if (c == 'N') {
			map[b - y][x - 1] = 4;
		}
		robots[b - y][x - 1] = i + 1; //로봇번호기록
	}

	playGame();

	return 0;
}