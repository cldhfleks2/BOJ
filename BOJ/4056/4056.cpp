#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair;
int sudoku[9][9], n;
vector<pair<int, int>> list; //5���� ��ĭ ��ġ
vector<int> lost; //��ĭ���� ���� 5��

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

							if (check())  //������ ã��
								return true;

						}
					}
				}
			}
		}
	}

	return false; //������ ��ã����
}

bool check() { //���罺���� �����ΰ�?
	int dx[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
	int dy[9] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
	bool numbers[10] = { false };
	for (int k = 0; k < 9; k++) {
		int x = dx[k];
		int y = dy[k];
		for (int l = 1; l <= 9; l++) //�ʱ�ȭ
			numbers[l] = false;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int xx = x + i; int yy = y + j;
				if (numbers[sudoku[xx][yy]]) //�ι�üũ�Ǹ�
					return false; //����!
				else 
					numbers[sudoku[xx][yy]] = true;
			}
		}

	}
	for (int i = 0; i < 9; i++) {
		for (int l = 1; l <= 9; l++) //�ʱ�ȭ
			numbers[l] = false;

		for (int j = 0; j < 9; j++) {
			if (numbers[sudoku[i][j]]) //���� check
				return false; 
			else
				numbers[sudoku[i][j]] = true;
		}

		for (int l = 1; l <= 9; l++) 
			numbers[l] = false;

		for (int j = 0; j < 9; j++) {
			if (numbers[sudoku[j][i]]) //���� check
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
	int cnt[10]; //1~9���� ���� �󵵼�
	for (int i = 1; i <= 9; i++) 
		cnt[i] = 9;
	char c;
	for (int i = 0; i < 9; i++) {
		scanf("%c", &c);
		for (int j = 0, temp; j < 9; j++) {
			scanf("%c", &c);
			temp = c - '0';
			sudoku[i][j] = temp;
			if (temp == 0) //��ĭ���
				list.push_back({i, j});
			cnt[temp]--;
		}
	}
	for(int i = 1 ; i<=9 ; i++) //5���� �� ���ڵ�
		while (cnt[i]--) 
			lost.push_back(i);
}

int main(void) {
	scanf("%d", &n);
	while (n--) {
		input();
		
		if (draw()) { //������ ã�����
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++)
					printf("%d", sudoku[i][j]);
				printf("\n");
			}
			printf("\n");
		}
		else { //�����̾��°��
			printf("Could not complete this grid.\n");
		}

	}

	return 0;
}