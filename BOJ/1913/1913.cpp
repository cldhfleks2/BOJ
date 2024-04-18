#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {

	int n, m;
	scanf("%d\n%d", &n, &m);

	int** map = new int* [n]; //메모리설정
	for (int i = 0; i < n; i++)
		map[i] = new int[n];

	for (int i = 0; i < n; i++) //초기화
		for (int j = 0; j < n; j++)
			map[i][j] = 0;
	

	//0 : ↓
	//1 : →
	//2 : ↑
	//3 : ←
	int flag = 0; //방향을 기억
	int r = 0, c = 0; //행, 열 위치
	//지나온길을 못지나가게 하는 4방향 변수
	int down = n, right = n, up = -1, left = 0; 
	//찾고자하는 값의 위치
	int locX, locY;
	
	for (int i = n*n; i >= 1; i--) { //역으로 기록
		map[r][c] = i; //현재위치 기록

		if (i == m) {
			locX = r;
			locY = c;
		}

		if (flag == 0) {
			r++;

			if (r == down) {
				r--;
				c++;
				flag++;
				down--;
			}
		}
		else if (flag == 1) {
			c++;

			if (c == right) {
				c--;
				r--;
				flag++;
				right--;
			}
		}
		else if (flag == 2) {
			r--;

			if (r == up) {
				r++;
				c--;
				flag++;
				up++;
			}
		}
		else if (flag == 3) {
			c--;

			if (c == left) {
				c++;
				r++;
				flag = 0;
				left++;
			}
		}

	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", locX+1, locY+1);

	return 0;
}