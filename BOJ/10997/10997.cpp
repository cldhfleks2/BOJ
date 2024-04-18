#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d", &n);
	if (n == 1) {
		printf("*");
		return 0;
	}
	int x_size = 4 * n - 3 + 2, y_size = 4 * n - 3;
	char** map = new char*[x_size];
	for (int i = 0; i < x_size; i++) {
		map[i] = new char[y_size];
		for (int j = 0; j < y_size; j++)
			map[i][j] = ' '; //공백문자로 초기화
	}
	//0 : ←
	//1 : ↓
	//2 : →
	//3 : ↑
	int flag = 0;
	int cnt = 4 * n - 2; //총반복횟수
	int left = -1, down = x_size, right = y_size, up = 1 ;
	int x = 0, y = y_size - 1; //시작위치
	map[x][y] = '*'; //기본
	while (1) {
		if (flag == 0) {
			y--;
			if (y == left) {
				y++; //원위치
				x++; //다음방향으로 한번이동
				left += 2;
				flag++;
				cnt--;
			}
		}
		else if (flag == 1) {
			x++;
			if (x == down) {
				x--;
				y++;
				down -= 2;
				flag++;
				cnt--;
			}
		}
		else if (flag == 2) {
			y++;
			if (y == right) {
				y--;
				x--;
				right -= 2;
				flag++;
				cnt--;
			}
		}
		else if (flag == 3) {
			x--;
			if (x == up) {
				x++;
				y--;
				up += 2;
				flag = 0;
				cnt--;
			}
		}
		if (cnt == 0) {
			break;
		}
		map[x][y] = '*'; //현재위치에 별찍기
	}

	for (int i = 0; i < x_size; i++) {
		if (i == 1) {
			printf("*\n");
			continue;
		}
		for (int j = 0; j < y_size; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}

	return 0;
}