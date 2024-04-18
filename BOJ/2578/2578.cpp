#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int bingo[5][5];
int moderator[25];

void input();
void play();
bool checker();

void input() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &bingo[i][j]); //전부기록
		}
	}
	for (int i = 0; i < 25; i++) {
		scanf("%d", &moderator[i]);
	}

	play();
}

//게임하는 부분
void play() {
	for (int i = 0; i < 25; i++) {
		int num = moderator[i]; //순서대로 숫자를 호명한다.

		for (int j = 0; j < 5; j++) { //빙고판의 숫자를 찾아 적는다
			for (int k = 0; k < 5; k++) {
				if (bingo[j][k] == num) {
					bingo[j][k] = -1;
					break;
				}
			}
		}
		if (checker()) {
			printf("%d", i + 1);
			return;
		}
	}
}

//몇빙고인지 확인하는 부분
bool checker() {
	int res = 0;
	bool line = false;
	//가로줄 확인
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingo[i][j] != -1) {
				line = false;
				break; //다음 가로줄확인
			}
			else {
				line = true; 
			}
		}
		if (line) //완성된 줄갯수 기록
			res++; 
	}
	
	line = false; //초기화
	//세로줄 확인
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingo[j][i] != -1) {
				line = false;
				break; //다음 세로줄확인
			}
			else {
				line = true;
			}
		}
		if (line) //완성된 줄갯수 기록
			res++;
	}

	int cnt = 0;
	//좌상우하대각선 ( \ )
	for (int i = 0; i < 5; i++) {
		if (bingo[i][i] == -1)
			cnt++;
	}
	if (cnt == 5) //확인
		res++;

	cnt = 0; //초기화
	//좌하우상대각선 ( / )
	for (int i = 0; i < 5; i++) {
		if (bingo[i][4 - i] == -1)
			cnt++;
	}
	if (cnt == 5) //확인
		res++;

	//printf("%d\n", res);
	return res >= 3; //3개의 선이 완성되면 빙고
}

int main(void) {
	input();

	return 0;
}