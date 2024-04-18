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
			scanf("%d", &bingo[i][j]); //���α��
		}
	}
	for (int i = 0; i < 25; i++) {
		scanf("%d", &moderator[i]);
	}

	play();
}

//�����ϴ� �κ�
void play() {
	for (int i = 0; i < 25; i++) {
		int num = moderator[i]; //������� ���ڸ� ȣ���Ѵ�.

		for (int j = 0; j < 5; j++) { //�������� ���ڸ� ã�� ���´�
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

//��������� Ȯ���ϴ� �κ�
bool checker() {
	int res = 0;
	bool line = false;
	//������ Ȯ��
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingo[i][j] != -1) {
				line = false;
				break; //���� ������Ȯ��
			}
			else {
				line = true; 
			}
		}
		if (line) //�ϼ��� �ٰ��� ���
			res++; 
	}
	
	line = false; //�ʱ�ȭ
	//������ Ȯ��
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingo[j][i] != -1) {
				line = false;
				break; //���� ������Ȯ��
			}
			else {
				line = true;
			}
		}
		if (line) //�ϼ��� �ٰ��� ���
			res++;
	}

	int cnt = 0;
	//�»���ϴ밢�� ( \ )
	for (int i = 0; i < 5; i++) {
		if (bingo[i][i] == -1)
			cnt++;
	}
	if (cnt == 5) //Ȯ��
		res++;

	cnt = 0; //�ʱ�ȭ
	//���Ͽ��밢�� ( / )
	for (int i = 0; i < 5; i++) {
		if (bingo[i][4 - i] == -1)
			cnt++;
	}
	if (cnt == 5) //Ȯ��
		res++;

	//printf("%d\n", res);
	return res >= 3; //3���� ���� �ϼ��Ǹ� ����
}

int main(void) {
	input();

	return 0;
}