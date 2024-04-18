#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
//n, c, e : 입력값
//cnt: 공과대학생수를셀것
//map: 학생들의 배치도
int n, c, e, cnt, ** map; 
int dx[4] = { 0, 1, 0, -1 }; //우 하 좌 상 순서
int dy[4] = { 1, 0, -1, 0 };

int main(void) {
	scanf("%d%d%d", &n, &c, &e);
	cnt = e; 
	if (c > n * n) { //컴퓨터공학과 학생수가 맵보다크면
		printf("-1");
		return 0;
	}
	map = new int* [n];
	//맵 생성, 초기화
	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
		for (int j = 0; j < n; j++)
			map[i][j] = 0; //빈공간 즉 바리게이트
	}

	//컴퓨터과학과 학생(A)을 배치
	int x = 0, y = 0, gap1 = 1, gap2 = 1, cnt_a = 0;
	for (int k = 1; k <= n; k++) cnt_a += k;
	while (c--) {
		map[x][y] = 1; //현재위치에 A그룹을 설치
		cnt_a--;
		if (cnt_a > 0) {
			x -= 1; y += 1; //우상단방향으로 설치
			if (x < 0) {
				x = gap1; y = 0;
				gap1++;
			}
		}
		else if (cnt_a == 0) {
			x = 1; y = n - 1;
		}
		else {
			x += 1; y -= 1; //좌상단으로설치
			if (y < gap2) {
				gap2++;
				x = gap2;  y = n - 1;
			}
		}
		
	}

	int res = 0;

	//공과대학생(B )을 배치
	for (int i = 0; i < n; i++) {
		if (cnt == 0) break;
		for (int j = 0; j < n; j++) { //현재위치 i,j 탐색
			if (cnt == 0) break;
			if (map[i][j] == 1) continue; //이미 컴퓨터과학과공간이면 제외
			bool isBlank = true; //빈공간인가? => 공과대학생공간 설치가 가능한가?
			for (int k = 0; k < 4; k++) { //현재위치 i,j에서 상하좌우를 탐색
				int xx = i + dx[k];
				int yy = j + dy[k];
				if (xx < 0 || y < 0 || n == xx || n == yy) continue; //맵크기를 벗어나면 제외
				if (map[xx][yy] == 1) { //i,j 기준 상하좌우에 컴퓨터과학과공간이 설치되있으면
					isBlank = false; //빈공간이 아님
					break; //상하좌우 탐색종료
				}
			}
			if (isBlank) {
				map[i][j] = 2; //현재위치를 공과대학생공간으로 기록
				res++;
				cnt--; //공과대학생수 카운트
			}
		}
	}

	if (res < e)
		printf("-1");
	else {
		printf("1\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d", map[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}