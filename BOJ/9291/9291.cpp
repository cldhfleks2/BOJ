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
		//�Է¹���
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				scanf("%d", &sudoku[i][j]);
			}
		}
		checker();
		
		//�ʱ�ȭ 
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				sudoku[i][j] = 0;
			}
		}

		c++;
	}

}

void checker() {
	bool number[10] = {false}; //��� false�� üũ

	for (int i = 0; i < 9; i++) { //���� üũ
		for (int j = 0; j < 9; j++) {
			int num = sudoku[i][j];
			if (number[num]) { //�ߺ��� ���ڰ� ��Ÿ�����
				printf("Case %d: INCORRECT\n", c);
				return;
			}
			else {
				number[num] = true;
			}
		}
		//�ʱ�ȭ
		for (int i = 1; i < 10; i++)
			number[i] = false;
	}

	for (int i = 0; i < 9; i++) { //���� üũ
		for (int j = 0; j < 9; j++) {
			int num = sudoku[j][i];
			if (number[num]) { //�ߺ��� ���ڰ� ��Ÿ�����
				printf("Case %d: INCORRECT\n", c);
				return;
			}
			else {
				number[num] = true;
			}
		}
		//�ʱ�ȭ
		for (int i = 1; i < 10; i++)
			number[i] = false;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 3 * i; k < 3 * i + 3; k++) {
				for (int l = 3 * j; l < 3 * j + 3; l++) {
					int num = sudoku[k][l];
					if (number[num]) { //�ߺ��� ���ڰ� ��Ÿ�����
						printf("Case %d: INCORRECT\n", c); //�������
						return;
					}
					else {
						number[num] = true;
					}
				}
			}
			//�ʱ�ȭ
			for (int m = 1; m < 10; m++)
				number[m] = false;
		}
	}
	//����������� �������
	printf("Case %d: CORRECT\n", c);
}

int main(void) {
	input();

	return 0;
}