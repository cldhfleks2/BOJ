#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair;
int sudoku[9][9], n;
vector<pair<int, int>> list; //5개의 빈칸 위치
vector<int> lost; //빈칸에들어갈 숫자 5개

bool check();
void input();

bool draw() {
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 5; b++) {
			for (int c = 0; c < 5; c++) {
				for (int d = 0; d < 5; d++) {
					for (int e = 0; e < 5; e++) {
						if (a == b || a == c || a == d || a == e || b == c || 
							b == d || b == e || c == d || c == e || d == e) {
							continue;
						}
						else {
							sudoku[list[0].first][list[0].second] = lost[a];
							sudoku[list[1].first][list[1].second] = lost[b];
							sudoku[list[2].first][list[2].second] = lost[c];
							sudoku[list[3].first][list[3].second] = lost[d];
							sudoku[list[4].first][list[4].second] = lost[e];

							if (check())  //정답을 찾음
								return true;

						}
					}
				}
			}
		}
	}

	return false; //정답을 못찾았음
}

bool check() { //현재스도쿠가 정답인가?
	int dx[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
	int dy[9] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
	bool numbers[10] = { false };
	for (int k = 0; k < 9; k++) {
		int x = dx[k];
		int y = dy[k];
		for (int l = 1; l <= 9; l++) //초기화
			numbers[l] = false;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int xx = x + i; int yy = y + j;
				if (numbers[sudoku[xx][yy]]) //두번체크되면
					return false; //실패!
				else 
					numbers[sudoku[xx][yy]] = true;
			}
		}

	}
	for (int i = 0; i < 9; i++) {
		for (int l = 1; l <= 9; l++) //초기화
			numbers[l] = false;

		for (int j = 0; j < 9; j++) {
			if (numbers[sudoku[i][j]]) //가로 check
				return false; 
			else
				numbers[sudoku[i][j]] = true;
		}

		for (int l = 1; l <= 9; l++) 
			numbers[l] = false;

		for (int j = 0; j < 9; j++) {
			if (numbers[sudoku[j][i]]) //세로 check
				return false; 
			else
				numbers[sudoku[j][i]] = true;
		}
	}
	return true;
}

void input() {
	list.clear();
	lost.clear();
	int cnt[10]; //1~9까지 숫자 빈도수
	for (int i = 1; i <= 9; i++) 
		cnt[i] = 9;
	char c;
	for (int i = 0; i < 9; i++) {
		scanf("%c", &c);
		for (int j = 0, temp; j < 9; j++) {
			scanf("%c", &c);
			temp = c - '0';
			sudoku[i][j] = temp;
			if (temp == 0) //빈칸기록
				list.push_back({i, j});
			cnt[temp]--;
		}
	}
	for(int i = 1 ; i<=9 ; i++) //5군데 들어갈 숫자들
		while (cnt[i]--) 
			lost.push_back(i);
}

int main(void) {
	scanf("%d", &n);
	while (n--) {
		input();
		
		if (draw()) { //정답을 찾은경우
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++)
					printf("%d", sudoku[i][j]);
				printf("\n");
			}
			printf("\n");
		}
		else { //정답이없는경우
			printf("Could not complete this grid.\n");
		}

	}

	return 0;
}