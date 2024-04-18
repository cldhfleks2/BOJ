#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n, m, x, y, k, **map;
int top = 0, right = 0, forward = 0, left = 0, backward = 0, bottom = 0;

void roll(int dir) { //1~4 방향으로 주사위를 굴림
	int temp = top;
	if (dir == 1) { //동쪽으로 주사위를 굴림
		top = left;
		left = bottom;
		bottom = right;
		right = temp;
	}
	else if (dir == 2) {
		top = right;
		right = bottom;
		bottom = left;
		left = temp;
	}
	else if (dir == 3) {
		top = backward;
		backward = bottom;
		bottom = forward;
		forward = temp;
	}
	else if (dir == 4) {
		top = forward;
		forward = bottom;
		bottom = backward;
		backward = temp;
	}
}

int main(void) {
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	map = new int* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	}

	for (int i = 0, dir; i < k; i++) {
		scanf("%d", &dir);
		//명령어의 방향대로 주사위를 굴린다.
		if (dir == 1) {
			if (y + 1 >= m) { //주사위가 지도를 벗어나면 제외
				continue;
			}
			y++;
			roll(1);
		}
		else if (dir == 2) {
			if (y - 1 <= -1) {
				continue;
			}
			y--;
			roll(2);
		}
		else if (dir == 3) {
			if (x - 1 <= -1) {
				continue;
			}
			x--;
			roll(3);
		}
		else if (dir == 4) {
			if (x + 1 >=  n) {
				continue;
			}
			x++;
			roll(4);
		}
		//굴려진주사위와 지도바닥을 비교하여 숫자를 복사
		if (map[x][y] == 0) { //지도에 적힌 숫자가 0이면
			map[x][y] = bottom; //주사위 바닥숫자를 지도에 복사
		}
		else {
			bottom = map[x][y]; //지도에적힌 숫자를 주사위 바닥으로 복사
			map[x][y] = 0; //칸에 쓰인숫자를 0으로 초기화
		}
		printf("%d\n", top); //주사위 상단의 숫자를 출력함

	}
	return 0;
}