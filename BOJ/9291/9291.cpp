#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int sudoku[9][9] = {0, };
int c = 1;

void input();
void checker();

void input() {
	int t;
	scanf("%d", &t);
	while (t--) {
		//입력받음
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				scanf("%d", &sudoku[i][j]);
			}
		}
		checker();
		
		//초기화 
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				sudoku[i][j] = 0;
			}
		}

		c++;
	}

}

void checker() {
	bool number[10] = {false}; //모두 false로 체크

	for (int i = 0; i < 9; i++) { //가로 체크
		for (int j = 0; j < 9; j++) {
			int num = sudoku[i][j];
			if (number[num]) { //중복된 숫자가 나타난경우
				printf("Case %d: INCORRECT\n", c);
				return;
			}
			else {
				number[num] = true;
			}
		}
		//초기화
		for (int i = 1; i < 10; i++)
			number[i] = false;
	}

	for (int i = 0; i < 9; i++) { //세로 체크
		for (int j = 0; j < 9; j++) {
			int num = sudoku[j][i];
			if (number[num]) { //중복된 숫자가 나타난경우
				printf("Case %d: INCORRECT\n", c);
				return;
			}
			else {
				number[num] = true;
			}
		}
		//초기화
		for (int i = 1; i < 10; i++)
			number[i] = false;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 3 * i; k < 3 * i + 3; k++) {
				for (int l = 3 * j; l < 3 * j + 3; l++) {
					int num = sudoku[k][l];
					if (number[num]) { //중복된 숫자가 나타난경우
						printf("Case %d: INCORRECT\n", c); //오답출력
						return;
					}
					else {
						number[num] = true;
					}
				}
			}
			//초기화
			for (int m = 1; m < 10; m++)
				number[m] = false;
		}
	}
	//여기까지오면 정답출력
	printf("Case %d: CORRECT\n", c);
}

int main(void) {
	input();

	return 0;
}