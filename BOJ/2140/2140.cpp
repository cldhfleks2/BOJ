#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n, **map;

void vertex_check() { //4방향꼭짓점 check
	if (map[0][0] == 1) map[1][1] = -1;
	if (map[n - 1][0] == 1) map[n - 2][1] = -1;
	if (map[0][n - 1] == 1) map[1][n - 2] = -1;
	if (map[n - 1][n - 1] == 1) map[n - 2][n - 2] = -1;
}

void playGame() {
	for (int i = 1; i <= n - 3; i++) { //상
		int mineCnt = 0;
		if (map[1][i - 1] == -1) mineCnt++;
		if (map[1][i] == -1) mineCnt++;
		if (mineCnt < map[0][i]) map[1][i + 1] = -1; //우하단위치에 지뢰check
	}

	for (int i = 1; i <= n - 3; i++) { //우
		int mineCnt = 0;
		if (map[i - 1][n - 2] == -1) mineCnt++;
		if (map[i][n - 2] == -1) mineCnt++;
		if (mineCnt < map[i][n - 1]) map[i + 1][n - 2] = -1;
	}

	for (int i = 1; i <= n - 3; i++) { //하
		int mineCnt = 0;
		if (map[n - 2][i - 1] == -1) mineCnt++;
		if (map[n - 2][i] == -1) mineCnt++;
		if (mineCnt < map[n - 1][i]) map[n - 2][i + 1] = -1; 
	}

	for (int i = 1; i <= n - 3; i++) { //좌
		int mineCnt = 0;
		if (map[i - 1][1] == -1) mineCnt++;
		if (map[i][1] == -1) mineCnt++;
		if (mineCnt < map[i][0]) map[i + 1][1] = -1;
	}

}

int sum() {
	int res = 0;
	if(n >= 5)
		res = (n - 4) * (n - 4);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == -1)
				res++;
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++)
	//		printf("%2d", map[i][j]);
	//	printf("\n");
	//}
		
	return res;
}

int main(char c) {
	scanf("%d", &n);
	map = new int* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
		scanf("%c", &c);
		for (int j = 0, num; j < n; j++) {
			scanf("%c", &c);
			if (c == '#') {
				map[i][j] = 0;
			}
			else {
				num = c - '0';
				map[i][j] = num;
			}
		}
	}

	if (n == 1 || n == 2) {
		printf("0");
		return 0;
	}

	vertex_check();

	playGame();

	printf("%d", sum());


	return 0;
}