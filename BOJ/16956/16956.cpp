#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair;
int r, c, ** farm;
vector<pair<int, int>> sheep, wolf;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

bool place_fence() {
	for (int i = 0; i < sheep.size(); i++) {
		int x = sheep[i].first;
		int y = sheep[i].second;

		for (int j = 0; j < 4; j++) { //양주변 4방향에 울타리설치
			int xx = x + dx[j];
			int yy = y + dy[j];

			if (0 <= xx && xx <= r - 1 && 0 <= yy && yy <= c - 1) {
				if (farm[xx][yy] == 2) { //늑대랑 붙어있을시 실패
					//printf(">> %d %d => %d %d\n", x, y, xx, yy);
					return false;
				}
				if (farm[xx][yy] == 0) farm[xx][yy] = 3; //비어있으면 울타리설치
			}
		}

	}
	return true;
}

int main(char temp) {
	scanf("%d%d", &r, &c);
	farm = new int* [r];
	for (int i = 0; i < r; i++) {
		farm[i] = new int[c];
		scanf("%c", &temp);
		for (int j = 0; j < c; j++) {
			scanf("%c", &temp);
			if (temp == 'S') { //양
				farm[i][j] = 1;
				sheep.push_back({ i, j });
			}
			else if (temp == 'W') { //늑대
				farm[i][j] = 2;
				wolf.push_back({ i, j });
			}
			else {
				farm[i][j] = 0;
			}
		}
	}

	if (place_fence()) {
		printf("1\n");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				if (farm[i][j] == 0)
					printf(".");
				else if (farm[i][j] == 1)
					printf("S");
				else if (farm[i][j] == 2)
					printf("W");
				else if (farm[i][j] == 3)
					printf("D");
			printf("\n");
		}
	}
	else {
		printf("0\n");
	}

	return 0;
}